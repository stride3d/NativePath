-- Special trick to load the parent path of the current script.
local parent_path = string.match(arg[0], "(.-)([^\\/]-%.?([^%.\\/]*))$")
-- Add that path to the list of places where lua will load packages
package.path = package.path .. ";" .. parent_path .. "?.lua"
-- Load the driver package which will take care of the command line arguments and other settings
-- as here we just focus on the code necessary to build our supported platforms
require "np-build-driver"

local debug_flags = "-O0 -g"
local debug_ms_flags = "-Od"
local release_flags = "-O3"
local release_ms_flags = "-O2"

--Win dll for checking

function BuildWindows32DLL(cfile, isCpp)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	if isCpp then flags = flags.." -std=c++1z " end
	local cmd = "clang -v -m32 -DNP_WIN32 -Wall -gcodeview -fno-ms-extensions  -target i686-pc-windows-msvc "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkWindows32DLL()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "clang -v -m32 -shared -o Windows\\x86\\"..outputName..".dll -Wl,\"-libpath:C:\\Program Files (x86)\\Windows Kits\\10\\Lib\\10.0.22621.0\\ucrt\\x86\",\"-libpath:C:\\Program Files (x86)\\Windows Kits\\10\\Lib\\10.0.22621.0\\um\\x86\",-nodefaultlib:libcmt,-dll,-libpath:..\\Libs\\Windows\\x86\\ -llibNativePath "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

--LLVM bytecode

function BuildLLVM32(cfile, isCpp)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	if isCpp then flags = flags.." -std=c++1z -fno-rtti -fno-exceptions" end
	local cmd = "clang -DNP_LLVM_BC "..common_flags.." "..flags.." -o "..cfile..".bc ".." -c -emit-llvm -target i386-unknown-none "..cfile
	local cmdLL = "clang -DNP_LLVM_BC "..common_flags.." "..flags.." -o "..cfile..".ll ".." -S -c -emit-llvm -target i386-unknown-none "..cfile
	local cmdPP = "clang -DNP_LLVM_BC "..common_flags.." "..flags.." -E "..cfile.." > "..cfile..".pp"
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".bc") end
	os.execute(cmdLL)
	os.execute(cmdPP)
end

function LinkLLVM32()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-link -o LLVM\\"..outputName.."-i386.bc "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildLLVMarmv7(cfile, isCpp)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	if isCpp then flags = flags.." -std=c++1z -fno-rtti -fno-exceptions" end
	local cmd = "clang -DNP_LLVM_BC -mfpu=neon -mfloat-abi=hard "..common_flags.." "..flags.." -o "..cfile..".bc ".." -c -emit-llvm -target armv7-unknown-none "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".bc") end
end

function LinkLLVMarmv7()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-link -o LLVM\\"..outputName.."-armv7.bc "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildLLVMarmv7s(cfile, isCpp)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	if isCpp then flags = flags.." -std=c++1z -fno-rtti -fno-exceptions" end
	local cmd = "clang -DNP_LLVM_BC -mfpu=neon -mfloat-abi=hard "..common_flags.." "..flags.." -o "..cfile..".bc ".." -c -emit-llvm -target armv7s-unknown-none "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".bc") end
end

function LinkLLVMarmv7s()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-link -o LLVM\\"..outputName.."-armv7s.bc "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildLLVMAArch64(cfile, isCpp)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	if isCpp then flags = flags.." -std=c++1z -fno-rtti -fno-exceptions" end
	local cmd = "clang -DNP_LLVM_BC "..common_flags.." "..flags.." -o "..cfile..".bc ".." -c -emit-llvm -target aarch64-unknown-none "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".bc") end
end

function LinkLLVMAArch64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-link -o LLVM\\"..outputName.."-aarch64.bc "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildLLVMarmv6(cfile, isCpp)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	if isCpp then flags = flags.." -std=c++1z -fno-rtti -fno-exceptions" end
	local cmd = "clang -DNP_LLVM_BC -mfloat-abi=hard -mfpu=vfp "..common_flags.." "..flags.." -o "..cfile..".bc ".." -c -emit-llvm -target armv6-unknown-none "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".bc") end
