CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Android defines
SET(ANDROID_ABI armeabi-v7a)
# Global defines
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Include dir
SET(LIB_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

PROJECT(M3DMath)

# For android arm support (for implement in the future)
IF(ANDROID)
	SET(CLANG_TOOLCHAIN_VERSION 8.0.2)
	SET(ANDROID_TOOLCHAIN_INCLUDE_DIR ${ANDROID_TOOLCHAIN_ROOT}\\lib64\\clang\\${CLANG_TOOLCHAIN_VERSION}\\include)
	SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffreestanding -march=armv7-a -mfpu=neon -mfloat-abi=softfp" )
ENDIF()
# For x86_64 windows
IF()
	SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx -ftree-vectorize -funsafe-math-optimizations -mveclibabi=svml" )
ENDIF()
# For x86_64 linux
IF(NOT ANDROID AND NOT WIN32)
	SET ( CMAKE_CXX_COMPILER "/opt/intel/system_studio_2019/bin/icpc")
	SET ( CMAKE_CC_COMPILER "/opt/intel/system_studio_2019/bin/icc")
	# SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g" )
	IF(CMAKE_DEBUG)
		SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g" )
	ENDIF()
ENDIF()

# Targets
SET(M3DMATH_LIB_TARGET libM3DMath)
SET(MATH_TESTS_TARGET Math3DTests)

# Directories
ADD_SUBDIRECTORY("libM3DMath")
ADD_SUBDIRECTORY("MathTests")