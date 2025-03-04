CMAKE_MINIMUM_REQUIRED (VERSION 3.30)
PROJECT (libNativePath)

FIND_PATH(NP_INCLUDE_DIR NAMES NativeMath.h
  PATHS
  ${PROJECT_SOURCE_DIR}/NativePath/
)

INCLUDE_DIRECTORIES(${NP_INCLUDE_DIR} ${NP_INCLUDE_DIR}/../source)

IF(${CMAKE_GENERATOR} MATCHES "Unix Makefiles")
	SET(NP_LIB_DIR ${NP_INCLUDE_DIR}/..)
	SET(NP_LIB NativePath)
ELSE()
	SET(NP_LIB_DIR ${NP_INCLUDE_DIR}/..)
	SET(NP_LIB libNativePath)
ENDIF()

ADD_LIBRARY(${NP_LIB} STATIC
    source/NativeMemory.c
	source/NativeTime.cpp
	source/NativeDynamicLinking.c
	source/stdlib.c
	source/stdio.c
	source/NEONvsSSE.c
	source/NativeThreading.cpp
	source/workarounds.c
)
