-- Special trick to load the parent path of the current script.
local parent_path = string.match(arg[0], "(.-)([^\\/]-%.?([^%.\\/]*))$")
-- Add that path to the list of places where lua will load packages
package.path = package.path .. ";" .. parent_path .. "?.lua"
-- Load the driver package which will take care of the command line arguments and other settings
-- as here we just focus on the code necessary to build our supported platforms
require "np-build-driver-stride"

local debug_flags = "-O0 -g"
local debug_ms_flags = "-Od"
local release_flags = "-O3"
local release_ms_flags = "-O2"

-- NOTE: This is a cleaned up version of np-build.lua specific to the needs of Stride, and uses Zig CC cross compiler instead of clang, etc.
-- We can port over other commands from np-build.lua as needed.

-- we require Zig v0.12.0 reachable from your path. this only works on Windows for now
local zig = "zig.exe"	

-- For testing alternative versions of Zig, etc
-- local zig = "c:\\devtools\\zig-0.11.0\\zig.exe"

function BuildZig(cfile, target, platform_args)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end

	local cmd = zig.." cc "..platform_args.." -target "..target.." "..zig_common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end

	os.execute(cmd)
	table.insert(objs, cfile..".o")
end

function LinkZigStatic(target, folder, ext)
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
    local cmd = zig.." build-lib -static -target "..target.." -femit-bin="..folder.."\\"..outputName.."."..ext.." "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

-- TODO: Unused for now
-- function LinkZigShared(target, folder, ext)
-- 	local objs_str = ""
-- 	for i, o in ipairs(objs) do
-- 		objs_str = objs_str..o.." "
-- 	end

-- 	local cmd = zig.." build-lib -shared -target "..target.." -femit-bin="..folder.."\\"..outputName.."."..ext.." "..objs_str
-- 	if is_verbose == true then
-- 		print(cmd)
-- 	end
-- 	os.execute(cmd)
-- end

if platform == "windows" then 
	lfs.mkdir("libs")
	lfs.chdir("libs")
	lfs.mkdir("win-x86")
	lfs.mkdir("win-x64")
	lfs.mkdir("win-arm64")
	lfs.chdir("..")

	objs = {}
    print ("Building Windows x86...")
	for i,f in ipairs(cfiles) do
		BuildZig(f, "x86-windows-gnu", "-DNP_WIN32 -m32 -gcodeview -fno-ms-extensions")
	end
	LinkZigStatic("x86-windows-gnu", "libs\\win-x86", "lib")

	objs = {}
    print ("Building Windows x64...")
	for i,f in ipairs(cfiles) do
		BuildZig(f, "x86_64-windows-gnu", "-DNP_WIN32 -m64 -gcodeview -fno-ms-extensions")
	end
	LinkZigStatic("x86_64-windows-gnu", "libs\\win-x64", "lib")

	objs = {}
    print ("Building Windows arm64...")
	for i,f in ipairs(cfiles) do
		BuildZig(f, "aarch64-windows-gnu", "-DNP_WIN32 -m64 -gcodeview -fno-ms-extensions")
	end
	LinkZigStatic("aarch64-windows-gnu", "libs\\win-arm64", "lib")

elseif platform == "ios" then
	-- TODO: port over to Zig

elseif platform == "macos" then	
	lfs.mkdir("libs")
	lfs.chdir("libs")
	lfs.mkdir("osx-x64")
	lfs.mkdir("osx-arm64")
	lfs.chdir("..")
	
	objs = {}
    print ("Building macOS x64...")
	for i,f in ipairs(cfiles) do
		BuildZig(f, "x86_64-macos", "-DNP_MACOS -mmacosx-version-min=10.5")
	end
	LinkZigStatic("x86_64-macos", "libs\\osx-x64", "a")
	
	objs = {}
    print ("Building macOS arm64...")
	for i,f in ipairs(cfiles) do
		BuildZig(f, "aarch64-macos", "-DNP_MACOS -mmacosx-version-min=10.5")
	end
	LinkZigStatic("aarch64-macos", "libs\\osx-arm64", "a")
	
	-- lfs.mkdir("macOS")
	
	if is_verbose == true then
		print(cmd)
	end
	-- Not sure we need lipo anymore 
	-- os.execute("lipo macOS\\"..outputName.."_i386.a macOS\\"..outputName.."_x86_64.a -create -output macOS\\"..outputName..".a")
	-- os.remove("macOS\\"..outputName.."_i386.a")
	-- os.remove("macOS\\"..outputName.."_x86_64.a")

elseif platform == "linux" then
	lfs.mkdir("libs")
	lfs.chdir("libs")
	lfs.mkdir("linux-x64")
	lfs.mkdir("linux-arm64")
	lfs.chdir("..")
	
	objs = {}
    print ("Building Linux x64...")
	for i,f in ipairs(cfiles) do
		BuildZig(f, "x86_64-linux-gnu", "-DNP_LINUX -fPIC")
	end
	LinkZigStatic("x86_64-linux-gnu", "libs\\linux-x64", "a")
	
	objs = {}
    print ("Building Linux arm64...")
	for i,f in ipairs(cfiles) do
		BuildZig(f, "aarch64-linux-gnu", "-DNP_LINUX -fPIC")
	end
	LinkZigStatic("aarch64-linux-gnu", "libs\\linux-arm64", "a")

elseif platform == "android" then
	-- TODO: port over to Zig

end