end

function LinkLLVMarmv6()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-link -o LLVM\\"..outputName.."-armv6.bc "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildLLVM64(cfile, isCpp)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	if isCpp then flags = flags.." -std=c++1z -fno-rtti -fno-exceptions" end
	local cmd = "clang -DNP_LLVM_BC "..common_flags.." "..flags.." -o "..cfile..".bc ".." -c -emit-llvm -target x86_64-unknown-none "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".bc") end
end

function LinkLLVM64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-link -o LLVM\\"..outputName.."-x86_64.bc "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

--apple llvm

function BuildLLVMarmv7Appl(cfile, isCpp)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	if isCpp then flags = flags.." -std=c++1z -fno-rtti -fno-exceptions" end
	local cmd = "clang -DNP_LLVM_BC -mfpu=neon -mfloat-abi=hard "..common_flags.." "..flags.." -o "..cfile..".bc ".." -c -emit-llvm -target armv7-apple-macho "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".bc") end
end

function LinkLLVMarmv7Appl()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-link -o LLVM\\"..outputName.."-armv7-apple.bc "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildLLVMarmv7sAppl(cfile, isCpp)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	if isCpp then flags = flags.." -std=c++1z -fno-rtti -fno-exceptions" end
	local cmd = "clang -DNP_LLVM_BC -mfpu=neon -mfloat-abi=hard "..common_flags.." "..flags.." -o "..cfile..".bc ".." -c -emit-llvm -target armv7s-apple-macho "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".bc") end
end

function LinkLLVMarmv7sAppl()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-link -o LLVM\\"..outputName.."-armv7s-apple.bc "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildLLVMAArch64Appl(cfile, isCpp)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	if isCpp then flags = flags.." -std=c++1z -fno-rtti -fno-exceptions" end
	local cmd = "clang -DNP_LLVM_BC "..common_flags.." "..flags.." -o "..cfile..".bc ".." -c -emit-llvm -target arm64-apple-macho "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".bc") end
end

function LinkLLVMAArch64Appl()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-link -o LLVM\\"..outputName.."-aarch64-apple.bc "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildLLVM32Appl(cfile, isCpp)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	if isCpp then flags = flags.." -std=c++1z -fno-rtti -fno-exceptions" end
	local cmd = "clang -DNP_LLVM_BC "..common_flags.." "..flags.." -o "..cfile..".bc ".." -c -emit-llvm -target i386-apple-darwin "..cfile
	local cmdLL = "clang -DNP_LLVM_BC "..common_flags.." "..flags.." -o "..cfile.."-apple.ll ".." -S -c -emit-llvm -target i386-apple-darwin "..cfile
	local cmdPP = "clang -DNP_LLVM_BC "..common_flags.." "..flags.." -E "..cfile.." > "..cfile..".pp"
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".bc") end
	os.execute(cmdLL)
	os.execute(cmdPP)
end

function LinkLLVM32Appl()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-link -o LLVM\\"..outputName.."-i386-apple.bc "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildLLVM64Appl(cfile, isCpp)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	if isCpp then flags = flags.." -std=c++1z -fno-rtti -fno-exceptions" end
	local cmd = "clang -DNP_LLVM_BC "..common_flags.." "..flags.." -o "..cfile..".bc ".." -c -emit-llvm -target x86_64-apple-macho "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".bc") end
end

function LinkLLVM64Appl()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-link -o LLVM\\"..outputName.."-x86_64-apple.bc "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

--Win

