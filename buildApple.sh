#!/bin/bash
set -e

mkdir -p build/ios-arm64
mkdir -p build/iossimulator-arm64
mkdir -p build/osx-arm64
#xcodebuild clean

xcodebuild VALID_ARCHS="arm64" ARCHS="arm64" ONLY_ACTIVE_ARCH=NO -sdk iphoneos        IPHONEOS_DEPLOYMENT_TARGET=12.0
mv build/Release-iphoneos/libNativePath.a build/ios-arm64/

xcodebuild VALID_ARCHS="arm64" ARCHS="arm64" ONLY_ACTIVE_ARCH=NO -sdk iphonesimulator IPHONEOS_DEPLOYMENT_TARGET=12.0
mv build/Release-iphonesimulator/libNativePath.a build/iossimulator-arm64/

xcodebuild VALID_ARCHS="arm64" ARCHS="arm64" ONLY_ACTIVE_ARCH=NO -sdk macosx MACOSX_DEPLOYMENT_TARGET=11.0
mv build/Release/libNativePath.a build/osx-arm64/

file build/ios-arm64/libNativePath.a
file build/iossimulator-arm64/libNativePath.a
file build/osx-arm64/libNativePath.a
