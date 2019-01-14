mkdir -p build/iOS
mkdir -p build/macOS
#xcodebuild clean

xcodebuild VALID_ARCHS="armv7 armv7s arm64" ARCHS="armv7 armv7s arm64" ONLY_ACTIVE_ARCH=NO -sdk iphoneos -mios-version-min=6.0
xcodebuild VALID_ARCHS="x86_64 i386" ARCHS="x86_64 i386" ONLY_ACTIVE_ARCH=NO -sdk iphonesimulator -mios-version-min=6.0
lipo build/Release-iphoneos/libNativePath.a build/Release-iphonesimulator/libNativePath.a -create -output build/iOS/libNativePath.a

xcodebuild VALID_ARCHS="x86_64" ARCHS="x86_64" -sdk macosx
mv build/Release/libNativePath.a build/macOS/


file build/iOS/libNativePath.a
file build/macOS/libNativePath.a