function BuildWindows32(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -m32 -DNP_WIN32 -gcodeview -fno-ms-extensions -target i686-pc-windows-msvc "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkWindows32()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvarsall\" x86 && lib /NOLOGO /OUT:Windows\\x86\\"..outputName..".lib "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildWindows64(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -m64 -DNP_WIN32 -gcodeview -fno-ms-extensions -target i686-pc-windows-msvc "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkWindows64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvarsall\" x64 && lib /NOLOGO /OUT:Windows\\x64\\"..outputName..".lib "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildWindowsARM64(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -m64 -DNP_WIN32 -gcodeview -fno-ms-extensions -target aarch64-pc-windows-msvc "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkWindowsARM64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvarsall\" arm64 && lib /NOLOGO /OUT:Windows\\arm64\\"..outputName..".lib "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

--Win UWP

function BuildWindowsUWP32(cfile)
	local flags = ""
	if debug then flags = debug_ms_flags else flags = release_ms_flags end
	local cmd = "clang-cl -DNP_WIN32 -WX -EHsc -GS- -MD -DWIN_EXPORT -m32 "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkWindowsUWP32()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvarsall\" x86 store 10.0.10240 && lib /NOLOGO /OUT:WindowsUWP\\x86\\"..outputName..".lib "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildWindowsUWP64(cfile)
	local flags = ""
	if debug then flags = debug_ms_flags else flags = release_ms_flags end
	local cmd = "clang-cl -DNP_WIN32 -WX -EHsc -GS- -MD -DWIN_EXPORT -m64 "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkWindowsUWP64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvarsall\" x64 store 10.0.10240 && lib /NOLOGO /OUT:WindowsUWP\\x64\\"..outputName..".lib "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildWindowsUWPARM(cfile)
	local flags = ""
	if debug then flags = debug_ms_flags else flags = release_ms_flags end
	local cmd = "clang-cl -DNP_WIN32 -WX -EHsc -GS- -MD -DWIN_EXPORT -m32 --target=thumbv7-windows-msvc "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkWindowsUWPARM()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvarsall\" x86_arm store 10.0.10240 && lib /NOLOGO /OUT:WindowsUWP\\ARM\\"..outputName..".lib "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

--Win 8.1

function LinkWindows8132()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvarsall\" x86 8.1 store && lib /NOLOGO /OUT:Windows8.1\\x86\\"..outputName..".lib "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function LinkWindows8164()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvarsall\" x64 8.1 store && lib /NOLOGO /OUT:Windows8.1\\x64\\"..outputName..".lib "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function LinkWindows81ARM()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvarsall\" x86_arm 8.1 store && lib /NOLOGO /OUT:Windows8.1\\ARM\\"..outputName..".lib "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

--Win Phone 8.1

function LinkWindowsWP32()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files (x86)\\Microsoft Visual Studio 11.0\\VC\\WPSDK\\WP80\\vcvarsphoneall\" x86 && lib /NOLOGO /OUT:WindowsPhone\\x86\\"..outputName..".lib "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function LinkWindowsWPARM()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files (x86)\\Microsoft Visual Studio 11.0\\VC\\WPSDK\\WP80\\vcvarsphoneall\" x86_arm && lib /NOLOGO /OUT:WindowsPhone\\ARM\\"..outputName..".lib "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

--iOS

function BuildIOSArm7(cfile, isCpp)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	if isCpp then flags = flags.." -std=c++1z " end
	local cmd = "clang -DNP_IOS -mios-version-min=6.0 -target armv7-apple-ios "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkIOSArm7()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd iOS\\"..outputName.."_armv7.a "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildIOSArm7s(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_IOS -mios-version-min=6.0 -target armv7s-apple-ios "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkIOSArm7s()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd iOS\\"..outputName.."_armv7s.a "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildIOSArm64(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_IOS -mios-version-min=6.0 -target arm64-apple-ios "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkIOSArm64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd iOS\\"..outputName.."_arm64.a "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildIOSx86(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_IOS -mios-version-min=6.0 -target i386-apple-ios "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkIOSx86()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd iOS\\"..outputName.."_i386.a "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildIOSx64(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_IOS -mios-version-min=6.0 -target x86_64-apple-ios "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkIOSx64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd iOS\\"..outputName.."_x86_64.a "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

--macOS

function BuildMacOSx86(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_MACOS -mmacosx-version-min=10.5 -target i386-apple-macosx "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkMacOSx86()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd macOS\\"..outputName.."_i386.a "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildMacOSx64(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_MACOS -mmacosx-version-min=10.5 -target x86_64-apple-macosx "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkMacOSx64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd macOS\\"..outputName.."_x86_64.a "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

--Android

function BuildAndroidArm(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_ANDROID -target arm-none-android "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkAndroidArm()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=gnu Android\\armeabi\\"..outputName..".a "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildAndroidArm7(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_ANDROID -target armv7-none-android "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkAndroidArm7()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=gnu Android\\armeabi-v7a\\"..outputName..".a "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildAndroidArm64(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_ANDROID -target aarch64-none-android "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkAndroidArm64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=gnu Android\\arm64-v8a\\"..outputName..".a "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildAndroidx86(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_ANDROID -target i386-none-android "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkAndroidx86()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=gnu Android\\x86\\"..outputName..".a "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildAndroidx64(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_ANDROID -target x86_64-none-android "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkAndroidx64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=gnu Android\\x86_64\\"..outputName..".a "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

--linux

function BuildLinuxX64(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_LINUX -fPIC -target x86_64-linux-gnu "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkLinuxX64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=gnu Linux\\x86_64\\"..outputName..".a "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

function BuildLinuxX86(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_LINUX -fPIC -target i386-linux-gnu "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile
	if is_verbose == true then
		print(cmd)
	end
	if os.execute(cmd) then table.insert(objs, cfile..".o") end
end

function LinkLinuxX86()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=gnu Linux\\x86\\"..outputName..".a "..objs_str
	if is_verbose == true then
		print(cmd)
	end
	os.execute(cmd)
end

if platform == "windows" then 
	lfs.mkdir("Windows")
	lfs.chdir("Windows")
	lfs.mkdir("x64")
	lfs.mkdir("x86")
	lfs.mkdir("arm64")
	lfs.chdir("..")

    print ("Building Windows x86 DLL...")
	for i,f in ipairs(cfiles) do
		BuildWindows32DLL(f, false)
	end
	for i,f in ipairs(cppfiles) do
		BuildWindows32DLL(f, true)
	end
	LinkWindows32DLL()

	objs = {}
    print ("Building Windows x86...")
	for i,f in ipairs(cfiles) do
		BuildWindows32(f)
	end
	LinkWindows32()

	objs = {}
    print ("Building Windows x64...")
	for i,f in ipairs(cfiles) do
		BuildWindows64(f)
	end
	LinkWindows64()

	objs = {}
    print ("Building Windows arm64...")
	for i,f in ipairs(cfiles) do
		BuildWindowsARM64(f)
	end
	LinkWindowsARM64()

	objs = {}
	lfs.mkdir("WindowsUWP")
	lfs.chdir("WindowsUWP")
	lfs.mkdir("x64")
	lfs.mkdir("x86")
	lfs.mkdir("ARM")
	lfs.chdir("..")

    print ("Building Windows UWP x86...")
	for i,f in ipairs(cfiles) do
		BuildWindowsUWP32(f)
	end
	LinkWindowsUWP32()

	objs = {}
    print ("Building Windows UWP x64...")
	for i,f in ipairs(cfiles) do
		BuildWindowsUWP64(f)
	end
	LinkWindowsUWP64()

	objs = {}
    print ("Building Windows UWP ARM...")
	for i,f in ipairs(cfiles) do
		BuildWindowsUWPARM(f)
	end
	LinkWindowsUWPARM()

	objs = {}
	lfs.mkdir("Windows8.1")
	lfs.chdir("Windows8.1")
	lfs.mkdir("x64")
	lfs.mkdir("x86")
	lfs.mkdir("ARM")
	lfs.chdir("..")

    print ("Building Windows UWP 8.1 x86...")
	for i,f in ipairs(cfiles) do
		BuildWindowsUWP32(f)
	end
	LinkWindows8132()

	objs = {}
    print ("Building Windows UWP 8.1 x64...")
	for i,f in ipairs(cfiles) do
		BuildWindowsUWP64(f)
	end
	LinkWindows8164()

	objs = {}
    print ("Building Windows UWP 8.1 ARM...")
	for i,f in ipairs(cfiles) do
		BuildWindowsUWPARM(f)
	end
	LinkWindows81ARM()

	--

	objs = {}
	lfs.mkdir("WindowsPhone")
	lfs.chdir("WindowsPhone")
	lfs.mkdir("x86")
	lfs.mkdir("ARM")
	lfs.chdir("..")

    print ("Building Windows Phone x86...")
	for i,f in ipairs(cfiles) do
		BuildWindowsUWP32(f)
	end
	LinkWindowsWP32()

	objs = {}
    print ("Building Windows Phone ARM...")
	for i,f in ipairs(cfiles) do
		BuildWindowsUWPARM(f)
	end
	LinkWindowsWPARM()

elseif platform == "ios" then
	objs = {}
    print ("Building iOS arm7...")
	for i,f in ipairs(cfiles) do
		BuildIOSArm7(f, false)
	end
	for i,f in ipairs(cppfiles) do
		BuildIOSArm7(f, true)
	end
	LinkIOSArm7()
	
	objs = {}
    print ("Building iOS arm7s...")
	for i,f in ipairs(cfiles) do
		BuildIOSArm7s(f)
	end
	LinkIOSArm7s()
	
	objs = {}
    print ("Building iOS arm64...")
	for i,f in ipairs(cfiles) do
		BuildIOSArm64(f)
	end
	LinkIOSArm64()
	
	objs = {}
    print ("Building iOS x86...")
	for i,f in ipairs(cfiles) do
		BuildIOSx86(f)
	end
	LinkIOSx86()
	
	objs = {}
    print ("Building iOS x64...")
	for i,f in ipairs(cfiles) do
		BuildIOSx64(f)
	end
	LinkIOSx64()
	
	lfs.mkdir("iOS")
	
	if is_verbose == true then
		print(cmd)
	end
	os.execute("lipo iOS\\"..outputName.."_armv7.a iOS\\"..outputName.."_armv7s.a iOS\\"..outputName.."_arm64.a iOS\\"..outputName.."_i386.a iOS\\"..outputName.."_x86_64.a -create -output iOS\\"..outputName..".a")
	os.remove("iOS\\"..outputName.."_armv7.a ")
    os.remove("iOS\\"..outputName.."_armv7s.a ")
    os.remove("iOS\\"..outputName.."_arm64.a ")
    os.remove("iOS\\"..outputName.."_i386.a ")
    os.remove("iOS\\"..outputName.."_x86_64.a")

elseif platform == "macos" then	
	objs = {}
    print ("Building macOS x86...")
	for i,f in ipairs(cfiles) do
		BuildMacOSx86(f)
	end
	LinkMacOSx86()
	
	objs = {}
    print ("Building macOS x64...")
	for i,f in ipairs(cfiles) do
		BuildMacOSx64(f)
	end
	LinkMacOSx64()
	
	lfs.mkdir("macOS")
	
	if is_verbose == true then
		print(cmd)
	end
	os.execute("lipo macOS\\"..outputName.."_i386.a macOS\\"..outputName.."_x86_64.a -create -output macOS\\"..outputName..".a")
	os.remove("macOS\\"..outputName.."_i386.a")
	os.remove("macOS\\"..outputName.."_x86_64.a")
	
elseif platform == "llvm" then
	lfs.mkdir("LLVM")
	
	objs = {}
    print ("Building LLVM x86...")
	for i,f in ipairs(cfiles) do
		BuildLLVM32(f, false)
	end
	for i,f in ipairs(cppfiles) do
		BuildLLVM32(f, true)
	end
	LinkLLVM32()
	
	objs = {}
    print ("Building LLVM x64...")
	for i,f in ipairs(cfiles) do
		BuildLLVM64(f, false)
	end
	for i,f in ipairs(cppfiles) do
		BuildLLVM64(f, true)
	end
	LinkLLVM64()
	
	objs = {}
    print ("Building LLVM armv6...")
	for i,f in ipairs(cfiles) do
		BuildLLVMarmv6(f, false)
	end
	for i,f in ipairs(cppfiles) do
		BuildLLVMarmv6(f, true)
	end
	LinkLLVMarmv6()
	
	objs = {}
    print ("Building LLVM armv7...")
	for i,f in ipairs(cfiles) do
		BuildLLVMarmv7(f, false)
	end
	for i,f in ipairs(cppfiles) do
		BuildLLVMarmv7(f, true)
	end
	LinkLLVMarmv7()
	
	objs = {}
    print ("Building LLVM AArch64...")
	for i,f in ipairs(cfiles) do
		BuildLLVMAArch64(f, false)
	end
	for i,f in ipairs(cppfiles) do
		BuildLLVMAArch64(f, true)
	end
	LinkLLVMAArch64()

	objs = {}
    print ("Building LLVM x86 Apple...")
	for i,f in ipairs(cfiles) do
		BuildLLVM32Appl(f, false)
	end
	for i,f in ipairs(cppfiles) do
		BuildLLVM32Appl(f, true)
	end
	LinkLLVM32Appl()
	
	objs = {}
    print ("Building LLVM x64 Apple...")
	for i,f in ipairs(cfiles) do
		BuildLLVM64Appl(f, false)
	end
	for i,f in ipairs(cppfiles) do
		BuildLLVM64Appl(f, true)
	end
	LinkLLVM64Appl()
	
	objs = {}
    print ("Building LLVM armv7 Apple...")
	for i,f in ipairs(cfiles) do
		BuildLLVMarmv7Appl(f, false)
	end
	for i,f in ipairs(cppfiles) do
		BuildLLVMarmv7Appl(f, true)
	end
	LinkLLVMarmv7Appl()
	
	objs = {}
    print ("Building LLVM armv7s Apple...")
	for i,f in ipairs(cfiles) do
		BuildLLVMarmv7sAppl(f, false)
	end
	for i,f in ipairs(cppfiles) do
		BuildLLVMarmv7sAppl(f, true)
	end
	LinkLLVMarmv7sAppl()
	
	objs = {}
    print ("Building LLVM AArch64 Apple...")
	for i,f in ipairs(cfiles) do
		BuildLLVMAArch64Appl(f, false)
	end
	for i,f in ipairs(cppfiles) do
		BuildLLVMAArch64Appl(f, true)
	end
	LinkLLVMAArch64Appl()

elseif platform == "linux" then
	lfs.mkdir("Linux")
	lfs.chdir("Linux")
	lfs.mkdir("x86_64")
	lfs.mkdir("x86")
	lfs.chdir("..")
	
	objs = {}
    print ("Building Linux x64...")
	for i,f in ipairs(cfiles) do
		BuildLinuxX64(f)
	end
	LinkLinuxX64()
	
	objs = {}
    print ("Building Linux x86...")
	for i,f in ipairs(cfiles) do
		BuildLinuxX86(f)
	end
	LinkLinuxX86()

elseif platform == "android" then
	lfs.mkdir("Android")
	lfs.chdir("Android")
	lfs.mkdir("x86_64")
	lfs.mkdir("x86")
	lfs.mkdir("arm64-v8a")
	lfs.mkdir("armeabi")
	lfs.mkdir("armeabi-v7a")
	lfs.chdir("..")
	
	objs = {}
    print ("Building Android arm...")
	for i,f in ipairs(cfiles) do
		BuildAndroidArm(f)
	end
	LinkAndroidArm()

	objs = {}
    print ("Building Android arm7...")
	for i,f in ipairs(cfiles) do
		BuildAndroidArm7(f)
	end
	LinkAndroidArm7()

	objs = {}
    print ("Building Android arm64...")
	for i,f in ipairs(cfiles) do
		BuildAndroidArm64(f)
	end
	LinkAndroidArm64()

	objs = {}
    print ("Building Android x86...")
	for i,f in ipairs(cfiles) do
		BuildAndroidx86(f)
	end
	LinkAndroidx86()

	objs = {}
    print ("Building Android x64...")
	for i,f in ipairs(cfiles) do
		BuildAndroidx64(f)
	end
	LinkAndroidx64()
end
