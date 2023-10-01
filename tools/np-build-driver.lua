ffi = require 'ffi'

local SLASH = "/"
if ffi.os == "Windows" then SLASH = "\\" end

-- Code by David Kastrup
require "lfs"

function dirtree(dir)
  assert(dir and dir ~= "", "directory parameter is missing or empty")
  if string.sub(dir, -1) == SLASH then
    dir=string.sub(dir, 1, -2)
  end

  local function yieldtree(dir)
    for entry in lfs.dir(dir) do
      if entry ~= "." and entry ~= ".." then
        entry=dir..SLASH..entry
        local attr=lfs.attributes(entry)
        coroutine.yield(entry,attr)
        if attr.mode == "directory" then
          yieldtree(entry)
        end
      end
    end
  end

  return coroutine.wrap(function() yieldtree(dir) end)
end

function string.ends(String,End)
   return End=='' or string.sub(String,-string.len(End))==End
end

function string.starts(String,Start)
   return string.sub(String,1,string.len(Start))==Start
end

local exclude_dirs = {}
local exclude_files = {}
local directory = ""

common_flags = "-ffast-math -fno-threadsafe-statics -nostdlibinc -nobuiltininc -nostdinc++ -Wno-macro-redefined -I.."..SLASH.."NativePath -I.."..SLASH.."NativePath"..SLASH.."standard"
zig_common_flags = "-Wno-ignored-attributes -Wno-delete-non-virtual-dtor -Wno-macro-redefined -fno-rtti -fno-exceptions"

objs = {}
cfiles = {}
cppfiles = {}
hfiles = {}
debug = false
is_verbose = false
platform = "windows"
outputName = "lib"

function table.contains(table, element)
  for _, value in pairs(table) do
    if string.starts(element, value) then
      return true
    end
  end
  return false
end

-- Process the zig command line options 
for i,v in ipairs(arg) do 
  if v == "debug" then
      debug = true
  elseif string.starts(v, "-I") then
      -- add an include directory to the compiler flags
      local includeDir = string.sub(v, 3)
      common_flags = common_flags.." -I"..includeDir
      zig_common_flags = zig_common_flags.." -I"..includeDir
  elseif string.starts(v, "-D") then
      -- add a define to the compiler flags
      local includeDir = string.sub(v, 3)
      common_flags = common_flags.." -D"..includeDir
      zig_common_flags = zig_common_flags.." -D"..includeDir
  elseif string.starts(v, "-n") then
      local n = string.sub(v, 3)
      outputName = n
  elseif string.starts(v, "-E") then
      local n = string.sub(v, 3)
      table.insert(exclude_dirs, n)
  elseif string.starts(v, "-e") then
      local n = string.sub(v, 3)
      table.insert(exclude_files, n)
  elseif v == "--verbose" or v == "-v" then
      is_verbose = true
  elseif v == "--shared" then
      is_shared = true
  elseif string.starts(v, "-p") then
      platform = string.sub(v, 3)
  else
      directory = v
  end
end

-- Build a list of all source files to compile excluding those that we do not want via -E or -e see above.
for filename, attr in dirtree(directory) do
    if table.contains(exclude_dirs, filename) ~= true and table.contains(exclude_files, filename) ~= true then
        if string.ends(filename, ".c") and attr.mode == "file" and table.contains(exclude_files, filename) ~= true then
            table.insert(cfiles, filename)
            if is_verbose == true then
                print("Keeping:   "..filename)
            end
        elseif string.ends(filename, ".cpp") and attr.mode == "file" and table.contains(exclude_files, filename) ~= true then
			table.insert(cppfiles, filename)
            if is_verbose == true then
                print("Keeping:   "..filename)
            end
		end
    elseif is_verbose == true then
        print("Excluding: "..filename)
    end
end
