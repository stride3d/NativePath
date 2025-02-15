#ifndef NO_INTRINSICS

#ifdef _WIN32
	#define NATIVE_PATH_WIN
	//define something for Windows (32-bit and 64-bit, this part is common)
	#if defined(_M_ARM) || defined(_M_ARM64)
		#include <arm_neon.h>
	#else
		#include "NEONvsSSE.h"
	#endif

	#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
	// This code is for Win32 desktop apps
	#define NATIVE_PATH_WIN_DESKTOP
	#else
	// This code is for WinRT Windows Store apps
	#define NATIVE_PATH_WIN_APP
	#endif

	#ifdef _WIN64
	  //define something for Windows (64-bit only)
	#endif
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_IPHONE_SIMULATOR
        #define NATIVE_PATH_IOS
         // iOS Simulator
        #include "NEONvsSSE.h"
    #elif TARGET_OS_IPHONE
        #define NATIVE_PATH_IOS
        #include <stdio.h>
        #include <arm_neon.h>
        // iOS device
    #elif TARGET_OS_MAC
        // Other kinds of Mac OS
        #include "NEONvsSSE.h"
    #else
    #   error "Unknown Apple platform"
    #endif
#elif defined(__ANDROID__)
	#define NATIVE_PATH_ANDROID
	#include <stdio.h>
	#ifdef __USE_NEON__
	#include <arm_neon.h>
	#else
	#include "NEONvsSSE.h"
	#endif
#elif defined(__linux__) || defined(__ORBIS__)
	#define NATIVE_PATH_LINUX
	#include <stdio.h>
	// We have to undefine __SSE4_2__ otherwise it will use __builtin_ia32_insertps128
	// in a call where the last argument is expected to be a literal and NEONvsSSE.h would provide
	// just a `const int`.
	#undef __SSE4_2__
	#include "NEONvsSSE.h"
#elif __unix__ // all unices not caught above
    // Unix
#elif defined(_POSIX_VERSION)
    // POSIX
#else
#   error "Unknown compiler"
#endif

int npCanUseSIMD()
{
	return 1;
}

int8x16_t np_vaddq_s8(int8x16_t a, int8x16_t b)
{
	return vaddq_s8(a, b);
}

int16x8_t np_vaddq_s16(int16x8_t a, int16x8_t b)
{
	return vaddq_s16(a, b);
}

int32x4_t np_vaddq_s32(int32x4_t a, int32x4_t b)
{
	return vaddq_s32(a, b);
}

int64x2_t np_vaddq_s64(int64x2_t a, int64x2_t b)
{
	return vaddq_s64(a, b);
}

float32x4_t np_vaddq_f32(float32x4_t a, float32x4_t b)
{
	return vaddq_f32(a, b);
}

uint8x16_t np_vaddq_u8(uint8x16_t a, uint8x16_t b)
{
	return vaddq_u8(a, b);
}

uint16x8_t np_vaddq_u16(uint16x8_t a, uint16x8_t b)
{
	return vaddq_u16(a, b);
}

uint32x4_t np_vaddq_u32(uint32x4_t a, uint32x4_t b)
{
	return vaddq_u32(a, b);
}

uint64x2_t np_vaddq_u64(uint64x2_t a, uint64x2_t b)
{
	return vaddq_u64(a, b);
}

int8x16_t np_vhaddq_s8(int8x16_t a, int8x16_t b)
{
	return vhaddq_s8(a, b);
}

int16x8_t np_vhaddq_s16(int16x8_t a, int16x8_t b)
{
	return vhaddq_s16(a, b);
}

int32x4_t np_vhaddq_s32(int32x4_t a, int32x4_t b)
{
	return vhaddq_s32(a, b);
}

uint8x16_t np_vhaddq_u8(uint8x16_t a, uint8x16_t b)
{
	return vhaddq_u8(a, b);
}

uint16x8_t np_vhaddq_u16(uint16x8_t a, uint16x8_t b)
{
	return vhaddq_u16(a, b);
}

uint32x4_t np_vhaddq_u32(uint32x4_t a, uint32x4_t b)
{
	return vhaddq_u32(a, b);
}

int8x16_t np_vrhaddq_s8(int8x16_t a, int8x16_t b)
{
	return vrhaddq_s8(a, b);
}

int16x8_t np_vrhaddq_s16(int16x8_t a, int16x8_t b)
{
	return vrhaddq_s16(a, b);
}

int32x4_t np_vrhaddq_s32(int32x4_t a, int32x4_t b)
{
	return vrhaddq_s32(a, b);
}

uint8x16_t np_vrhaddq_u8(uint8x16_t a, uint8x16_t b)
{
	return vrhaddq_u8(a, b);
}

uint16x8_t np_vrhaddq_u16(uint16x8_t a, uint16x8_t b)
{
	return vrhaddq_u16(a, b);
}

uint32x4_t np_vrhaddq_u32(uint32x4_t a, uint32x4_t b)
{
	return vrhaddq_u32(a, b);
}

int8x16_t np_vqaddq_s8(int8x16_t a, int8x16_t b)
{
	return vqaddq_s8(a, b);
}

int16x8_t np_vqaddq_s16(int16x8_t a, int16x8_t b)
{
	return vqaddq_s16(a, b);
}

int32x4_t np_vqaddq_s32(int32x4_t a, int32x4_t b)
{
	return vqaddq_s32(a, b);
}

int64x2_t np_vqaddq_s64(int64x2_t a, int64x2_t b)
{
	return vqaddq_s64(a, b);
}

uint8x16_t np_vqaddq_u8(uint8x16_t a, uint8x16_t b)
{
	return vqaddq_u8(a, b);
}

uint16x8_t np_vqaddq_u16(uint16x8_t a, uint16x8_t b)
{
	return vqaddq_u16(a, b);
}

uint32x4_t np_vqaddq_u32(uint32x4_t a, uint32x4_t b)
{
	return vqaddq_u32(a, b);
}

uint64x2_t np_vqaddq_u64(uint64x2_t a, uint64x2_t b)
{
	return vqaddq_u64(a, b);
}

int8x16_t np_vmulq_s8(int8x16_t a, int8x16_t b)
{
	return vmulq_s8(a, b);
}

int16x8_t np_vmulq_s16(int16x8_t a, int16x8_t b)
{
	return vmulq_s16(a, b);
}

int32x4_t np_vmulq_s32(int32x4_t a, int32x4_t b)
{
	return vmulq_s32(a, b);
}

float32x4_t np_vmulq_f32(float32x4_t a, float32x4_t b)
{
	return vmulq_f32(a, b);
}

uint8x16_t np_vmulq_u8(uint8x16_t a, uint8x16_t b)
{
	return vmulq_u8(a, b);
}

uint16x8_t np_vmulq_u16(uint16x8_t a, uint16x8_t b)
{
	return vmulq_u16(a, b);
}

uint32x4_t np_vmulq_u32(uint32x4_t a, uint32x4_t b)
{
	return vmulq_u32(a, b);
}

poly8x16_t np_vmulq_p8(poly8x16_t a, poly8x16_t b)
{
	return vmulq_p8(a, b);
}

int8x16_t np_vmlaq_s8(int8x16_t a, int8x16_t b, int8x16_t c)
{
	return vmlaq_s8(a, b, c);
}

int16x8_t np_vmlaq_s16(int16x8_t a, int16x8_t b, int16x8_t c)
{
	return vmlaq_s16(a, b, c);
}

int32x4_t np_vmlaq_s32(int32x4_t a, int32x4_t b, int32x4_t c)
{
	return vmlaq_s32(a, b, c);
}

float32x4_t np_vmlaq_f32(float32x4_t a, float32x4_t b, float32x4_t c)
{
	return vmlaq_f32(a, b, c);
}

uint8x16_t np_vmlaq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c)
{
	return vmlaq_u8(a, b, c);
}

uint16x8_t np_vmlaq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c)
{
	return vmlaq_u16(a, b, c);
}

uint32x4_t np_vmlaq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c)
{
	return vmlaq_u32(a, b, c);
}

int8x16_t np_vmlsq_s8(int8x16_t a, int8x16_t b, int8x16_t c)
{
	return vmlsq_s8(a, b, c);
}

int16x8_t np_vmlsq_s16(int16x8_t a, int16x8_t b, int16x8_t c)
{
	return vmlsq_s16(a, b, c);
}

int32x4_t np_vmlsq_s32(int32x4_t a, int32x4_t b, int32x4_t c)
{
	return vmlsq_s32(a, b, c);
}

float32x4_t np_vmlsq_f32(float32x4_t a, float32x4_t b, float32x4_t c)
{
	return vmlsq_f32(a, b, c);
}

uint8x16_t np_vmlsq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c)
{
	return vmlsq_u8(a, b, c);
}

uint16x8_t np_vmlsq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c)
{
	return vmlsq_u16(a, b, c);
}

uint32x4_t np_vmlsq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c)
{
	return vmlsq_u32(a, b, c);
}

int16x8_t np_vqdmulhq_s16(int16x8_t a, int16x8_t b)
{
	return vqdmulhq_s16(a, b);
}

int32x4_t np_vqdmulhq_s32(int32x4_t a, int32x4_t b)
{
	return vqdmulhq_s32(a, b);
}

int16x8_t np_vqrdmulhq_s16(int16x8_t a, int16x8_t b)
{
	return vqrdmulhq_s16(a, b);
}

int32x4_t np_vqrdmulhq_s32(int32x4_t a, int32x4_t b)
{
	return vqrdmulhq_s32(a, b);
}

int8x16_t np_vsubq_s8(int8x16_t a, int8x16_t b)
{
	return vsubq_s8(a, b);
}

int16x8_t np_vsubq_s16(int16x8_t a, int16x8_t b)
{
	return vsubq_s16(a, b);
}

int32x4_t np_vsubq_s32(int32x4_t a, int32x4_t b)
{
	return vsubq_s32(a, b);
}

int64x2_t np_vsubq_s64(int64x2_t a, int64x2_t b)
{
	return vsubq_s64(a, b);
}

float32x4_t np_vsubq_f32(float32x4_t a, float32x4_t b)
{
	return vsubq_f32(a, b);
}

uint8x16_t np_vsubq_u8(uint8x16_t a, uint8x16_t b)
{
	return vsubq_u8(a, b);
}

uint16x8_t np_vsubq_u16(uint16x8_t a, uint16x8_t b)
{
	return vsubq_u16(a, b);
}

uint32x4_t np_vsubq_u32(uint32x4_t a, uint32x4_t b)
{
	return vsubq_u32(a, b);
}

uint64x2_t np_vsubq_u64(uint64x2_t a, uint64x2_t b)
{
	return vsubq_u64(a, b);
}

int8x16_t np_vqsubq_s8(int8x16_t a, int8x16_t b)
{
	return vqsubq_s8(a, b);
}

int16x8_t np_vqsubq_s16(int16x8_t a, int16x8_t b)
{
	return vqsubq_s16(a, b);
}

int32x4_t np_vqsubq_s32(int32x4_t a, int32x4_t b)
{
	return vqsubq_s32(a, b);
}

int64x2_t np_vqsubq_s64(int64x2_t a, int64x2_t b)
{
	return vqsubq_s64(a, b);
}

uint8x16_t np_vqsubq_u8(uint8x16_t a, uint8x16_t b)
{
	return vqsubq_u8(a, b);
}

uint16x8_t np_vqsubq_u16(uint16x8_t a, uint16x8_t b)
{
	return vqsubq_u16(a, b);
}

uint32x4_t np_vqsubq_u32(uint32x4_t a, uint32x4_t b)
{
	return vqsubq_u32(a, b);
}

uint64x2_t np_vqsubq_u64(uint64x2_t a, uint64x2_t b)
{
	return vqsubq_u64(a, b);
}

int8x16_t np_vhsubq_s8(int8x16_t a, int8x16_t b)
{
	return vhsubq_s8(a, b);
}

int16x8_t np_vhsubq_s16(int16x8_t a, int16x8_t b)
{
	return vhsubq_s16(a, b);
}

int32x4_t np_vhsubq_s32(int32x4_t a, int32x4_t b)
{
	return vhsubq_s32(a, b);
}

uint8x16_t np_vhsubq_u8(uint8x16_t a, uint8x16_t b)
{
	return vhsubq_u8(a, b);
}

uint16x8_t np_vhsubq_u16(uint16x8_t a, uint16x8_t b)
{
	return vhsubq_u16(a, b);
}

uint32x4_t np_vhsubq_u32(uint32x4_t a, uint32x4_t b)
{
	return vhsubq_u32(a, b);
}

uint8x16_t np_vceqq_s8(int8x16_t a, int8x16_t b)
{
	return vceqq_s8(a, b);
}

uint16x8_t np_vceqq_s16(int16x8_t a, int16x8_t b)
{
	return vceqq_s16(a, b);
}

uint32x4_t np_vceqq_s32(int32x4_t a, int32x4_t b)
{
	return vceqq_s32(a, b);
}

uint32x4_t np_vceqq_f32(float32x4_t a, float32x4_t b)
{
	return vceqq_f32(a, b);
}

uint8x16_t np_vceqq_u8(uint8x16_t a, uint8x16_t b)
{
	return vceqq_u8(a, b);
}

uint16x8_t np_vceqq_u16(uint16x8_t a, uint16x8_t b)
{
	return vceqq_u16(a, b);
}

uint32x4_t np_vceqq_u32(uint32x4_t a, uint32x4_t b)
{
	return vceqq_u32(a, b);
}

uint8x16_t np_vceqq_p8(poly8x16_t a, poly8x16_t b)
{
	return vceqq_p8(a, b);
}

uint8x16_t np_vcgeq_s8(int8x16_t a, int8x16_t b)
{
	return vcgeq_s8(a, b);
}

uint16x8_t np_vcgeq_s16(int16x8_t a, int16x8_t b)
{
	return vcgeq_s16(a, b);
}

uint32x4_t np_vcgeq_s32(int32x4_t a, int32x4_t b)
{
	return vcgeq_s32(a, b);
}

uint32x4_t np_vcgeq_f32(float32x4_t a, float32x4_t b)
{
	return vcgeq_f32(a, b);
}

uint8x16_t np_vcgeq_u8(uint8x16_t a, uint8x16_t b)
{
	return vcgeq_u8(a, b);
}

uint16x8_t np_vcgeq_u16(uint16x8_t a, uint16x8_t b)
{
	return vcgeq_u16(a, b);
}

uint32x4_t np_vcgeq_u32(uint32x4_t a, uint32x4_t b)
{
	return vcgeq_u32(a, b);
}

uint8x16_t np_vcleq_s8(int8x16_t a, int8x16_t b)
{
	return vcleq_s8(a, b);
}

uint16x8_t np_vcleq_s16(int16x8_t a, int16x8_t b)
{
	return vcleq_s16(a, b);
}

uint32x4_t np_vcleq_s32(int32x4_t a, int32x4_t b)
{
	return vcleq_s32(a, b);
}

uint32x4_t np_vcleq_f32(float32x4_t a, float32x4_t b)
{
	return vcleq_f32(a, b);
}

uint8x16_t np_vcleq_u8(uint8x16_t a, uint8x16_t b)
{
	return vcleq_u8(a, b);
}

uint16x8_t np_vcleq_u16(uint16x8_t a, uint16x8_t b)
{
	return vcleq_u16(a, b);
}

uint32x4_t np_vcleq_u32(uint32x4_t a, uint32x4_t b)
{
	return vcleq_u32(a, b);
}

uint8x16_t np_vcgtq_s8(int8x16_t a, int8x16_t b)
{
	return vcgtq_s8(a, b);
}

uint16x8_t np_vcgtq_s16(int16x8_t a, int16x8_t b)
{
	return vcgtq_s16(a, b);
}

uint32x4_t np_vcgtq_s32(int32x4_t a, int32x4_t b)
{
	return vcgtq_s32(a, b);
}

uint32x4_t np_vcgtq_f32(float32x4_t a, float32x4_t b)
{
	return vcgtq_f32(a, b);
}

uint8x16_t np_vcgtq_u8(uint8x16_t a, uint8x16_t b)
{
	return vcgtq_u8(a, b);
}

uint16x8_t np_vcgtq_u16(uint16x8_t a, uint16x8_t b)
{
	return vcgtq_u16(a, b);
}

uint32x4_t np_vcgtq_u32(uint32x4_t a, uint32x4_t b)
{
	return vcgtq_u32(a, b);
}

uint8x16_t np_vcltq_s8(int8x16_t a, int8x16_t b)
{
	return vcltq_s8(a, b);
}

uint16x8_t np_vcltq_s16(int16x8_t a, int16x8_t b)
{
	return vcltq_s16(a, b);
}

uint32x4_t np_vcltq_s32(int32x4_t a, int32x4_t b)
{
	return vcltq_s32(a, b);
}

uint32x4_t np_vcltq_f32(float32x4_t a, float32x4_t b)
{
	return vcltq_f32(a, b);
}

uint8x16_t np_vcltq_u8(uint8x16_t a, uint8x16_t b)
{
	return vcltq_u8(a, b);
}

uint16x8_t np_vcltq_u16(uint16x8_t a, uint16x8_t b)
{
	return vcltq_u16(a, b);
}

uint32x4_t np_vcltq_u32(uint32x4_t a, uint32x4_t b)
{
	return vcltq_u32(a, b);
}

uint8x16_t np_vtstq_s8(int8x16_t a, int8x16_t b)
{
	return vtstq_s8(a, b);
}

uint16x8_t np_vtstq_s16(int16x8_t a, int16x8_t b)
{
	return vtstq_s16(a, b);
}

uint32x4_t np_vtstq_s32(int32x4_t a, int32x4_t b)
{
	return vtstq_s32(a, b);
}

uint8x16_t np_vtstq_u8(uint8x16_t a, uint8x16_t b)
{
	return vtstq_u8(a, b);
}

uint16x8_t np_vtstq_u16(uint16x8_t a, uint16x8_t b)
{
	return vtstq_u16(a, b);
}

uint32x4_t np_vtstq_u32(uint32x4_t a, uint32x4_t b)
{
	return vtstq_u32(a, b);
}

uint8x16_t np_vtstq_p8(poly8x16_t a, poly8x16_t b)
{
	return vtstq_p8(a, b);
}

int8x16_t np_vabdq_s8(int8x16_t a, int8x16_t b)
{
	return vabdq_s8(a, b);
}

int16x8_t np_vabdq_s16(int16x8_t a, int16x8_t b)
{
	return vabdq_s16(a, b);
}

int32x4_t np_vabdq_s32(int32x4_t a, int32x4_t b)
{
	return vabdq_s32(a, b);
}

uint8x16_t np_vabdq_u8(uint8x16_t a, uint8x16_t b)
{
	return vabdq_u8(a, b);
}

uint16x8_t np_vabdq_u16(uint16x8_t a, uint16x8_t b)
{
	return vabdq_u16(a, b);
}

uint32x4_t np_vabdq_u32(uint32x4_t a, uint32x4_t b)
{
	return vabdq_u32(a, b);
}

float32x4_t np_vabdq_f32(float32x4_t a, float32x4_t b)
{
	return vabdq_f32(a, b);
}

int8x16_t np_vabaq_s8(int8x16_t a, int8x16_t b, int8x16_t c)
{
	return vabaq_s8(a, b, c);
}

int16x8_t np_vabaq_s16(int16x8_t a, int16x8_t b, int16x8_t c)
{
	return vabaq_s16(a, b, c);
}

int32x4_t np_vabaq_s32(int32x4_t a, int32x4_t b, int32x4_t c)
{
	return vabaq_s32(a, b, c);
}

uint8x16_t np_vabaq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c)
{
	return vabaq_u8(a, b, c);
}

uint16x8_t np_vabaq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c)
{
	return vabaq_u16(a, b, c);
}

uint32x4_t np_vabaq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c)
{
	return vabaq_u32(a, b, c);
}

int8x16_t np_vmaxq_s8(int8x16_t a, int8x16_t b)
{
	return vmaxq_s8(a, b);
}

int16x8_t np_vmaxq_s16(int16x8_t a, int16x8_t b)
{
	return vmaxq_s16(a, b);
}

int32x4_t np_vmaxq_s32(int32x4_t a, int32x4_t b)
{
	return vmaxq_s32(a, b);
}

uint8x16_t np_vmaxq_u8(uint8x16_t a, uint8x16_t b)
{
	return vmaxq_u8(a, b);
}

uint16x8_t np_vmaxq_u16(uint16x8_t a, uint16x8_t b)
{
	return vmaxq_u16(a, b);
}

uint32x4_t np_vmaxq_u32(uint32x4_t a, uint32x4_t b)
{
	return vmaxq_u32(a, b);
}

float32x4_t np_vmaxq_f32(float32x4_t a, float32x4_t b)
{
	return vmaxq_f32(a, b);
}

int8x16_t np_vminq_s8(int8x16_t a, int8x16_t b)
{
	return vminq_s8(a, b);
}

int16x8_t np_vminq_s16(int16x8_t a, int16x8_t b)
{
	return vminq_s16(a, b);
}

int32x4_t np_vminq_s32(int32x4_t a, int32x4_t b)
{
	return vminq_s32(a, b);
}

uint8x16_t np_vminq_u8(uint8x16_t a, uint8x16_t b)
{
	return vminq_u8(a, b);
}

uint16x8_t np_vminq_u16(uint16x8_t a, uint16x8_t b)
{
	return vminq_u16(a, b);
}

uint32x4_t np_vminq_u32(uint32x4_t a, uint32x4_t b)
{
	return vminq_u32(a, b);
}

float32x4_t np_vminq_f32(float32x4_t a, float32x4_t b)
{
	return vminq_f32(a, b);
}

int16x8_t np_vpaddlq_s8(int8x16_t a)
{
	return vpaddlq_s8(a);
}

int32x4_t np_vpaddlq_s16(int16x8_t a)
{
	return vpaddlq_s16(a);
}

int64x2_t np_vpaddlq_s32(int32x4_t a)
{
	return vpaddlq_s32(a);
}

uint16x8_t np_vpaddlq_u8(uint8x16_t a)
{
	return vpaddlq_u8(a);
}

uint32x4_t np_vpaddlq_u16(uint16x8_t a)
{
	return vpaddlq_u16(a);
}

uint64x2_t np_vpaddlq_u32(uint32x4_t a)
{
	return vpaddlq_u32(a);
}

int16x8_t np_vpadalq_s8(int16x8_t a, int8x16_t b)
{
	return vpadalq_s8(a, b);
}

int32x4_t np_vpadalq_s16(int32x4_t a, int16x8_t b)
{
	return vpadalq_s16(a, b);
}

int64x2_t np_vpadalq_s32(int64x2_t a, int32x4_t b)
{
	return vpadalq_s32(a, b);
}

uint16x8_t np_vpadalq_u8(uint16x8_t a, uint8x16_t b)
{
	return vpadalq_u8(a, b);
}

uint32x4_t np_vpadalq_u16(uint32x4_t a, uint16x8_t b)
{
	return vpadalq_u16(a, b);
}

uint64x2_t np_vpadalq_u32(uint64x2_t a, uint32x4_t b)
{
	return vpadalq_u32(a, b);
}

float32x4_t np_vrecpsq_f32(float32x4_t a, float32x4_t b)
{
	return vrecpsq_f32(a, b);
}

float32x4_t np_vrsqrtsq_f32(float32x4_t a, float32x4_t b)
{
	return vrsqrtsq_f32(a, b);
}

int8x16_t np_vshlq_s8(int8x16_t a, int8x16_t b)
{
	return vshlq_s8(a, b);
}

int16x8_t np_vshlq_s16(int16x8_t a, int16x8_t b)
{
	return vshlq_s16(a, b);
}

int32x4_t np_vshlq_s32(int32x4_t a, int32x4_t b)
{
	return vshlq_s32(a, b);
}

int64x2_t np_vshlq_s64(int64x2_t a, int64x2_t b)
{
	return vshlq_s64(a, b);
}

uint8x16_t np_vshlq_u8(uint8x16_t a, int8x16_t b)
{
	return vshlq_u8(a, b);
}

uint16x8_t np_vshlq_u16(uint16x8_t a, int16x8_t b)
{
	return vshlq_u16(a, b);
}

uint32x4_t np_vshlq_u32(uint32x4_t a, int32x4_t b)
{
	return vshlq_u32(a, b);
}

uint64x2_t np_vshlq_u64(uint64x2_t a, int64x2_t b)
{
	return vshlq_u64(a, b);
}

int8x16_t np_vqshlq_s8(int8x16_t a, int8x16_t b)
{
	return vqshlq_s8(a, b);
}

int16x8_t np_vqshlq_s16(int16x8_t a, int16x8_t b)
{
	return vqshlq_s16(a, b);
}

int32x4_t np_vqshlq_s32(int32x4_t a, int32x4_t b)
{
	return vqshlq_s32(a, b);
}

int64x2_t np_vqshlq_s64(int64x2_t a, int64x2_t b)
{
	return vqshlq_s64(a, b);
}

uint8x16_t np_vqshlq_u8(uint8x16_t a, int8x16_t b)
{
	return vqshlq_u8(a, b);
}

uint16x8_t np_vqshlq_u16(uint16x8_t a, int16x8_t b)
{
	return vqshlq_u16(a, b);
}

uint32x4_t np_vqshlq_u32(uint32x4_t a, int32x4_t b)
{
	return vqshlq_u32(a, b);
}

uint64x2_t np_vqshlq_u64(uint64x2_t a, int64x2_t b)
{
	return vqshlq_u64(a, b);
}

int8x16_t np_vrshlq_s8(int8x16_t a, int8x16_t b)
{
	return vrshlq_s8(a, b);
}

int16x8_t np_vrshlq_s16(int16x8_t a, int16x8_t b)
{
	return vrshlq_s16(a, b);
}

int32x4_t np_vrshlq_s32(int32x4_t a, int32x4_t b)
{
	return vrshlq_s32(a, b);
}

int64x2_t np_vrshlq_s64(int64x2_t a, int64x2_t b)
{
	return vrshlq_s64(a, b);
}

uint8x16_t np_vrshlq_u8(uint8x16_t a, int8x16_t b)
{
	return vrshlq_u8(a, b);
}

uint16x8_t np_vrshlq_u16(uint16x8_t a, int16x8_t b)
{
	return vrshlq_u16(a, b);
}

uint32x4_t np_vrshlq_u32(uint32x4_t a, int32x4_t b)
{
	return vrshlq_u32(a, b);
}

uint64x2_t np_vrshlq_u64(uint64x2_t a, int64x2_t b)
{
	return vrshlq_u64(a, b);
}

int8x16_t np_vqrshlq_s8(int8x16_t a, int8x16_t b)
{
	return vqrshlq_s8(a, b);
}

int16x8_t np_vqrshlq_s16(int16x8_t a, int16x8_t b)
{
	return vqrshlq_s16(a, b);
}

int32x4_t np_vqrshlq_s32(int32x4_t a, int32x4_t b)
{
	return vqrshlq_s32(a, b);
}

int64x2_t np_vqrshlq_s64(int64x2_t a, int64x2_t b)
{
	return vqrshlq_s64(a, b);
}

uint8x16_t np_vqrshlq_u8(uint8x16_t a, int8x16_t b)
{
	return vqrshlq_u8(a, b);
}

uint16x8_t np_vqrshlq_u16(uint16x8_t a, int16x8_t b)
{
	return vqrshlq_u16(a, b);
}

uint32x4_t np_vqrshlq_u32(uint32x4_t a, int32x4_t b)
{
	return vqrshlq_u32(a, b);
}

uint64x2_t np_vqrshlq_u64(uint64x2_t a, int64x2_t b)
{
	return vqrshlq_u64(a, b);
}

int8x16_t np_vshrq_n_s8_1(int8x16_t a)
{
	return vshrq_n_s8(a, 1);
}

int8x16_t np_vshrq_n_s8_2(int8x16_t a)
{
	return vshrq_n_s8(a, 2);
}

int8x16_t np_vshrq_n_s8_3(int8x16_t a)
{
	return vshrq_n_s8(a, 3);
}

int8x16_t np_vshrq_n_s8_4(int8x16_t a)
{
	return vshrq_n_s8(a, 4);
}

int8x16_t np_vshrq_n_s8_5(int8x16_t a)
{
	return vshrq_n_s8(a, 5);
}

int8x16_t np_vshrq_n_s8_6(int8x16_t a)
{
	return vshrq_n_s8(a, 6);
}

int8x16_t np_vshrq_n_s8_7(int8x16_t a)
{
	return vshrq_n_s8(a, 7);
}

int8x16_t np_vshrq_n_s8_8(int8x16_t a)
{
	return vshrq_n_s8(a, 8);
}

int16x8_t np_vshrq_n_s16_1(int16x8_t a)
{
	return vshrq_n_s16(a, 1);
}

int16x8_t np_vshrq_n_s16_2(int16x8_t a)
{
	return vshrq_n_s16(a, 2);
}

int16x8_t np_vshrq_n_s16_3(int16x8_t a)
{
	return vshrq_n_s16(a, 3);
}

int16x8_t np_vshrq_n_s16_4(int16x8_t a)
{
	return vshrq_n_s16(a, 4);
}

int16x8_t np_vshrq_n_s16_5(int16x8_t a)
{
	return vshrq_n_s16(a, 5);
}

int16x8_t np_vshrq_n_s16_6(int16x8_t a)
{
	return vshrq_n_s16(a, 6);
}

int16x8_t np_vshrq_n_s16_7(int16x8_t a)
{
	return vshrq_n_s16(a, 7);
}

int16x8_t np_vshrq_n_s16_8(int16x8_t a)
{
	return vshrq_n_s16(a, 8);
}

int16x8_t np_vshrq_n_s16_9(int16x8_t a)
{
	return vshrq_n_s16(a, 9);
}

int16x8_t np_vshrq_n_s16_10(int16x8_t a)
{
	return vshrq_n_s16(a, 10);
}

int16x8_t np_vshrq_n_s16_11(int16x8_t a)
{
	return vshrq_n_s16(a, 11);
}

int16x8_t np_vshrq_n_s16_12(int16x8_t a)
{
	return vshrq_n_s16(a, 12);
}

int16x8_t np_vshrq_n_s16_13(int16x8_t a)
{
	return vshrq_n_s16(a, 13);
}

int16x8_t np_vshrq_n_s16_14(int16x8_t a)
{
	return vshrq_n_s16(a, 14);
}

int16x8_t np_vshrq_n_s16_15(int16x8_t a)
{
	return vshrq_n_s16(a, 15);
}

int16x8_t np_vshrq_n_s16_16(int16x8_t a)
{
	return vshrq_n_s16(a, 16);
}

int32x4_t np_vshrq_n_s32_1(int32x4_t a)
{
	return vshrq_n_s32(a, 1);
}

int32x4_t np_vshrq_n_s32_2(int32x4_t a)
{
	return vshrq_n_s32(a, 2);
}

int32x4_t np_vshrq_n_s32_3(int32x4_t a)
{
	return vshrq_n_s32(a, 3);
}

int32x4_t np_vshrq_n_s32_4(int32x4_t a)
{
	return vshrq_n_s32(a, 4);
}

int32x4_t np_vshrq_n_s32_5(int32x4_t a)
{
	return vshrq_n_s32(a, 5);
}

int32x4_t np_vshrq_n_s32_6(int32x4_t a)
{
	return vshrq_n_s32(a, 6);
}

int32x4_t np_vshrq_n_s32_7(int32x4_t a)
{
	return vshrq_n_s32(a, 7);
}

int32x4_t np_vshrq_n_s32_8(int32x4_t a)
{
	return vshrq_n_s32(a, 8);
}

int32x4_t np_vshrq_n_s32_9(int32x4_t a)
{
	return vshrq_n_s32(a, 9);
}

int32x4_t np_vshrq_n_s32_10(int32x4_t a)
{
	return vshrq_n_s32(a, 10);
}

int32x4_t np_vshrq_n_s32_11(int32x4_t a)
{
	return vshrq_n_s32(a, 11);
}

int32x4_t np_vshrq_n_s32_12(int32x4_t a)
{
	return vshrq_n_s32(a, 12);
}

int32x4_t np_vshrq_n_s32_13(int32x4_t a)
{
	return vshrq_n_s32(a, 13);
}

int32x4_t np_vshrq_n_s32_14(int32x4_t a)
{
	return vshrq_n_s32(a, 14);
}

int32x4_t np_vshrq_n_s32_15(int32x4_t a)
{
	return vshrq_n_s32(a, 15);
}

int32x4_t np_vshrq_n_s32_16(int32x4_t a)
{
	return vshrq_n_s32(a, 16);
}

int32x4_t np_vshrq_n_s32_17(int32x4_t a)
{
	return vshrq_n_s32(a, 17);
}

int32x4_t np_vshrq_n_s32_18(int32x4_t a)
{
	return vshrq_n_s32(a, 18);
}

int32x4_t np_vshrq_n_s32_19(int32x4_t a)
{
	return vshrq_n_s32(a, 19);
}

int32x4_t np_vshrq_n_s32_20(int32x4_t a)
{
	return vshrq_n_s32(a, 20);
}

int32x4_t np_vshrq_n_s32_21(int32x4_t a)
{
	return vshrq_n_s32(a, 21);
}

int32x4_t np_vshrq_n_s32_22(int32x4_t a)
{
	return vshrq_n_s32(a, 22);
}

int32x4_t np_vshrq_n_s32_23(int32x4_t a)
{
	return vshrq_n_s32(a, 23);
}

int32x4_t np_vshrq_n_s32_24(int32x4_t a)
{
	return vshrq_n_s32(a, 24);
}

int32x4_t np_vshrq_n_s32_25(int32x4_t a)
{
	return vshrq_n_s32(a, 25);
}

int32x4_t np_vshrq_n_s32_26(int32x4_t a)
{
	return vshrq_n_s32(a, 26);
}

int32x4_t np_vshrq_n_s32_27(int32x4_t a)
{
	return vshrq_n_s32(a, 27);
}

int32x4_t np_vshrq_n_s32_28(int32x4_t a)
{
	return vshrq_n_s32(a, 28);
}

int32x4_t np_vshrq_n_s32_29(int32x4_t a)
{
	return vshrq_n_s32(a, 29);
}

int32x4_t np_vshrq_n_s32_30(int32x4_t a)
{
	return vshrq_n_s32(a, 30);
}

int32x4_t np_vshrq_n_s32_31(int32x4_t a)
{
	return vshrq_n_s32(a, 31);
}

int32x4_t np_vshrq_n_s32_32(int32x4_t a)
{
	return vshrq_n_s32(a, 32);
}

int64x2_t np_vshrq_n_s64_1(int64x2_t a)
{
	return vshrq_n_s64(a, 1);
}

int64x2_t np_vshrq_n_s64_2(int64x2_t a)
{
	return vshrq_n_s64(a, 2);
}

int64x2_t np_vshrq_n_s64_3(int64x2_t a)
{
	return vshrq_n_s64(a, 3);
}

int64x2_t np_vshrq_n_s64_4(int64x2_t a)
{
	return vshrq_n_s64(a, 4);
}

int64x2_t np_vshrq_n_s64_5(int64x2_t a)
{
	return vshrq_n_s64(a, 5);
}

int64x2_t np_vshrq_n_s64_6(int64x2_t a)
{
	return vshrq_n_s64(a, 6);
}

int64x2_t np_vshrq_n_s64_7(int64x2_t a)
{
	return vshrq_n_s64(a, 7);
}

int64x2_t np_vshrq_n_s64_8(int64x2_t a)
{
	return vshrq_n_s64(a, 8);
}

int64x2_t np_vshrq_n_s64_9(int64x2_t a)
{
	return vshrq_n_s64(a, 9);
}

int64x2_t np_vshrq_n_s64_10(int64x2_t a)
{
	return vshrq_n_s64(a, 10);
}

int64x2_t np_vshrq_n_s64_11(int64x2_t a)
{
	return vshrq_n_s64(a, 11);
}

int64x2_t np_vshrq_n_s64_12(int64x2_t a)
{
	return vshrq_n_s64(a, 12);
}

int64x2_t np_vshrq_n_s64_13(int64x2_t a)
{
	return vshrq_n_s64(a, 13);
}

int64x2_t np_vshrq_n_s64_14(int64x2_t a)
{
	return vshrq_n_s64(a, 14);
}

int64x2_t np_vshrq_n_s64_15(int64x2_t a)
{
	return vshrq_n_s64(a, 15);
}

int64x2_t np_vshrq_n_s64_16(int64x2_t a)
{
	return vshrq_n_s64(a, 16);
}

int64x2_t np_vshrq_n_s64_17(int64x2_t a)
{
	return vshrq_n_s64(a, 17);
}

int64x2_t np_vshrq_n_s64_18(int64x2_t a)
{
	return vshrq_n_s64(a, 18);
}

int64x2_t np_vshrq_n_s64_19(int64x2_t a)
{
	return vshrq_n_s64(a, 19);
}

int64x2_t np_vshrq_n_s64_20(int64x2_t a)
{
	return vshrq_n_s64(a, 20);
}

int64x2_t np_vshrq_n_s64_21(int64x2_t a)
{
	return vshrq_n_s64(a, 21);
}

int64x2_t np_vshrq_n_s64_22(int64x2_t a)
{
	return vshrq_n_s64(a, 22);
}

int64x2_t np_vshrq_n_s64_23(int64x2_t a)
{
	return vshrq_n_s64(a, 23);
}

int64x2_t np_vshrq_n_s64_24(int64x2_t a)
{
	return vshrq_n_s64(a, 24);
}

int64x2_t np_vshrq_n_s64_25(int64x2_t a)
{
	return vshrq_n_s64(a, 25);
}

int64x2_t np_vshrq_n_s64_26(int64x2_t a)
{
	return vshrq_n_s64(a, 26);
}

int64x2_t np_vshrq_n_s64_27(int64x2_t a)
{
	return vshrq_n_s64(a, 27);
}

int64x2_t np_vshrq_n_s64_28(int64x2_t a)
{
	return vshrq_n_s64(a, 28);
}

int64x2_t np_vshrq_n_s64_29(int64x2_t a)
{
	return vshrq_n_s64(a, 29);
}

int64x2_t np_vshrq_n_s64_30(int64x2_t a)
{
	return vshrq_n_s64(a, 30);
}

int64x2_t np_vshrq_n_s64_31(int64x2_t a)
{
	return vshrq_n_s64(a, 31);
}

int64x2_t np_vshrq_n_s64_32(int64x2_t a)
{
	return vshrq_n_s64(a, 32);
}

int64x2_t np_vshrq_n_s64_33(int64x2_t a)
{
	return vshrq_n_s64(a, 33);
}

int64x2_t np_vshrq_n_s64_34(int64x2_t a)
{
	return vshrq_n_s64(a, 34);
}

int64x2_t np_vshrq_n_s64_35(int64x2_t a)
{
	return vshrq_n_s64(a, 35);
}

int64x2_t np_vshrq_n_s64_36(int64x2_t a)
{
	return vshrq_n_s64(a, 36);
}

int64x2_t np_vshrq_n_s64_37(int64x2_t a)
{
	return vshrq_n_s64(a, 37);
}

int64x2_t np_vshrq_n_s64_38(int64x2_t a)
{
	return vshrq_n_s64(a, 38);
}

int64x2_t np_vshrq_n_s64_39(int64x2_t a)
{
	return vshrq_n_s64(a, 39);
}

int64x2_t np_vshrq_n_s64_40(int64x2_t a)
{
	return vshrq_n_s64(a, 40);
}

int64x2_t np_vshrq_n_s64_41(int64x2_t a)
{
	return vshrq_n_s64(a, 41);
}

int64x2_t np_vshrq_n_s64_42(int64x2_t a)
{
	return vshrq_n_s64(a, 42);
}

int64x2_t np_vshrq_n_s64_43(int64x2_t a)
{
	return vshrq_n_s64(a, 43);
}

int64x2_t np_vshrq_n_s64_44(int64x2_t a)
{
	return vshrq_n_s64(a, 44);
}

int64x2_t np_vshrq_n_s64_45(int64x2_t a)
{
	return vshrq_n_s64(a, 45);
}

int64x2_t np_vshrq_n_s64_46(int64x2_t a)
{
	return vshrq_n_s64(a, 46);
}

int64x2_t np_vshrq_n_s64_47(int64x2_t a)
{
	return vshrq_n_s64(a, 47);
}

int64x2_t np_vshrq_n_s64_48(int64x2_t a)
{
	return vshrq_n_s64(a, 48);
}

int64x2_t np_vshrq_n_s64_49(int64x2_t a)
{
	return vshrq_n_s64(a, 49);
}

int64x2_t np_vshrq_n_s64_50(int64x2_t a)
{
	return vshrq_n_s64(a, 50);
}

int64x2_t np_vshrq_n_s64_51(int64x2_t a)
{
	return vshrq_n_s64(a, 51);
}

int64x2_t np_vshrq_n_s64_52(int64x2_t a)
{
	return vshrq_n_s64(a, 52);
}

int64x2_t np_vshrq_n_s64_53(int64x2_t a)
{
	return vshrq_n_s64(a, 53);
}

int64x2_t np_vshrq_n_s64_54(int64x2_t a)
{
	return vshrq_n_s64(a, 54);
}

int64x2_t np_vshrq_n_s64_55(int64x2_t a)
{
	return vshrq_n_s64(a, 55);
}

int64x2_t np_vshrq_n_s64_56(int64x2_t a)
{
	return vshrq_n_s64(a, 56);
}

int64x2_t np_vshrq_n_s64_57(int64x2_t a)
{
	return vshrq_n_s64(a, 57);
}

int64x2_t np_vshrq_n_s64_58(int64x2_t a)
{
	return vshrq_n_s64(a, 58);
}

int64x2_t np_vshrq_n_s64_59(int64x2_t a)
{
	return vshrq_n_s64(a, 59);
}

int64x2_t np_vshrq_n_s64_60(int64x2_t a)
{
	return vshrq_n_s64(a, 60);
}

int64x2_t np_vshrq_n_s64_61(int64x2_t a)
{
	return vshrq_n_s64(a, 61);
}

int64x2_t np_vshrq_n_s64_62(int64x2_t a)
{
	return vshrq_n_s64(a, 62);
}

int64x2_t np_vshrq_n_s64_63(int64x2_t a)
{
	return vshrq_n_s64(a, 63);
}

int64x2_t np_vshrq_n_s64_64(int64x2_t a)
{
	return vshrq_n_s64(a, 64);
}

uint8x16_t np_vshrq_n_u8_1(uint8x16_t a)
{
	return vshrq_n_u8(a, 1);
}

uint8x16_t np_vshrq_n_u8_2(uint8x16_t a)
{
	return vshrq_n_u8(a, 2);
}

uint8x16_t np_vshrq_n_u8_3(uint8x16_t a)
{
	return vshrq_n_u8(a, 3);
}

uint8x16_t np_vshrq_n_u8_4(uint8x16_t a)
{
	return vshrq_n_u8(a, 4);
}

uint8x16_t np_vshrq_n_u8_5(uint8x16_t a)
{
	return vshrq_n_u8(a, 5);
}

uint8x16_t np_vshrq_n_u8_6(uint8x16_t a)
{
	return vshrq_n_u8(a, 6);
}

uint8x16_t np_vshrq_n_u8_7(uint8x16_t a)
{
	return vshrq_n_u8(a, 7);
}

uint8x16_t np_vshrq_n_u8_8(uint8x16_t a)
{
	return vshrq_n_u8(a, 8);
}

uint16x8_t np_vshrq_n_u16_1(uint16x8_t a)
{
	return vshrq_n_u16(a, 1);
}

uint16x8_t np_vshrq_n_u16_2(uint16x8_t a)
{
	return vshrq_n_u16(a, 2);
}

uint16x8_t np_vshrq_n_u16_3(uint16x8_t a)
{
	return vshrq_n_u16(a, 3);
}

uint16x8_t np_vshrq_n_u16_4(uint16x8_t a)
{
	return vshrq_n_u16(a, 4);
}

uint16x8_t np_vshrq_n_u16_5(uint16x8_t a)
{
	return vshrq_n_u16(a, 5);
}

uint16x8_t np_vshrq_n_u16_6(uint16x8_t a)
{
	return vshrq_n_u16(a, 6);
}

uint16x8_t np_vshrq_n_u16_7(uint16x8_t a)
{
	return vshrq_n_u16(a, 7);
}

uint16x8_t np_vshrq_n_u16_8(uint16x8_t a)
{
	return vshrq_n_u16(a, 8);
}

uint16x8_t np_vshrq_n_u16_9(uint16x8_t a)
{
	return vshrq_n_u16(a, 9);
}

uint16x8_t np_vshrq_n_u16_10(uint16x8_t a)
{
	return vshrq_n_u16(a, 10);
}

uint16x8_t np_vshrq_n_u16_11(uint16x8_t a)
{
	return vshrq_n_u16(a, 11);
}

uint16x8_t np_vshrq_n_u16_12(uint16x8_t a)
{
	return vshrq_n_u16(a, 12);
}

uint16x8_t np_vshrq_n_u16_13(uint16x8_t a)
{
	return vshrq_n_u16(a, 13);
}

uint16x8_t np_vshrq_n_u16_14(uint16x8_t a)
{
	return vshrq_n_u16(a, 14);
}

uint16x8_t np_vshrq_n_u16_15(uint16x8_t a)
{
	return vshrq_n_u16(a, 15);
}

uint16x8_t np_vshrq_n_u16_16(uint16x8_t a)
{
	return vshrq_n_u16(a, 16);
}

uint32x4_t np_vshrq_n_u32_1(uint32x4_t a)
{
	return vshrq_n_u32(a, 1);
}

uint32x4_t np_vshrq_n_u32_2(uint32x4_t a)
{
	return vshrq_n_u32(a, 2);
}

uint32x4_t np_vshrq_n_u32_3(uint32x4_t a)
{
	return vshrq_n_u32(a, 3);
}

uint32x4_t np_vshrq_n_u32_4(uint32x4_t a)
{
	return vshrq_n_u32(a, 4);
}

uint32x4_t np_vshrq_n_u32_5(uint32x4_t a)
{
	return vshrq_n_u32(a, 5);
}

uint32x4_t np_vshrq_n_u32_6(uint32x4_t a)
{
	return vshrq_n_u32(a, 6);
}

uint32x4_t np_vshrq_n_u32_7(uint32x4_t a)
{
	return vshrq_n_u32(a, 7);
}

uint32x4_t np_vshrq_n_u32_8(uint32x4_t a)
{
	return vshrq_n_u32(a, 8);
}

uint32x4_t np_vshrq_n_u32_9(uint32x4_t a)
{
	return vshrq_n_u32(a, 9);
}

uint32x4_t np_vshrq_n_u32_10(uint32x4_t a)
{
	return vshrq_n_u32(a, 10);
}

uint32x4_t np_vshrq_n_u32_11(uint32x4_t a)
{
	return vshrq_n_u32(a, 11);
}

uint32x4_t np_vshrq_n_u32_12(uint32x4_t a)
{
	return vshrq_n_u32(a, 12);
}

uint32x4_t np_vshrq_n_u32_13(uint32x4_t a)
{
	return vshrq_n_u32(a, 13);
}

uint32x4_t np_vshrq_n_u32_14(uint32x4_t a)
{
	return vshrq_n_u32(a, 14);
}

uint32x4_t np_vshrq_n_u32_15(uint32x4_t a)
{
	return vshrq_n_u32(a, 15);
}

uint32x4_t np_vshrq_n_u32_16(uint32x4_t a)
{
	return vshrq_n_u32(a, 16);
}

uint32x4_t np_vshrq_n_u32_17(uint32x4_t a)
{
	return vshrq_n_u32(a, 17);
}

uint32x4_t np_vshrq_n_u32_18(uint32x4_t a)
{
	return vshrq_n_u32(a, 18);
}

uint32x4_t np_vshrq_n_u32_19(uint32x4_t a)
{
	return vshrq_n_u32(a, 19);
}

uint32x4_t np_vshrq_n_u32_20(uint32x4_t a)
{
	return vshrq_n_u32(a, 20);
}

uint32x4_t np_vshrq_n_u32_21(uint32x4_t a)
{
	return vshrq_n_u32(a, 21);
}

uint32x4_t np_vshrq_n_u32_22(uint32x4_t a)
{
	return vshrq_n_u32(a, 22);
}

uint32x4_t np_vshrq_n_u32_23(uint32x4_t a)
{
	return vshrq_n_u32(a, 23);
}

uint32x4_t np_vshrq_n_u32_24(uint32x4_t a)
{
	return vshrq_n_u32(a, 24);
}

uint32x4_t np_vshrq_n_u32_25(uint32x4_t a)
{
	return vshrq_n_u32(a, 25);
}

uint32x4_t np_vshrq_n_u32_26(uint32x4_t a)
{
	return vshrq_n_u32(a, 26);
}

uint32x4_t np_vshrq_n_u32_27(uint32x4_t a)
{
	return vshrq_n_u32(a, 27);
}

uint32x4_t np_vshrq_n_u32_28(uint32x4_t a)
{
	return vshrq_n_u32(a, 28);
}

uint32x4_t np_vshrq_n_u32_29(uint32x4_t a)
{
	return vshrq_n_u32(a, 29);
}

uint32x4_t np_vshrq_n_u32_30(uint32x4_t a)
{
	return vshrq_n_u32(a, 30);
}

uint32x4_t np_vshrq_n_u32_31(uint32x4_t a)
{
	return vshrq_n_u32(a, 31);
}

uint32x4_t np_vshrq_n_u32_32(uint32x4_t a)
{
	return vshrq_n_u32(a, 32);
}

uint64x2_t np_vshrq_n_u64_1(uint64x2_t a)
{
	return vshrq_n_u64(a, 1);
}

uint64x2_t np_vshrq_n_u64_2(uint64x2_t a)
{
	return vshrq_n_u64(a, 2);
}

uint64x2_t np_vshrq_n_u64_3(uint64x2_t a)
{
	return vshrq_n_u64(a, 3);
}

uint64x2_t np_vshrq_n_u64_4(uint64x2_t a)
{
	return vshrq_n_u64(a, 4);
}

uint64x2_t np_vshrq_n_u64_5(uint64x2_t a)
{
	return vshrq_n_u64(a, 5);
}

uint64x2_t np_vshrq_n_u64_6(uint64x2_t a)
{
	return vshrq_n_u64(a, 6);
}

uint64x2_t np_vshrq_n_u64_7(uint64x2_t a)
{
	return vshrq_n_u64(a, 7);
}

uint64x2_t np_vshrq_n_u64_8(uint64x2_t a)
{
	return vshrq_n_u64(a, 8);
}

uint64x2_t np_vshrq_n_u64_9(uint64x2_t a)
{
	return vshrq_n_u64(a, 9);
}

uint64x2_t np_vshrq_n_u64_10(uint64x2_t a)
{
	return vshrq_n_u64(a, 10);
}

uint64x2_t np_vshrq_n_u64_11(uint64x2_t a)
{
	return vshrq_n_u64(a, 11);
}

uint64x2_t np_vshrq_n_u64_12(uint64x2_t a)
{
	return vshrq_n_u64(a, 12);
}

uint64x2_t np_vshrq_n_u64_13(uint64x2_t a)
{
	return vshrq_n_u64(a, 13);
}

uint64x2_t np_vshrq_n_u64_14(uint64x2_t a)
{
	return vshrq_n_u64(a, 14);
}

uint64x2_t np_vshrq_n_u64_15(uint64x2_t a)
{
	return vshrq_n_u64(a, 15);
}

uint64x2_t np_vshrq_n_u64_16(uint64x2_t a)
{
	return vshrq_n_u64(a, 16);
}

uint64x2_t np_vshrq_n_u64_17(uint64x2_t a)
{
	return vshrq_n_u64(a, 17);
}

uint64x2_t np_vshrq_n_u64_18(uint64x2_t a)
{
	return vshrq_n_u64(a, 18);
}

uint64x2_t np_vshrq_n_u64_19(uint64x2_t a)
{
	return vshrq_n_u64(a, 19);
}

uint64x2_t np_vshrq_n_u64_20(uint64x2_t a)
{
	return vshrq_n_u64(a, 20);
}

uint64x2_t np_vshrq_n_u64_21(uint64x2_t a)
{
	return vshrq_n_u64(a, 21);
}

uint64x2_t np_vshrq_n_u64_22(uint64x2_t a)
{
	return vshrq_n_u64(a, 22);
}

uint64x2_t np_vshrq_n_u64_23(uint64x2_t a)
{
	return vshrq_n_u64(a, 23);
}

uint64x2_t np_vshrq_n_u64_24(uint64x2_t a)
{
	return vshrq_n_u64(a, 24);
}

uint64x2_t np_vshrq_n_u64_25(uint64x2_t a)
{
	return vshrq_n_u64(a, 25);
}

uint64x2_t np_vshrq_n_u64_26(uint64x2_t a)
{
	return vshrq_n_u64(a, 26);
}

uint64x2_t np_vshrq_n_u64_27(uint64x2_t a)
{
	return vshrq_n_u64(a, 27);
}

uint64x2_t np_vshrq_n_u64_28(uint64x2_t a)
{
	return vshrq_n_u64(a, 28);
}

uint64x2_t np_vshrq_n_u64_29(uint64x2_t a)
{
	return vshrq_n_u64(a, 29);
}

uint64x2_t np_vshrq_n_u64_30(uint64x2_t a)
{
	return vshrq_n_u64(a, 30);
}

uint64x2_t np_vshrq_n_u64_31(uint64x2_t a)
{
	return vshrq_n_u64(a, 31);
}

uint64x2_t np_vshrq_n_u64_32(uint64x2_t a)
{
	return vshrq_n_u64(a, 32);
}

uint64x2_t np_vshrq_n_u64_33(uint64x2_t a)
{
	return vshrq_n_u64(a, 33);
}

uint64x2_t np_vshrq_n_u64_34(uint64x2_t a)
{
	return vshrq_n_u64(a, 34);
}

uint64x2_t np_vshrq_n_u64_35(uint64x2_t a)
{
	return vshrq_n_u64(a, 35);
}

uint64x2_t np_vshrq_n_u64_36(uint64x2_t a)
{
	return vshrq_n_u64(a, 36);
}

uint64x2_t np_vshrq_n_u64_37(uint64x2_t a)
{
	return vshrq_n_u64(a, 37);
}

uint64x2_t np_vshrq_n_u64_38(uint64x2_t a)
{
	return vshrq_n_u64(a, 38);
}

uint64x2_t np_vshrq_n_u64_39(uint64x2_t a)
{
	return vshrq_n_u64(a, 39);
}

uint64x2_t np_vshrq_n_u64_40(uint64x2_t a)
{
	return vshrq_n_u64(a, 40);
}

uint64x2_t np_vshrq_n_u64_41(uint64x2_t a)
{
	return vshrq_n_u64(a, 41);
}

uint64x2_t np_vshrq_n_u64_42(uint64x2_t a)
{
	return vshrq_n_u64(a, 42);
}

uint64x2_t np_vshrq_n_u64_43(uint64x2_t a)
{
	return vshrq_n_u64(a, 43);
}

uint64x2_t np_vshrq_n_u64_44(uint64x2_t a)
{
	return vshrq_n_u64(a, 44);
}

uint64x2_t np_vshrq_n_u64_45(uint64x2_t a)
{
	return vshrq_n_u64(a, 45);
}

uint64x2_t np_vshrq_n_u64_46(uint64x2_t a)
{
	return vshrq_n_u64(a, 46);
}

uint64x2_t np_vshrq_n_u64_47(uint64x2_t a)
{
	return vshrq_n_u64(a, 47);
}

uint64x2_t np_vshrq_n_u64_48(uint64x2_t a)
{
	return vshrq_n_u64(a, 48);
}

uint64x2_t np_vshrq_n_u64_49(uint64x2_t a)
{
	return vshrq_n_u64(a, 49);
}

uint64x2_t np_vshrq_n_u64_50(uint64x2_t a)
{
	return vshrq_n_u64(a, 50);
}

uint64x2_t np_vshrq_n_u64_51(uint64x2_t a)
{
	return vshrq_n_u64(a, 51);
}

uint64x2_t np_vshrq_n_u64_52(uint64x2_t a)
{
	return vshrq_n_u64(a, 52);
}

uint64x2_t np_vshrq_n_u64_53(uint64x2_t a)
{
	return vshrq_n_u64(a, 53);
}

uint64x2_t np_vshrq_n_u64_54(uint64x2_t a)
{
	return vshrq_n_u64(a, 54);
}

uint64x2_t np_vshrq_n_u64_55(uint64x2_t a)
{
	return vshrq_n_u64(a, 55);
}

uint64x2_t np_vshrq_n_u64_56(uint64x2_t a)
{
	return vshrq_n_u64(a, 56);
}

uint64x2_t np_vshrq_n_u64_57(uint64x2_t a)
{
	return vshrq_n_u64(a, 57);
}

uint64x2_t np_vshrq_n_u64_58(uint64x2_t a)
{
	return vshrq_n_u64(a, 58);
}

uint64x2_t np_vshrq_n_u64_59(uint64x2_t a)
{
	return vshrq_n_u64(a, 59);
}

uint64x2_t np_vshrq_n_u64_60(uint64x2_t a)
{
	return vshrq_n_u64(a, 60);
}

uint64x2_t np_vshrq_n_u64_61(uint64x2_t a)
{
	return vshrq_n_u64(a, 61);
}

uint64x2_t np_vshrq_n_u64_62(uint64x2_t a)
{
	return vshrq_n_u64(a, 62);
}

uint64x2_t np_vshrq_n_u64_63(uint64x2_t a)
{
	return vshrq_n_u64(a, 63);
}

uint64x2_t np_vshrq_n_u64_64(uint64x2_t a)
{
	return vshrq_n_u64(a, 64);
}

int8x16_t np_vshlq_n_s8_0(int8x16_t a)
{
	return vshlq_n_s8(a, 0);
}

int8x16_t np_vshlq_n_s8_1(int8x16_t a)
{
	return vshlq_n_s8(a, 1);
}

int8x16_t np_vshlq_n_s8_2(int8x16_t a)
{
	return vshlq_n_s8(a, 2);
}

int8x16_t np_vshlq_n_s8_3(int8x16_t a)
{
	return vshlq_n_s8(a, 3);
}

int8x16_t np_vshlq_n_s8_4(int8x16_t a)
{
	return vshlq_n_s8(a, 4);
}

int8x16_t np_vshlq_n_s8_5(int8x16_t a)
{
	return vshlq_n_s8(a, 5);
}

int8x16_t np_vshlq_n_s8_6(int8x16_t a)
{
	return vshlq_n_s8(a, 6);
}

int8x16_t np_vshlq_n_s8_7(int8x16_t a)
{
	return vshlq_n_s8(a, 7);
}

int16x8_t np_vshlq_n_s16_0(int16x8_t a)
{
	return vshlq_n_s16(a, 0);
}

int16x8_t np_vshlq_n_s16_1(int16x8_t a)
{
	return vshlq_n_s16(a, 1);
}

int16x8_t np_vshlq_n_s16_2(int16x8_t a)
{
	return vshlq_n_s16(a, 2);
}

int16x8_t np_vshlq_n_s16_3(int16x8_t a)
{
	return vshlq_n_s16(a, 3);
}

int16x8_t np_vshlq_n_s16_4(int16x8_t a)
{
	return vshlq_n_s16(a, 4);
}

int16x8_t np_vshlq_n_s16_5(int16x8_t a)
{
	return vshlq_n_s16(a, 5);
}

int16x8_t np_vshlq_n_s16_6(int16x8_t a)
{
	return vshlq_n_s16(a, 6);
}

int16x8_t np_vshlq_n_s16_7(int16x8_t a)
{
	return vshlq_n_s16(a, 7);
}

int16x8_t np_vshlq_n_s16_8(int16x8_t a)
{
	return vshlq_n_s16(a, 8);
}

int16x8_t np_vshlq_n_s16_9(int16x8_t a)
{
	return vshlq_n_s16(a, 9);
}

int16x8_t np_vshlq_n_s16_10(int16x8_t a)
{
	return vshlq_n_s16(a, 10);
}

int16x8_t np_vshlq_n_s16_11(int16x8_t a)
{
	return vshlq_n_s16(a, 11);
}

int16x8_t np_vshlq_n_s16_12(int16x8_t a)
{
	return vshlq_n_s16(a, 12);
}

int16x8_t np_vshlq_n_s16_13(int16x8_t a)
{
	return vshlq_n_s16(a, 13);
}

int16x8_t np_vshlq_n_s16_14(int16x8_t a)
{
	return vshlq_n_s16(a, 14);
}

int16x8_t np_vshlq_n_s16_15(int16x8_t a)
{
	return vshlq_n_s16(a, 15);
}

int32x4_t np_vshlq_n_s32_0(int32x4_t a)
{
	return vshlq_n_s32(a, 0);
}

int32x4_t np_vshlq_n_s32_1(int32x4_t a)
{
	return vshlq_n_s32(a, 1);
}

int32x4_t np_vshlq_n_s32_2(int32x4_t a)
{
	return vshlq_n_s32(a, 2);
}

int32x4_t np_vshlq_n_s32_3(int32x4_t a)
{
	return vshlq_n_s32(a, 3);
}

int32x4_t np_vshlq_n_s32_4(int32x4_t a)
{
	return vshlq_n_s32(a, 4);
}

int32x4_t np_vshlq_n_s32_5(int32x4_t a)
{
	return vshlq_n_s32(a, 5);
}

int32x4_t np_vshlq_n_s32_6(int32x4_t a)
{
	return vshlq_n_s32(a, 6);
}

int32x4_t np_vshlq_n_s32_7(int32x4_t a)
{
	return vshlq_n_s32(a, 7);
}

int32x4_t np_vshlq_n_s32_8(int32x4_t a)
{
	return vshlq_n_s32(a, 8);
}

int32x4_t np_vshlq_n_s32_9(int32x4_t a)
{
	return vshlq_n_s32(a, 9);
}

int32x4_t np_vshlq_n_s32_10(int32x4_t a)
{
	return vshlq_n_s32(a, 10);
}

int32x4_t np_vshlq_n_s32_11(int32x4_t a)
{
	return vshlq_n_s32(a, 11);
}

int32x4_t np_vshlq_n_s32_12(int32x4_t a)
{
	return vshlq_n_s32(a, 12);
}

int32x4_t np_vshlq_n_s32_13(int32x4_t a)
{
	return vshlq_n_s32(a, 13);
}

int32x4_t np_vshlq_n_s32_14(int32x4_t a)
{
	return vshlq_n_s32(a, 14);
}

int32x4_t np_vshlq_n_s32_15(int32x4_t a)
{
	return vshlq_n_s32(a, 15);
}

int32x4_t np_vshlq_n_s32_16(int32x4_t a)
{
	return vshlq_n_s32(a, 16);
}

int32x4_t np_vshlq_n_s32_17(int32x4_t a)
{
	return vshlq_n_s32(a, 17);
}

int32x4_t np_vshlq_n_s32_18(int32x4_t a)
{
	return vshlq_n_s32(a, 18);
}

int32x4_t np_vshlq_n_s32_19(int32x4_t a)
{
	return vshlq_n_s32(a, 19);
}

int32x4_t np_vshlq_n_s32_20(int32x4_t a)
{
	return vshlq_n_s32(a, 20);
}

int32x4_t np_vshlq_n_s32_21(int32x4_t a)
{
	return vshlq_n_s32(a, 21);
}

int32x4_t np_vshlq_n_s32_22(int32x4_t a)
{
	return vshlq_n_s32(a, 22);
}

int32x4_t np_vshlq_n_s32_23(int32x4_t a)
{
	return vshlq_n_s32(a, 23);
}

int32x4_t np_vshlq_n_s32_24(int32x4_t a)
{
	return vshlq_n_s32(a, 24);
}

int32x4_t np_vshlq_n_s32_25(int32x4_t a)
{
	return vshlq_n_s32(a, 25);
}

int32x4_t np_vshlq_n_s32_26(int32x4_t a)
{
	return vshlq_n_s32(a, 26);
}

int32x4_t np_vshlq_n_s32_27(int32x4_t a)
{
	return vshlq_n_s32(a, 27);
}

int32x4_t np_vshlq_n_s32_28(int32x4_t a)
{
	return vshlq_n_s32(a, 28);
}

int32x4_t np_vshlq_n_s32_29(int32x4_t a)
{
	return vshlq_n_s32(a, 29);
}

int32x4_t np_vshlq_n_s32_30(int32x4_t a)
{
	return vshlq_n_s32(a, 30);
}

int32x4_t np_vshlq_n_s32_31(int32x4_t a)
{
	return vshlq_n_s32(a, 31);
}

int64x2_t np_vshlq_n_s64_0(int64x2_t a)
{
	return vshlq_n_s64(a, 0);
}

int64x2_t np_vshlq_n_s64_1(int64x2_t a)
{
	return vshlq_n_s64(a, 1);
}

int64x2_t np_vshlq_n_s64_2(int64x2_t a)
{
	return vshlq_n_s64(a, 2);
}

int64x2_t np_vshlq_n_s64_3(int64x2_t a)
{
	return vshlq_n_s64(a, 3);
}

int64x2_t np_vshlq_n_s64_4(int64x2_t a)
{
	return vshlq_n_s64(a, 4);
}

int64x2_t np_vshlq_n_s64_5(int64x2_t a)
{
	return vshlq_n_s64(a, 5);
}

int64x2_t np_vshlq_n_s64_6(int64x2_t a)
{
	return vshlq_n_s64(a, 6);
}

int64x2_t np_vshlq_n_s64_7(int64x2_t a)
{
	return vshlq_n_s64(a, 7);
}

int64x2_t np_vshlq_n_s64_8(int64x2_t a)
{
	return vshlq_n_s64(a, 8);
}

int64x2_t np_vshlq_n_s64_9(int64x2_t a)
{
	return vshlq_n_s64(a, 9);
}

int64x2_t np_vshlq_n_s64_10(int64x2_t a)
{
	return vshlq_n_s64(a, 10);
}

int64x2_t np_vshlq_n_s64_11(int64x2_t a)
{
	return vshlq_n_s64(a, 11);
}

int64x2_t np_vshlq_n_s64_12(int64x2_t a)
{
	return vshlq_n_s64(a, 12);
}

int64x2_t np_vshlq_n_s64_13(int64x2_t a)
{
	return vshlq_n_s64(a, 13);
}

int64x2_t np_vshlq_n_s64_14(int64x2_t a)
{
	return vshlq_n_s64(a, 14);
}

int64x2_t np_vshlq_n_s64_15(int64x2_t a)
{
	return vshlq_n_s64(a, 15);
}

int64x2_t np_vshlq_n_s64_16(int64x2_t a)
{
	return vshlq_n_s64(a, 16);
}

int64x2_t np_vshlq_n_s64_17(int64x2_t a)
{
	return vshlq_n_s64(a, 17);
}

int64x2_t np_vshlq_n_s64_18(int64x2_t a)
{
	return vshlq_n_s64(a, 18);
}

int64x2_t np_vshlq_n_s64_19(int64x2_t a)
{
	return vshlq_n_s64(a, 19);
}

int64x2_t np_vshlq_n_s64_20(int64x2_t a)
{
	return vshlq_n_s64(a, 20);
}

int64x2_t np_vshlq_n_s64_21(int64x2_t a)
{
	return vshlq_n_s64(a, 21);
}

int64x2_t np_vshlq_n_s64_22(int64x2_t a)
{
	return vshlq_n_s64(a, 22);
}

int64x2_t np_vshlq_n_s64_23(int64x2_t a)
{
	return vshlq_n_s64(a, 23);
}

int64x2_t np_vshlq_n_s64_24(int64x2_t a)
{
	return vshlq_n_s64(a, 24);
}

int64x2_t np_vshlq_n_s64_25(int64x2_t a)
{
	return vshlq_n_s64(a, 25);
}

int64x2_t np_vshlq_n_s64_26(int64x2_t a)
{
	return vshlq_n_s64(a, 26);
}

int64x2_t np_vshlq_n_s64_27(int64x2_t a)
{
	return vshlq_n_s64(a, 27);
}

int64x2_t np_vshlq_n_s64_28(int64x2_t a)
{
	return vshlq_n_s64(a, 28);
}

int64x2_t np_vshlq_n_s64_29(int64x2_t a)
{
	return vshlq_n_s64(a, 29);
}

int64x2_t np_vshlq_n_s64_30(int64x2_t a)
{
	return vshlq_n_s64(a, 30);
}

int64x2_t np_vshlq_n_s64_31(int64x2_t a)
{
	return vshlq_n_s64(a, 31);
}

int64x2_t np_vshlq_n_s64_32(int64x2_t a)
{
	return vshlq_n_s64(a, 32);
}

int64x2_t np_vshlq_n_s64_33(int64x2_t a)
{
	return vshlq_n_s64(a, 33);
}

int64x2_t np_vshlq_n_s64_34(int64x2_t a)
{
	return vshlq_n_s64(a, 34);
}

int64x2_t np_vshlq_n_s64_35(int64x2_t a)
{
	return vshlq_n_s64(a, 35);
}

int64x2_t np_vshlq_n_s64_36(int64x2_t a)
{
	return vshlq_n_s64(a, 36);
}

int64x2_t np_vshlq_n_s64_37(int64x2_t a)
{
	return vshlq_n_s64(a, 37);
}

int64x2_t np_vshlq_n_s64_38(int64x2_t a)
{
	return vshlq_n_s64(a, 38);
}

int64x2_t np_vshlq_n_s64_39(int64x2_t a)
{
	return vshlq_n_s64(a, 39);
}

int64x2_t np_vshlq_n_s64_40(int64x2_t a)
{
	return vshlq_n_s64(a, 40);
}

int64x2_t np_vshlq_n_s64_41(int64x2_t a)
{
	return vshlq_n_s64(a, 41);
}

int64x2_t np_vshlq_n_s64_42(int64x2_t a)
{
	return vshlq_n_s64(a, 42);
}

int64x2_t np_vshlq_n_s64_43(int64x2_t a)
{
	return vshlq_n_s64(a, 43);
}

int64x2_t np_vshlq_n_s64_44(int64x2_t a)
{
	return vshlq_n_s64(a, 44);
}

int64x2_t np_vshlq_n_s64_45(int64x2_t a)
{
	return vshlq_n_s64(a, 45);
}

int64x2_t np_vshlq_n_s64_46(int64x2_t a)
{
	return vshlq_n_s64(a, 46);
}

int64x2_t np_vshlq_n_s64_47(int64x2_t a)
{
	return vshlq_n_s64(a, 47);
}

int64x2_t np_vshlq_n_s64_48(int64x2_t a)
{
	return vshlq_n_s64(a, 48);
}

int64x2_t np_vshlq_n_s64_49(int64x2_t a)
{
	return vshlq_n_s64(a, 49);
}

int64x2_t np_vshlq_n_s64_50(int64x2_t a)
{
	return vshlq_n_s64(a, 50);
}

int64x2_t np_vshlq_n_s64_51(int64x2_t a)
{
	return vshlq_n_s64(a, 51);
}

int64x2_t np_vshlq_n_s64_52(int64x2_t a)
{
	return vshlq_n_s64(a, 52);
}

int64x2_t np_vshlq_n_s64_53(int64x2_t a)
{
	return vshlq_n_s64(a, 53);
}

int64x2_t np_vshlq_n_s64_54(int64x2_t a)
{
	return vshlq_n_s64(a, 54);
}

int64x2_t np_vshlq_n_s64_55(int64x2_t a)
{
	return vshlq_n_s64(a, 55);
}

int64x2_t np_vshlq_n_s64_56(int64x2_t a)
{
	return vshlq_n_s64(a, 56);
}

int64x2_t np_vshlq_n_s64_57(int64x2_t a)
{
	return vshlq_n_s64(a, 57);
}

int64x2_t np_vshlq_n_s64_58(int64x2_t a)
{
	return vshlq_n_s64(a, 58);
}

int64x2_t np_vshlq_n_s64_59(int64x2_t a)
{
	return vshlq_n_s64(a, 59);
}

int64x2_t np_vshlq_n_s64_60(int64x2_t a)
{
	return vshlq_n_s64(a, 60);
}

int64x2_t np_vshlq_n_s64_61(int64x2_t a)
{
	return vshlq_n_s64(a, 61);
}

int64x2_t np_vshlq_n_s64_62(int64x2_t a)
{
	return vshlq_n_s64(a, 62);
}

int64x2_t np_vshlq_n_s64_63(int64x2_t a)
{
	return vshlq_n_s64(a, 63);
}

uint8x16_t np_vshlq_n_u8_0(uint8x16_t a)
{
	return vshlq_n_u8(a, 0);
}

uint8x16_t np_vshlq_n_u8_1(uint8x16_t a)
{
	return vshlq_n_u8(a, 1);
}

uint8x16_t np_vshlq_n_u8_2(uint8x16_t a)
{
	return vshlq_n_u8(a, 2);
}

uint8x16_t np_vshlq_n_u8_3(uint8x16_t a)
{
	return vshlq_n_u8(a, 3);
}

uint8x16_t np_vshlq_n_u8_4(uint8x16_t a)
{
	return vshlq_n_u8(a, 4);
}

uint8x16_t np_vshlq_n_u8_5(uint8x16_t a)
{
	return vshlq_n_u8(a, 5);
}

uint8x16_t np_vshlq_n_u8_6(uint8x16_t a)
{
	return vshlq_n_u8(a, 6);
}

uint8x16_t np_vshlq_n_u8_7(uint8x16_t a)
{
	return vshlq_n_u8(a, 7);
}

uint16x8_t np_vshlq_n_u16_0(uint16x8_t a)
{
	return vshlq_n_u16(a, 0);
}

uint16x8_t np_vshlq_n_u16_1(uint16x8_t a)
{
	return vshlq_n_u16(a, 1);
}

uint16x8_t np_vshlq_n_u16_2(uint16x8_t a)
{
	return vshlq_n_u16(a, 2);
}

uint16x8_t np_vshlq_n_u16_3(uint16x8_t a)
{
	return vshlq_n_u16(a, 3);
}

uint16x8_t np_vshlq_n_u16_4(uint16x8_t a)
{
	return vshlq_n_u16(a, 4);
}

uint16x8_t np_vshlq_n_u16_5(uint16x8_t a)
{
	return vshlq_n_u16(a, 5);
}

uint16x8_t np_vshlq_n_u16_6(uint16x8_t a)
{
	return vshlq_n_u16(a, 6);
}

uint16x8_t np_vshlq_n_u16_7(uint16x8_t a)
{
	return vshlq_n_u16(a, 7);
}

uint16x8_t np_vshlq_n_u16_8(uint16x8_t a)
{
	return vshlq_n_u16(a, 8);
}

uint16x8_t np_vshlq_n_u16_9(uint16x8_t a)
{
	return vshlq_n_u16(a, 9);
}

uint16x8_t np_vshlq_n_u16_10(uint16x8_t a)
{
	return vshlq_n_u16(a, 10);
}

uint16x8_t np_vshlq_n_u16_11(uint16x8_t a)
{
	return vshlq_n_u16(a, 11);
}

uint16x8_t np_vshlq_n_u16_12(uint16x8_t a)
{
	return vshlq_n_u16(a, 12);
}

uint16x8_t np_vshlq_n_u16_13(uint16x8_t a)
{
	return vshlq_n_u16(a, 13);
}

uint16x8_t np_vshlq_n_u16_14(uint16x8_t a)
{
	return vshlq_n_u16(a, 14);
}

uint16x8_t np_vshlq_n_u16_15(uint16x8_t a)
{
	return vshlq_n_u16(a, 15);
}

uint32x4_t np_vshlq_n_u32_0(uint32x4_t a)
{
	return vshlq_n_u32(a, 0);
}

uint32x4_t np_vshlq_n_u32_1(uint32x4_t a)
{
	return vshlq_n_u32(a, 1);
}

uint32x4_t np_vshlq_n_u32_2(uint32x4_t a)
{
	return vshlq_n_u32(a, 2);
}

uint32x4_t np_vshlq_n_u32_3(uint32x4_t a)
{
	return vshlq_n_u32(a, 3);
}

uint32x4_t np_vshlq_n_u32_4(uint32x4_t a)
{
	return vshlq_n_u32(a, 4);
}

uint32x4_t np_vshlq_n_u32_5(uint32x4_t a)
{
	return vshlq_n_u32(a, 5);
}

uint32x4_t np_vshlq_n_u32_6(uint32x4_t a)
{
	return vshlq_n_u32(a, 6);
}

uint32x4_t np_vshlq_n_u32_7(uint32x4_t a)
{
	return vshlq_n_u32(a, 7);
}

uint32x4_t np_vshlq_n_u32_8(uint32x4_t a)
{
	return vshlq_n_u32(a, 8);
}

uint32x4_t np_vshlq_n_u32_9(uint32x4_t a)
{
	return vshlq_n_u32(a, 9);
}

uint32x4_t np_vshlq_n_u32_10(uint32x4_t a)
{
	return vshlq_n_u32(a, 10);
}

uint32x4_t np_vshlq_n_u32_11(uint32x4_t a)
{
	return vshlq_n_u32(a, 11);
}

uint32x4_t np_vshlq_n_u32_12(uint32x4_t a)
{
	return vshlq_n_u32(a, 12);
}

uint32x4_t np_vshlq_n_u32_13(uint32x4_t a)
{
	return vshlq_n_u32(a, 13);
}

uint32x4_t np_vshlq_n_u32_14(uint32x4_t a)
{
	return vshlq_n_u32(a, 14);
}

uint32x4_t np_vshlq_n_u32_15(uint32x4_t a)
{
	return vshlq_n_u32(a, 15);
}

uint32x4_t np_vshlq_n_u32_16(uint32x4_t a)
{
	return vshlq_n_u32(a, 16);
}

uint32x4_t np_vshlq_n_u32_17(uint32x4_t a)
{
	return vshlq_n_u32(a, 17);
}

uint32x4_t np_vshlq_n_u32_18(uint32x4_t a)
{
	return vshlq_n_u32(a, 18);
}

uint32x4_t np_vshlq_n_u32_19(uint32x4_t a)
{
	return vshlq_n_u32(a, 19);
}

uint32x4_t np_vshlq_n_u32_20(uint32x4_t a)
{
	return vshlq_n_u32(a, 20);
}

uint32x4_t np_vshlq_n_u32_21(uint32x4_t a)
{
	return vshlq_n_u32(a, 21);
}

uint32x4_t np_vshlq_n_u32_22(uint32x4_t a)
{
	return vshlq_n_u32(a, 22);
}

uint32x4_t np_vshlq_n_u32_23(uint32x4_t a)
{
	return vshlq_n_u32(a, 23);
}

uint32x4_t np_vshlq_n_u32_24(uint32x4_t a)
{
	return vshlq_n_u32(a, 24);
}

uint32x4_t np_vshlq_n_u32_25(uint32x4_t a)
{
	return vshlq_n_u32(a, 25);
}

uint32x4_t np_vshlq_n_u32_26(uint32x4_t a)
{
	return vshlq_n_u32(a, 26);
}

uint32x4_t np_vshlq_n_u32_27(uint32x4_t a)
{
	return vshlq_n_u32(a, 27);
}

uint32x4_t np_vshlq_n_u32_28(uint32x4_t a)
{
	return vshlq_n_u32(a, 28);
}

uint32x4_t np_vshlq_n_u32_29(uint32x4_t a)
{
	return vshlq_n_u32(a, 29);
}

uint32x4_t np_vshlq_n_u32_30(uint32x4_t a)
{
	return vshlq_n_u32(a, 30);
}

uint32x4_t np_vshlq_n_u32_31(uint32x4_t a)
{
	return vshlq_n_u32(a, 31);
}

uint64x2_t np_vshlq_n_u64_0(uint64x2_t a)
{
	return vshlq_n_u64(a, 0);
}

uint64x2_t np_vshlq_n_u64_1(uint64x2_t a)
{
	return vshlq_n_u64(a, 1);
}

uint64x2_t np_vshlq_n_u64_2(uint64x2_t a)
{
	return vshlq_n_u64(a, 2);
}

uint64x2_t np_vshlq_n_u64_3(uint64x2_t a)
{
	return vshlq_n_u64(a, 3);
}

uint64x2_t np_vshlq_n_u64_4(uint64x2_t a)
{
	return vshlq_n_u64(a, 4);
}

uint64x2_t np_vshlq_n_u64_5(uint64x2_t a)
{
	return vshlq_n_u64(a, 5);
}

uint64x2_t np_vshlq_n_u64_6(uint64x2_t a)
{
	return vshlq_n_u64(a, 6);
}

uint64x2_t np_vshlq_n_u64_7(uint64x2_t a)
{
	return vshlq_n_u64(a, 7);
}

uint64x2_t np_vshlq_n_u64_8(uint64x2_t a)
{
	return vshlq_n_u64(a, 8);
}

uint64x2_t np_vshlq_n_u64_9(uint64x2_t a)
{
	return vshlq_n_u64(a, 9);
}

uint64x2_t np_vshlq_n_u64_10(uint64x2_t a)
{
	return vshlq_n_u64(a, 10);
}

uint64x2_t np_vshlq_n_u64_11(uint64x2_t a)
{
	return vshlq_n_u64(a, 11);
}

uint64x2_t np_vshlq_n_u64_12(uint64x2_t a)
{
	return vshlq_n_u64(a, 12);
}

uint64x2_t np_vshlq_n_u64_13(uint64x2_t a)
{
	return vshlq_n_u64(a, 13);
}

uint64x2_t np_vshlq_n_u64_14(uint64x2_t a)
{
	return vshlq_n_u64(a, 14);
}

uint64x2_t np_vshlq_n_u64_15(uint64x2_t a)
{
	return vshlq_n_u64(a, 15);
}

uint64x2_t np_vshlq_n_u64_16(uint64x2_t a)
{
	return vshlq_n_u64(a, 16);
}

uint64x2_t np_vshlq_n_u64_17(uint64x2_t a)
{
	return vshlq_n_u64(a, 17);
}

uint64x2_t np_vshlq_n_u64_18(uint64x2_t a)
{
	return vshlq_n_u64(a, 18);
}

uint64x2_t np_vshlq_n_u64_19(uint64x2_t a)
{
	return vshlq_n_u64(a, 19);
}

uint64x2_t np_vshlq_n_u64_20(uint64x2_t a)
{
	return vshlq_n_u64(a, 20);
}

uint64x2_t np_vshlq_n_u64_21(uint64x2_t a)
{
	return vshlq_n_u64(a, 21);
}

uint64x2_t np_vshlq_n_u64_22(uint64x2_t a)
{
	return vshlq_n_u64(a, 22);
}

uint64x2_t np_vshlq_n_u64_23(uint64x2_t a)
{
	return vshlq_n_u64(a, 23);
}

uint64x2_t np_vshlq_n_u64_24(uint64x2_t a)
{
	return vshlq_n_u64(a, 24);
}

uint64x2_t np_vshlq_n_u64_25(uint64x2_t a)
{
	return vshlq_n_u64(a, 25);
}

uint64x2_t np_vshlq_n_u64_26(uint64x2_t a)
{
	return vshlq_n_u64(a, 26);
}

uint64x2_t np_vshlq_n_u64_27(uint64x2_t a)
{
	return vshlq_n_u64(a, 27);
}

uint64x2_t np_vshlq_n_u64_28(uint64x2_t a)
{
	return vshlq_n_u64(a, 28);
}

uint64x2_t np_vshlq_n_u64_29(uint64x2_t a)
{
	return vshlq_n_u64(a, 29);
}

uint64x2_t np_vshlq_n_u64_30(uint64x2_t a)
{
	return vshlq_n_u64(a, 30);
}

uint64x2_t np_vshlq_n_u64_31(uint64x2_t a)
{
	return vshlq_n_u64(a, 31);
}

uint64x2_t np_vshlq_n_u64_32(uint64x2_t a)
{
	return vshlq_n_u64(a, 32);
}

uint64x2_t np_vshlq_n_u64_33(uint64x2_t a)
{
	return vshlq_n_u64(a, 33);
}

uint64x2_t np_vshlq_n_u64_34(uint64x2_t a)
{
	return vshlq_n_u64(a, 34);
}

uint64x2_t np_vshlq_n_u64_35(uint64x2_t a)
{
	return vshlq_n_u64(a, 35);
}

uint64x2_t np_vshlq_n_u64_36(uint64x2_t a)
{
	return vshlq_n_u64(a, 36);
}

uint64x2_t np_vshlq_n_u64_37(uint64x2_t a)
{
	return vshlq_n_u64(a, 37);
}

uint64x2_t np_vshlq_n_u64_38(uint64x2_t a)
{
	return vshlq_n_u64(a, 38);
}

uint64x2_t np_vshlq_n_u64_39(uint64x2_t a)
{
	return vshlq_n_u64(a, 39);
}

uint64x2_t np_vshlq_n_u64_40(uint64x2_t a)
{
	return vshlq_n_u64(a, 40);
}

uint64x2_t np_vshlq_n_u64_41(uint64x2_t a)
{
	return vshlq_n_u64(a, 41);
}

uint64x2_t np_vshlq_n_u64_42(uint64x2_t a)
{
	return vshlq_n_u64(a, 42);
}

uint64x2_t np_vshlq_n_u64_43(uint64x2_t a)
{
	return vshlq_n_u64(a, 43);
}

uint64x2_t np_vshlq_n_u64_44(uint64x2_t a)
{
	return vshlq_n_u64(a, 44);
}

uint64x2_t np_vshlq_n_u64_45(uint64x2_t a)
{
	return vshlq_n_u64(a, 45);
}

uint64x2_t np_vshlq_n_u64_46(uint64x2_t a)
{
	return vshlq_n_u64(a, 46);
}

uint64x2_t np_vshlq_n_u64_47(uint64x2_t a)
{
	return vshlq_n_u64(a, 47);
}

uint64x2_t np_vshlq_n_u64_48(uint64x2_t a)
{
	return vshlq_n_u64(a, 48);
}

uint64x2_t np_vshlq_n_u64_49(uint64x2_t a)
{
	return vshlq_n_u64(a, 49);
}

uint64x2_t np_vshlq_n_u64_50(uint64x2_t a)
{
	return vshlq_n_u64(a, 50);
}

uint64x2_t np_vshlq_n_u64_51(uint64x2_t a)
{
	return vshlq_n_u64(a, 51);
}

uint64x2_t np_vshlq_n_u64_52(uint64x2_t a)
{
	return vshlq_n_u64(a, 52);
}

uint64x2_t np_vshlq_n_u64_53(uint64x2_t a)
{
	return vshlq_n_u64(a, 53);
}

uint64x2_t np_vshlq_n_u64_54(uint64x2_t a)
{
	return vshlq_n_u64(a, 54);
}

uint64x2_t np_vshlq_n_u64_55(uint64x2_t a)
{
	return vshlq_n_u64(a, 55);
}

uint64x2_t np_vshlq_n_u64_56(uint64x2_t a)
{
	return vshlq_n_u64(a, 56);
}

uint64x2_t np_vshlq_n_u64_57(uint64x2_t a)
{
	return vshlq_n_u64(a, 57);
}

uint64x2_t np_vshlq_n_u64_58(uint64x2_t a)
{
	return vshlq_n_u64(a, 58);
}

uint64x2_t np_vshlq_n_u64_59(uint64x2_t a)
{
	return vshlq_n_u64(a, 59);
}

uint64x2_t np_vshlq_n_u64_60(uint64x2_t a)
{
	return vshlq_n_u64(a, 60);
}

uint64x2_t np_vshlq_n_u64_61(uint64x2_t a)
{
	return vshlq_n_u64(a, 61);
}

uint64x2_t np_vshlq_n_u64_62(uint64x2_t a)
{
	return vshlq_n_u64(a, 62);
}

uint64x2_t np_vshlq_n_u64_63(uint64x2_t a)
{
	return vshlq_n_u64(a, 63);
}

int8x16_t np_vrshrq_n_s8_1(int8x16_t a)
{
	return vrshrq_n_s8(a, 1);
}

int8x16_t np_vrshrq_n_s8_2(int8x16_t a)
{
	return vrshrq_n_s8(a, 2);
}

int8x16_t np_vrshrq_n_s8_3(int8x16_t a)
{
	return vrshrq_n_s8(a, 3);
}

int8x16_t np_vrshrq_n_s8_4(int8x16_t a)
{
	return vrshrq_n_s8(a, 4);
}

int8x16_t np_vrshrq_n_s8_5(int8x16_t a)
{
	return vrshrq_n_s8(a, 5);
}

int8x16_t np_vrshrq_n_s8_6(int8x16_t a)
{
	return vrshrq_n_s8(a, 6);
}

int8x16_t np_vrshrq_n_s8_7(int8x16_t a)
{
	return vrshrq_n_s8(a, 7);
}

int8x16_t np_vrshrq_n_s8_8(int8x16_t a)
{
	return vrshrq_n_s8(a, 8);
}

int16x8_t np_vrshrq_n_s16_1(int16x8_t a)
{
	return vrshrq_n_s16(a, 1);
}

int16x8_t np_vrshrq_n_s16_2(int16x8_t a)
{
	return vrshrq_n_s16(a, 2);
}

int16x8_t np_vrshrq_n_s16_3(int16x8_t a)
{
	return vrshrq_n_s16(a, 3);
}

int16x8_t np_vrshrq_n_s16_4(int16x8_t a)
{
	return vrshrq_n_s16(a, 4);
}

int16x8_t np_vrshrq_n_s16_5(int16x8_t a)
{
	return vrshrq_n_s16(a, 5);
}

int16x8_t np_vrshrq_n_s16_6(int16x8_t a)
{
	return vrshrq_n_s16(a, 6);
}

int16x8_t np_vrshrq_n_s16_7(int16x8_t a)
{
	return vrshrq_n_s16(a, 7);
}

int16x8_t np_vrshrq_n_s16_8(int16x8_t a)
{
	return vrshrq_n_s16(a, 8);
}

int16x8_t np_vrshrq_n_s16_9(int16x8_t a)
{
	return vrshrq_n_s16(a, 9);
}

int16x8_t np_vrshrq_n_s16_10(int16x8_t a)
{
	return vrshrq_n_s16(a, 10);
}

int16x8_t np_vrshrq_n_s16_11(int16x8_t a)
{
	return vrshrq_n_s16(a, 11);
}

int16x8_t np_vrshrq_n_s16_12(int16x8_t a)
{
	return vrshrq_n_s16(a, 12);
}

int16x8_t np_vrshrq_n_s16_13(int16x8_t a)
{
	return vrshrq_n_s16(a, 13);
}

int16x8_t np_vrshrq_n_s16_14(int16x8_t a)
{
	return vrshrq_n_s16(a, 14);
}

int16x8_t np_vrshrq_n_s16_15(int16x8_t a)
{
	return vrshrq_n_s16(a, 15);
}

int16x8_t np_vrshrq_n_s16_16(int16x8_t a)
{
	return vrshrq_n_s16(a, 16);
}

int32x4_t np_vrshrq_n_s32_1(int32x4_t a)
{
	return vrshrq_n_s32(a, 1);
}

int32x4_t np_vrshrq_n_s32_2(int32x4_t a)
{
	return vrshrq_n_s32(a, 2);
}

int32x4_t np_vrshrq_n_s32_3(int32x4_t a)
{
	return vrshrq_n_s32(a, 3);
}

int32x4_t np_vrshrq_n_s32_4(int32x4_t a)
{
	return vrshrq_n_s32(a, 4);
}

int32x4_t np_vrshrq_n_s32_5(int32x4_t a)
{
	return vrshrq_n_s32(a, 5);
}

int32x4_t np_vrshrq_n_s32_6(int32x4_t a)
{
	return vrshrq_n_s32(a, 6);
}

int32x4_t np_vrshrq_n_s32_7(int32x4_t a)
{
	return vrshrq_n_s32(a, 7);
}

int32x4_t np_vrshrq_n_s32_8(int32x4_t a)
{
	return vrshrq_n_s32(a, 8);
}

int32x4_t np_vrshrq_n_s32_9(int32x4_t a)
{
	return vrshrq_n_s32(a, 9);
}

int32x4_t np_vrshrq_n_s32_10(int32x4_t a)
{
	return vrshrq_n_s32(a, 10);
}

int32x4_t np_vrshrq_n_s32_11(int32x4_t a)
{
	return vrshrq_n_s32(a, 11);
}

int32x4_t np_vrshrq_n_s32_12(int32x4_t a)
{
	return vrshrq_n_s32(a, 12);
}

int32x4_t np_vrshrq_n_s32_13(int32x4_t a)
{
	return vrshrq_n_s32(a, 13);
}

int32x4_t np_vrshrq_n_s32_14(int32x4_t a)
{
	return vrshrq_n_s32(a, 14);
}

int32x4_t np_vrshrq_n_s32_15(int32x4_t a)
{
	return vrshrq_n_s32(a, 15);
}

int32x4_t np_vrshrq_n_s32_16(int32x4_t a)
{
	return vrshrq_n_s32(a, 16);
}

int32x4_t np_vrshrq_n_s32_17(int32x4_t a)
{
	return vrshrq_n_s32(a, 17);
}

int32x4_t np_vrshrq_n_s32_18(int32x4_t a)
{
	return vrshrq_n_s32(a, 18);
}

int32x4_t np_vrshrq_n_s32_19(int32x4_t a)
{
	return vrshrq_n_s32(a, 19);
}

int32x4_t np_vrshrq_n_s32_20(int32x4_t a)
{
	return vrshrq_n_s32(a, 20);
}

int32x4_t np_vrshrq_n_s32_21(int32x4_t a)
{
	return vrshrq_n_s32(a, 21);
}

int32x4_t np_vrshrq_n_s32_22(int32x4_t a)
{
	return vrshrq_n_s32(a, 22);
}

int32x4_t np_vrshrq_n_s32_23(int32x4_t a)
{
	return vrshrq_n_s32(a, 23);
}

int32x4_t np_vrshrq_n_s32_24(int32x4_t a)
{
	return vrshrq_n_s32(a, 24);
}

int32x4_t np_vrshrq_n_s32_25(int32x4_t a)
{
	return vrshrq_n_s32(a, 25);
}

int32x4_t np_vrshrq_n_s32_26(int32x4_t a)
{
	return vrshrq_n_s32(a, 26);
}

int32x4_t np_vrshrq_n_s32_27(int32x4_t a)
{
	return vrshrq_n_s32(a, 27);
}

int32x4_t np_vrshrq_n_s32_28(int32x4_t a)
{
	return vrshrq_n_s32(a, 28);
}

int32x4_t np_vrshrq_n_s32_29(int32x4_t a)
{
	return vrshrq_n_s32(a, 29);
}

int32x4_t np_vrshrq_n_s32_30(int32x4_t a)
{
	return vrshrq_n_s32(a, 30);
}

int32x4_t np_vrshrq_n_s32_31(int32x4_t a)
{
	return vrshrq_n_s32(a, 31);
}

int32x4_t np_vrshrq_n_s32_32(int32x4_t a)
{
	return vrshrq_n_s32(a, 32);
}

int64x2_t np_vrshrq_n_s64_1(int64x2_t a)
{
	return vrshrq_n_s64(a, 1);
}

int64x2_t np_vrshrq_n_s64_2(int64x2_t a)
{
	return vrshrq_n_s64(a, 2);
}

int64x2_t np_vrshrq_n_s64_3(int64x2_t a)
{
	return vrshrq_n_s64(a, 3);
}

int64x2_t np_vrshrq_n_s64_4(int64x2_t a)
{
	return vrshrq_n_s64(a, 4);
}

int64x2_t np_vrshrq_n_s64_5(int64x2_t a)
{
	return vrshrq_n_s64(a, 5);
}

int64x2_t np_vrshrq_n_s64_6(int64x2_t a)
{
	return vrshrq_n_s64(a, 6);
}

int64x2_t np_vrshrq_n_s64_7(int64x2_t a)
{
	return vrshrq_n_s64(a, 7);
}

int64x2_t np_vrshrq_n_s64_8(int64x2_t a)
{
	return vrshrq_n_s64(a, 8);
}

int64x2_t np_vrshrq_n_s64_9(int64x2_t a)
{
	return vrshrq_n_s64(a, 9);
}

int64x2_t np_vrshrq_n_s64_10(int64x2_t a)
{
	return vrshrq_n_s64(a, 10);
}

int64x2_t np_vrshrq_n_s64_11(int64x2_t a)
{
	return vrshrq_n_s64(a, 11);
}

int64x2_t np_vrshrq_n_s64_12(int64x2_t a)
{
	return vrshrq_n_s64(a, 12);
}

int64x2_t np_vrshrq_n_s64_13(int64x2_t a)
{
	return vrshrq_n_s64(a, 13);
}

int64x2_t np_vrshrq_n_s64_14(int64x2_t a)
{
	return vrshrq_n_s64(a, 14);
}

int64x2_t np_vrshrq_n_s64_15(int64x2_t a)
{
	return vrshrq_n_s64(a, 15);
}

int64x2_t np_vrshrq_n_s64_16(int64x2_t a)
{
	return vrshrq_n_s64(a, 16);
}

int64x2_t np_vrshrq_n_s64_17(int64x2_t a)
{
	return vrshrq_n_s64(a, 17);
}

int64x2_t np_vrshrq_n_s64_18(int64x2_t a)
{
	return vrshrq_n_s64(a, 18);
}

int64x2_t np_vrshrq_n_s64_19(int64x2_t a)
{
	return vrshrq_n_s64(a, 19);
}

int64x2_t np_vrshrq_n_s64_20(int64x2_t a)
{
	return vrshrq_n_s64(a, 20);
}

int64x2_t np_vrshrq_n_s64_21(int64x2_t a)
{
	return vrshrq_n_s64(a, 21);
}

int64x2_t np_vrshrq_n_s64_22(int64x2_t a)
{
	return vrshrq_n_s64(a, 22);
}

int64x2_t np_vrshrq_n_s64_23(int64x2_t a)
{
	return vrshrq_n_s64(a, 23);
}

int64x2_t np_vrshrq_n_s64_24(int64x2_t a)
{
	return vrshrq_n_s64(a, 24);
}

int64x2_t np_vrshrq_n_s64_25(int64x2_t a)
{
	return vrshrq_n_s64(a, 25);
}

int64x2_t np_vrshrq_n_s64_26(int64x2_t a)
{
	return vrshrq_n_s64(a, 26);
}

int64x2_t np_vrshrq_n_s64_27(int64x2_t a)
{
	return vrshrq_n_s64(a, 27);
}

int64x2_t np_vrshrq_n_s64_28(int64x2_t a)
{
	return vrshrq_n_s64(a, 28);
}

int64x2_t np_vrshrq_n_s64_29(int64x2_t a)
{
	return vrshrq_n_s64(a, 29);
}

int64x2_t np_vrshrq_n_s64_30(int64x2_t a)
{
	return vrshrq_n_s64(a, 30);
}

int64x2_t np_vrshrq_n_s64_31(int64x2_t a)
{
	return vrshrq_n_s64(a, 31);
}

int64x2_t np_vrshrq_n_s64_32(int64x2_t a)
{
	return vrshrq_n_s64(a, 32);
}

int64x2_t np_vrshrq_n_s64_33(int64x2_t a)
{
	return vrshrq_n_s64(a, 33);
}

int64x2_t np_vrshrq_n_s64_34(int64x2_t a)
{
	return vrshrq_n_s64(a, 34);
}

int64x2_t np_vrshrq_n_s64_35(int64x2_t a)
{
	return vrshrq_n_s64(a, 35);
}

int64x2_t np_vrshrq_n_s64_36(int64x2_t a)
{
	return vrshrq_n_s64(a, 36);
}

int64x2_t np_vrshrq_n_s64_37(int64x2_t a)
{
	return vrshrq_n_s64(a, 37);
}

int64x2_t np_vrshrq_n_s64_38(int64x2_t a)
{
	return vrshrq_n_s64(a, 38);
}

int64x2_t np_vrshrq_n_s64_39(int64x2_t a)
{
	return vrshrq_n_s64(a, 39);
}

int64x2_t np_vrshrq_n_s64_40(int64x2_t a)
{
	return vrshrq_n_s64(a, 40);
}

int64x2_t np_vrshrq_n_s64_41(int64x2_t a)
{
	return vrshrq_n_s64(a, 41);
}

int64x2_t np_vrshrq_n_s64_42(int64x2_t a)
{
	return vrshrq_n_s64(a, 42);
}

int64x2_t np_vrshrq_n_s64_43(int64x2_t a)
{
	return vrshrq_n_s64(a, 43);
}

int64x2_t np_vrshrq_n_s64_44(int64x2_t a)
{
	return vrshrq_n_s64(a, 44);
}

int64x2_t np_vrshrq_n_s64_45(int64x2_t a)
{
	return vrshrq_n_s64(a, 45);
}

int64x2_t np_vrshrq_n_s64_46(int64x2_t a)
{
	return vrshrq_n_s64(a, 46);
}

int64x2_t np_vrshrq_n_s64_47(int64x2_t a)
{
	return vrshrq_n_s64(a, 47);
}

int64x2_t np_vrshrq_n_s64_48(int64x2_t a)
{
	return vrshrq_n_s64(a, 48);
}

int64x2_t np_vrshrq_n_s64_49(int64x2_t a)
{
	return vrshrq_n_s64(a, 49);
}

int64x2_t np_vrshrq_n_s64_50(int64x2_t a)
{
	return vrshrq_n_s64(a, 50);
}

int64x2_t np_vrshrq_n_s64_51(int64x2_t a)
{
	return vrshrq_n_s64(a, 51);
}

int64x2_t np_vrshrq_n_s64_52(int64x2_t a)
{
	return vrshrq_n_s64(a, 52);
}

int64x2_t np_vrshrq_n_s64_53(int64x2_t a)
{
	return vrshrq_n_s64(a, 53);
}

int64x2_t np_vrshrq_n_s64_54(int64x2_t a)
{
	return vrshrq_n_s64(a, 54);
}

int64x2_t np_vrshrq_n_s64_55(int64x2_t a)
{
	return vrshrq_n_s64(a, 55);
}

int64x2_t np_vrshrq_n_s64_56(int64x2_t a)
{
	return vrshrq_n_s64(a, 56);
}

int64x2_t np_vrshrq_n_s64_57(int64x2_t a)
{
	return vrshrq_n_s64(a, 57);
}

int64x2_t np_vrshrq_n_s64_58(int64x2_t a)
{
	return vrshrq_n_s64(a, 58);
}

int64x2_t np_vrshrq_n_s64_59(int64x2_t a)
{
	return vrshrq_n_s64(a, 59);
}

int64x2_t np_vrshrq_n_s64_60(int64x2_t a)
{
	return vrshrq_n_s64(a, 60);
}

int64x2_t np_vrshrq_n_s64_61(int64x2_t a)
{
	return vrshrq_n_s64(a, 61);
}

int64x2_t np_vrshrq_n_s64_62(int64x2_t a)
{
	return vrshrq_n_s64(a, 62);
}

int64x2_t np_vrshrq_n_s64_63(int64x2_t a)
{
	return vrshrq_n_s64(a, 63);
}

int64x2_t np_vrshrq_n_s64_64(int64x2_t a)
{
	return vrshrq_n_s64(a, 64);
}

uint8x16_t np_vrshrq_n_u8_1(uint8x16_t a)
{
	return vrshrq_n_u8(a, 1);
}

uint8x16_t np_vrshrq_n_u8_2(uint8x16_t a)
{
	return vrshrq_n_u8(a, 2);
}

uint8x16_t np_vrshrq_n_u8_3(uint8x16_t a)
{
	return vrshrq_n_u8(a, 3);
}

uint8x16_t np_vrshrq_n_u8_4(uint8x16_t a)
{
	return vrshrq_n_u8(a, 4);
}

uint8x16_t np_vrshrq_n_u8_5(uint8x16_t a)
{
	return vrshrq_n_u8(a, 5);
}

uint8x16_t np_vrshrq_n_u8_6(uint8x16_t a)
{
	return vrshrq_n_u8(a, 6);
}

uint8x16_t np_vrshrq_n_u8_7(uint8x16_t a)
{
	return vrshrq_n_u8(a, 7);
}

uint8x16_t np_vrshrq_n_u8_8(uint8x16_t a)
{
	return vrshrq_n_u8(a, 8);
}

uint16x8_t np_vrshrq_n_u16_1(uint16x8_t a)
{
	return vrshrq_n_u16(a, 1);
}

uint16x8_t np_vrshrq_n_u16_2(uint16x8_t a)
{
	return vrshrq_n_u16(a, 2);
}

uint16x8_t np_vrshrq_n_u16_3(uint16x8_t a)
{
	return vrshrq_n_u16(a, 3);
}

uint16x8_t np_vrshrq_n_u16_4(uint16x8_t a)
{
	return vrshrq_n_u16(a, 4);
}

uint16x8_t np_vrshrq_n_u16_5(uint16x8_t a)
{
	return vrshrq_n_u16(a, 5);
}

uint16x8_t np_vrshrq_n_u16_6(uint16x8_t a)
{
	return vrshrq_n_u16(a, 6);
}

uint16x8_t np_vrshrq_n_u16_7(uint16x8_t a)
{
	return vrshrq_n_u16(a, 7);
}

uint16x8_t np_vrshrq_n_u16_8(uint16x8_t a)
{
	return vrshrq_n_u16(a, 8);
}

uint16x8_t np_vrshrq_n_u16_9(uint16x8_t a)
{
	return vrshrq_n_u16(a, 9);
}

uint16x8_t np_vrshrq_n_u16_10(uint16x8_t a)
{
	return vrshrq_n_u16(a, 10);
}

uint16x8_t np_vrshrq_n_u16_11(uint16x8_t a)
{
	return vrshrq_n_u16(a, 11);
}

uint16x8_t np_vrshrq_n_u16_12(uint16x8_t a)
{
	return vrshrq_n_u16(a, 12);
}

uint16x8_t np_vrshrq_n_u16_13(uint16x8_t a)
{
	return vrshrq_n_u16(a, 13);
}

uint16x8_t np_vrshrq_n_u16_14(uint16x8_t a)
{
	return vrshrq_n_u16(a, 14);
}

uint16x8_t np_vrshrq_n_u16_15(uint16x8_t a)
{
	return vrshrq_n_u16(a, 15);
}

uint16x8_t np_vrshrq_n_u16_16(uint16x8_t a)
{
	return vrshrq_n_u16(a, 16);
}

uint32x4_t np_vrshrq_n_u32_1(uint32x4_t a)
{
	return vrshrq_n_u32(a, 1);
}

uint32x4_t np_vrshrq_n_u32_2(uint32x4_t a)
{
	return vrshrq_n_u32(a, 2);
}

uint32x4_t np_vrshrq_n_u32_3(uint32x4_t a)
{
	return vrshrq_n_u32(a, 3);
}

uint32x4_t np_vrshrq_n_u32_4(uint32x4_t a)
{
	return vrshrq_n_u32(a, 4);
}

uint32x4_t np_vrshrq_n_u32_5(uint32x4_t a)
{
	return vrshrq_n_u32(a, 5);
}

uint32x4_t np_vrshrq_n_u32_6(uint32x4_t a)
{
	return vrshrq_n_u32(a, 6);
}

uint32x4_t np_vrshrq_n_u32_7(uint32x4_t a)
{
	return vrshrq_n_u32(a, 7);
}

uint32x4_t np_vrshrq_n_u32_8(uint32x4_t a)
{
	return vrshrq_n_u32(a, 8);
}

uint32x4_t np_vrshrq_n_u32_9(uint32x4_t a)
{
	return vrshrq_n_u32(a, 9);
}

uint32x4_t np_vrshrq_n_u32_10(uint32x4_t a)
{
	return vrshrq_n_u32(a, 10);
}

uint32x4_t np_vrshrq_n_u32_11(uint32x4_t a)
{
	return vrshrq_n_u32(a, 11);
}

uint32x4_t np_vrshrq_n_u32_12(uint32x4_t a)
{
	return vrshrq_n_u32(a, 12);
}

uint32x4_t np_vrshrq_n_u32_13(uint32x4_t a)
{
	return vrshrq_n_u32(a, 13);
}

uint32x4_t np_vrshrq_n_u32_14(uint32x4_t a)
{
	return vrshrq_n_u32(a, 14);
}

uint32x4_t np_vrshrq_n_u32_15(uint32x4_t a)
{
	return vrshrq_n_u32(a, 15);
}

uint32x4_t np_vrshrq_n_u32_16(uint32x4_t a)
{
	return vrshrq_n_u32(a, 16);
}

uint32x4_t np_vrshrq_n_u32_17(uint32x4_t a)
{
	return vrshrq_n_u32(a, 17);
}

uint32x4_t np_vrshrq_n_u32_18(uint32x4_t a)
{
	return vrshrq_n_u32(a, 18);
}

uint32x4_t np_vrshrq_n_u32_19(uint32x4_t a)
{
	return vrshrq_n_u32(a, 19);
}

uint32x4_t np_vrshrq_n_u32_20(uint32x4_t a)
{
	return vrshrq_n_u32(a, 20);
}

uint32x4_t np_vrshrq_n_u32_21(uint32x4_t a)
{
	return vrshrq_n_u32(a, 21);
}

uint32x4_t np_vrshrq_n_u32_22(uint32x4_t a)
{
	return vrshrq_n_u32(a, 22);
}

uint32x4_t np_vrshrq_n_u32_23(uint32x4_t a)
{
	return vrshrq_n_u32(a, 23);
}

uint32x4_t np_vrshrq_n_u32_24(uint32x4_t a)
{
	return vrshrq_n_u32(a, 24);
}

uint32x4_t np_vrshrq_n_u32_25(uint32x4_t a)
{
	return vrshrq_n_u32(a, 25);
}

uint32x4_t np_vrshrq_n_u32_26(uint32x4_t a)
{
	return vrshrq_n_u32(a, 26);
}

uint32x4_t np_vrshrq_n_u32_27(uint32x4_t a)
{
	return vrshrq_n_u32(a, 27);
}

uint32x4_t np_vrshrq_n_u32_28(uint32x4_t a)
{
	return vrshrq_n_u32(a, 28);
}

uint32x4_t np_vrshrq_n_u32_29(uint32x4_t a)
{
	return vrshrq_n_u32(a, 29);
}

uint32x4_t np_vrshrq_n_u32_30(uint32x4_t a)
{
	return vrshrq_n_u32(a, 30);
}

uint32x4_t np_vrshrq_n_u32_31(uint32x4_t a)
{
	return vrshrq_n_u32(a, 31);
}

uint32x4_t np_vrshrq_n_u32_32(uint32x4_t a)
{
	return vrshrq_n_u32(a, 32);
}

uint64x2_t np_vrshrq_n_u64_1(uint64x2_t a)
{
	return vrshrq_n_u64(a, 1);
}

uint64x2_t np_vrshrq_n_u64_2(uint64x2_t a)
{
	return vrshrq_n_u64(a, 2);
}

uint64x2_t np_vrshrq_n_u64_3(uint64x2_t a)
{
	return vrshrq_n_u64(a, 3);
}

uint64x2_t np_vrshrq_n_u64_4(uint64x2_t a)
{
	return vrshrq_n_u64(a, 4);
}

uint64x2_t np_vrshrq_n_u64_5(uint64x2_t a)
{
	return vrshrq_n_u64(a, 5);
}

uint64x2_t np_vrshrq_n_u64_6(uint64x2_t a)
{
	return vrshrq_n_u64(a, 6);
}

uint64x2_t np_vrshrq_n_u64_7(uint64x2_t a)
{
	return vrshrq_n_u64(a, 7);
}

uint64x2_t np_vrshrq_n_u64_8(uint64x2_t a)
{
	return vrshrq_n_u64(a, 8);
}

uint64x2_t np_vrshrq_n_u64_9(uint64x2_t a)
{
	return vrshrq_n_u64(a, 9);
}

uint64x2_t np_vrshrq_n_u64_10(uint64x2_t a)
{
	return vrshrq_n_u64(a, 10);
}

uint64x2_t np_vrshrq_n_u64_11(uint64x2_t a)
{
	return vrshrq_n_u64(a, 11);
}

uint64x2_t np_vrshrq_n_u64_12(uint64x2_t a)
{
	return vrshrq_n_u64(a, 12);
}

uint64x2_t np_vrshrq_n_u64_13(uint64x2_t a)
{
	return vrshrq_n_u64(a, 13);
}

uint64x2_t np_vrshrq_n_u64_14(uint64x2_t a)
{
	return vrshrq_n_u64(a, 14);
}

uint64x2_t np_vrshrq_n_u64_15(uint64x2_t a)
{
	return vrshrq_n_u64(a, 15);
}

uint64x2_t np_vrshrq_n_u64_16(uint64x2_t a)
{
	return vrshrq_n_u64(a, 16);
}

uint64x2_t np_vrshrq_n_u64_17(uint64x2_t a)
{
	return vrshrq_n_u64(a, 17);
}

uint64x2_t np_vrshrq_n_u64_18(uint64x2_t a)
{
	return vrshrq_n_u64(a, 18);
}

uint64x2_t np_vrshrq_n_u64_19(uint64x2_t a)
{
	return vrshrq_n_u64(a, 19);
}

uint64x2_t np_vrshrq_n_u64_20(uint64x2_t a)
{
	return vrshrq_n_u64(a, 20);
}

uint64x2_t np_vrshrq_n_u64_21(uint64x2_t a)
{
	return vrshrq_n_u64(a, 21);
}

uint64x2_t np_vrshrq_n_u64_22(uint64x2_t a)
{
	return vrshrq_n_u64(a, 22);
}

uint64x2_t np_vrshrq_n_u64_23(uint64x2_t a)
{
	return vrshrq_n_u64(a, 23);
}

uint64x2_t np_vrshrq_n_u64_24(uint64x2_t a)
{
	return vrshrq_n_u64(a, 24);
}

uint64x2_t np_vrshrq_n_u64_25(uint64x2_t a)
{
	return vrshrq_n_u64(a, 25);
}

uint64x2_t np_vrshrq_n_u64_26(uint64x2_t a)
{
	return vrshrq_n_u64(a, 26);
}

uint64x2_t np_vrshrq_n_u64_27(uint64x2_t a)
{
	return vrshrq_n_u64(a, 27);
}

uint64x2_t np_vrshrq_n_u64_28(uint64x2_t a)
{
	return vrshrq_n_u64(a, 28);
}

uint64x2_t np_vrshrq_n_u64_29(uint64x2_t a)
{
	return vrshrq_n_u64(a, 29);
}

uint64x2_t np_vrshrq_n_u64_30(uint64x2_t a)
{
	return vrshrq_n_u64(a, 30);
}

uint64x2_t np_vrshrq_n_u64_31(uint64x2_t a)
{
	return vrshrq_n_u64(a, 31);
}

uint64x2_t np_vrshrq_n_u64_32(uint64x2_t a)
{
	return vrshrq_n_u64(a, 32);
}

uint64x2_t np_vrshrq_n_u64_33(uint64x2_t a)
{
	return vrshrq_n_u64(a, 33);
}

uint64x2_t np_vrshrq_n_u64_34(uint64x2_t a)
{
	return vrshrq_n_u64(a, 34);
}

uint64x2_t np_vrshrq_n_u64_35(uint64x2_t a)
{
	return vrshrq_n_u64(a, 35);
}

uint64x2_t np_vrshrq_n_u64_36(uint64x2_t a)
{
	return vrshrq_n_u64(a, 36);
}

uint64x2_t np_vrshrq_n_u64_37(uint64x2_t a)
{
	return vrshrq_n_u64(a, 37);
}

uint64x2_t np_vrshrq_n_u64_38(uint64x2_t a)
{
	return vrshrq_n_u64(a, 38);
}

uint64x2_t np_vrshrq_n_u64_39(uint64x2_t a)
{
	return vrshrq_n_u64(a, 39);
}

uint64x2_t np_vrshrq_n_u64_40(uint64x2_t a)
{
	return vrshrq_n_u64(a, 40);
}

uint64x2_t np_vrshrq_n_u64_41(uint64x2_t a)
{
	return vrshrq_n_u64(a, 41);
}

uint64x2_t np_vrshrq_n_u64_42(uint64x2_t a)
{
	return vrshrq_n_u64(a, 42);
}

uint64x2_t np_vrshrq_n_u64_43(uint64x2_t a)
{
	return vrshrq_n_u64(a, 43);
}

uint64x2_t np_vrshrq_n_u64_44(uint64x2_t a)
{
	return vrshrq_n_u64(a, 44);
}

uint64x2_t np_vrshrq_n_u64_45(uint64x2_t a)
{
	return vrshrq_n_u64(a, 45);
}

uint64x2_t np_vrshrq_n_u64_46(uint64x2_t a)
{
	return vrshrq_n_u64(a, 46);
}

uint64x2_t np_vrshrq_n_u64_47(uint64x2_t a)
{
	return vrshrq_n_u64(a, 47);
}

uint64x2_t np_vrshrq_n_u64_48(uint64x2_t a)
{
	return vrshrq_n_u64(a, 48);
}

uint64x2_t np_vrshrq_n_u64_49(uint64x2_t a)
{
	return vrshrq_n_u64(a, 49);
}

uint64x2_t np_vrshrq_n_u64_50(uint64x2_t a)
{
	return vrshrq_n_u64(a, 50);
}

uint64x2_t np_vrshrq_n_u64_51(uint64x2_t a)
{
	return vrshrq_n_u64(a, 51);
}

uint64x2_t np_vrshrq_n_u64_52(uint64x2_t a)
{
	return vrshrq_n_u64(a, 52);
}

uint64x2_t np_vrshrq_n_u64_53(uint64x2_t a)
{
	return vrshrq_n_u64(a, 53);
}

uint64x2_t np_vrshrq_n_u64_54(uint64x2_t a)
{
	return vrshrq_n_u64(a, 54);
}

uint64x2_t np_vrshrq_n_u64_55(uint64x2_t a)
{
	return vrshrq_n_u64(a, 55);
}

uint64x2_t np_vrshrq_n_u64_56(uint64x2_t a)
{
	return vrshrq_n_u64(a, 56);
}

uint64x2_t np_vrshrq_n_u64_57(uint64x2_t a)
{
	return vrshrq_n_u64(a, 57);
}

uint64x2_t np_vrshrq_n_u64_58(uint64x2_t a)
{
	return vrshrq_n_u64(a, 58);
}

uint64x2_t np_vrshrq_n_u64_59(uint64x2_t a)
{
	return vrshrq_n_u64(a, 59);
}

uint64x2_t np_vrshrq_n_u64_60(uint64x2_t a)
{
	return vrshrq_n_u64(a, 60);
}

uint64x2_t np_vrshrq_n_u64_61(uint64x2_t a)
{
	return vrshrq_n_u64(a, 61);
}

uint64x2_t np_vrshrq_n_u64_62(uint64x2_t a)
{
	return vrshrq_n_u64(a, 62);
}

uint64x2_t np_vrshrq_n_u64_63(uint64x2_t a)
{
	return vrshrq_n_u64(a, 63);
}

uint64x2_t np_vrshrq_n_u64_64(uint64x2_t a)
{
	return vrshrq_n_u64(a, 64);
}

int8x16_t np_vsraq_n_s8_1(int8x16_t a, int8x16_t b)
{
	return vsraq_n_s8(a, b, 1);
}

int8x16_t np_vsraq_n_s8_2(int8x16_t a, int8x16_t b)
{
	return vsraq_n_s8(a, b, 2);
}

int8x16_t np_vsraq_n_s8_3(int8x16_t a, int8x16_t b)
{
	return vsraq_n_s8(a, b, 3);
}

int8x16_t np_vsraq_n_s8_4(int8x16_t a, int8x16_t b)
{
	return vsraq_n_s8(a, b, 4);
}

int8x16_t np_vsraq_n_s8_5(int8x16_t a, int8x16_t b)
{
	return vsraq_n_s8(a, b, 5);
}

int8x16_t np_vsraq_n_s8_6(int8x16_t a, int8x16_t b)
{
	return vsraq_n_s8(a, b, 6);
}

int8x16_t np_vsraq_n_s8_7(int8x16_t a, int8x16_t b)
{
	return vsraq_n_s8(a, b, 7);
}

int8x16_t np_vsraq_n_s8_8(int8x16_t a, int8x16_t b)
{
	return vsraq_n_s8(a, b, 8);
}

int16x8_t np_vsraq_n_s16_1(int16x8_t a, int16x8_t b)
{
	return vsraq_n_s16(a, b, 1);
}

int16x8_t np_vsraq_n_s16_2(int16x8_t a, int16x8_t b)
{
	return vsraq_n_s16(a, b, 2);
}

int16x8_t np_vsraq_n_s16_3(int16x8_t a, int16x8_t b)
{
	return vsraq_n_s16(a, b, 3);
}

int16x8_t np_vsraq_n_s16_4(int16x8_t a, int16x8_t b)
{
	return vsraq_n_s16(a, b, 4);
}

int16x8_t np_vsraq_n_s16_5(int16x8_t a, int16x8_t b)
{
	return vsraq_n_s16(a, b, 5);
}

int16x8_t np_vsraq_n_s16_6(int16x8_t a, int16x8_t b)
{
	return vsraq_n_s16(a, b, 6);
}

int16x8_t np_vsraq_n_s16_7(int16x8_t a, int16x8_t b)
{
	return vsraq_n_s16(a, b, 7);
}

int16x8_t np_vsraq_n_s16_8(int16x8_t a, int16x8_t b)
{
	return vsraq_n_s16(a, b, 8);
}

int16x8_t np_vsraq_n_s16_9(int16x8_t a, int16x8_t b)
{
	return vsraq_n_s16(a, b, 9);
}

int16x8_t np_vsraq_n_s16_10(int16x8_t a, int16x8_t b)
{
	return vsraq_n_s16(a, b, 10);
}

int16x8_t np_vsraq_n_s16_11(int16x8_t a, int16x8_t b)
{
	return vsraq_n_s16(a, b, 11);
}

int16x8_t np_vsraq_n_s16_12(int16x8_t a, int16x8_t b)
{
	return vsraq_n_s16(a, b, 12);
}

int16x8_t np_vsraq_n_s16_13(int16x8_t a, int16x8_t b)
{
	return vsraq_n_s16(a, b, 13);
}

int16x8_t np_vsraq_n_s16_14(int16x8_t a, int16x8_t b)
{
	return vsraq_n_s16(a, b, 14);
}

int16x8_t np_vsraq_n_s16_15(int16x8_t a, int16x8_t b)
{
	return vsraq_n_s16(a, b, 15);
}

int16x8_t np_vsraq_n_s16_16(int16x8_t a, int16x8_t b)
{
	return vsraq_n_s16(a, b, 16);
}

int32x4_t np_vsraq_n_s32_1(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 1);
}

int32x4_t np_vsraq_n_s32_2(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 2);
}

int32x4_t np_vsraq_n_s32_3(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 3);
}

int32x4_t np_vsraq_n_s32_4(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 4);
}

int32x4_t np_vsraq_n_s32_5(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 5);
}

int32x4_t np_vsraq_n_s32_6(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 6);
}

int32x4_t np_vsraq_n_s32_7(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 7);
}

int32x4_t np_vsraq_n_s32_8(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 8);
}

int32x4_t np_vsraq_n_s32_9(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 9);
}

int32x4_t np_vsraq_n_s32_10(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 10);
}

int32x4_t np_vsraq_n_s32_11(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 11);
}

int32x4_t np_vsraq_n_s32_12(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 12);
}

int32x4_t np_vsraq_n_s32_13(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 13);
}

int32x4_t np_vsraq_n_s32_14(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 14);
}

int32x4_t np_vsraq_n_s32_15(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 15);
}

int32x4_t np_vsraq_n_s32_16(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 16);
}

int32x4_t np_vsraq_n_s32_17(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 17);
}

int32x4_t np_vsraq_n_s32_18(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 18);
}

int32x4_t np_vsraq_n_s32_19(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 19);
}

int32x4_t np_vsraq_n_s32_20(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 20);
}

int32x4_t np_vsraq_n_s32_21(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 21);
}

int32x4_t np_vsraq_n_s32_22(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 22);
}

int32x4_t np_vsraq_n_s32_23(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 23);
}

int32x4_t np_vsraq_n_s32_24(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 24);
}

int32x4_t np_vsraq_n_s32_25(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 25);
}

int32x4_t np_vsraq_n_s32_26(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 26);
}

int32x4_t np_vsraq_n_s32_27(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 27);
}

int32x4_t np_vsraq_n_s32_28(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 28);
}

int32x4_t np_vsraq_n_s32_29(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 29);
}

int32x4_t np_vsraq_n_s32_30(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 30);
}

int32x4_t np_vsraq_n_s32_31(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 31);
}

int32x4_t np_vsraq_n_s32_32(int32x4_t a, int32x4_t b)
{
	return vsraq_n_s32(a, b, 32);
}

int64x2_t np_vsraq_n_s64_1(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 1);
}

int64x2_t np_vsraq_n_s64_2(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 2);
}

int64x2_t np_vsraq_n_s64_3(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 3);
}

int64x2_t np_vsraq_n_s64_4(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 4);
}

int64x2_t np_vsraq_n_s64_5(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 5);
}

int64x2_t np_vsraq_n_s64_6(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 6);
}

int64x2_t np_vsraq_n_s64_7(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 7);
}

int64x2_t np_vsraq_n_s64_8(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 8);
}

int64x2_t np_vsraq_n_s64_9(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 9);
}

int64x2_t np_vsraq_n_s64_10(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 10);
}

int64x2_t np_vsraq_n_s64_11(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 11);
}

int64x2_t np_vsraq_n_s64_12(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 12);
}

int64x2_t np_vsraq_n_s64_13(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 13);
}

int64x2_t np_vsraq_n_s64_14(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 14);
}

int64x2_t np_vsraq_n_s64_15(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 15);
}

int64x2_t np_vsraq_n_s64_16(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 16);
}

int64x2_t np_vsraq_n_s64_17(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 17);
}

int64x2_t np_vsraq_n_s64_18(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 18);
}

int64x2_t np_vsraq_n_s64_19(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 19);
}

int64x2_t np_vsraq_n_s64_20(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 20);
}

int64x2_t np_vsraq_n_s64_21(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 21);
}

int64x2_t np_vsraq_n_s64_22(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 22);
}

int64x2_t np_vsraq_n_s64_23(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 23);
}

int64x2_t np_vsraq_n_s64_24(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 24);
}

int64x2_t np_vsraq_n_s64_25(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 25);
}

int64x2_t np_vsraq_n_s64_26(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 26);
}

int64x2_t np_vsraq_n_s64_27(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 27);
}

int64x2_t np_vsraq_n_s64_28(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 28);
}

int64x2_t np_vsraq_n_s64_29(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 29);
}

int64x2_t np_vsraq_n_s64_30(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 30);
}

int64x2_t np_vsraq_n_s64_31(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 31);
}

int64x2_t np_vsraq_n_s64_32(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 32);
}

int64x2_t np_vsraq_n_s64_33(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 33);
}

int64x2_t np_vsraq_n_s64_34(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 34);
}

int64x2_t np_vsraq_n_s64_35(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 35);
}

int64x2_t np_vsraq_n_s64_36(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 36);
}

int64x2_t np_vsraq_n_s64_37(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 37);
}

int64x2_t np_vsraq_n_s64_38(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 38);
}

int64x2_t np_vsraq_n_s64_39(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 39);
}

int64x2_t np_vsraq_n_s64_40(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 40);
}

int64x2_t np_vsraq_n_s64_41(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 41);
}

int64x2_t np_vsraq_n_s64_42(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 42);
}

int64x2_t np_vsraq_n_s64_43(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 43);
}

int64x2_t np_vsraq_n_s64_44(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 44);
}

int64x2_t np_vsraq_n_s64_45(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 45);
}

int64x2_t np_vsraq_n_s64_46(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 46);
}

int64x2_t np_vsraq_n_s64_47(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 47);
}

int64x2_t np_vsraq_n_s64_48(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 48);
}

int64x2_t np_vsraq_n_s64_49(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 49);
}

int64x2_t np_vsraq_n_s64_50(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 50);
}

int64x2_t np_vsraq_n_s64_51(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 51);
}

int64x2_t np_vsraq_n_s64_52(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 52);
}

int64x2_t np_vsraq_n_s64_53(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 53);
}

int64x2_t np_vsraq_n_s64_54(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 54);
}

int64x2_t np_vsraq_n_s64_55(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 55);
}

int64x2_t np_vsraq_n_s64_56(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 56);
}

int64x2_t np_vsraq_n_s64_57(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 57);
}

int64x2_t np_vsraq_n_s64_58(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 58);
}

int64x2_t np_vsraq_n_s64_59(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 59);
}

int64x2_t np_vsraq_n_s64_60(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 60);
}

int64x2_t np_vsraq_n_s64_61(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 61);
}

int64x2_t np_vsraq_n_s64_62(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 62);
}

int64x2_t np_vsraq_n_s64_63(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 63);
}

int64x2_t np_vsraq_n_s64_64(int64x2_t a, int64x2_t b)
{
	return vsraq_n_s64(a, b, 64);
}

uint8x16_t np_vsraq_n_u8_1(uint8x16_t a, uint8x16_t b)
{
	return vsraq_n_u8(a, b, 1);
}

uint8x16_t np_vsraq_n_u8_2(uint8x16_t a, uint8x16_t b)
{
	return vsraq_n_u8(a, b, 2);
}

uint8x16_t np_vsraq_n_u8_3(uint8x16_t a, uint8x16_t b)
{
	return vsraq_n_u8(a, b, 3);
}

uint8x16_t np_vsraq_n_u8_4(uint8x16_t a, uint8x16_t b)
{
	return vsraq_n_u8(a, b, 4);
}

uint8x16_t np_vsraq_n_u8_5(uint8x16_t a, uint8x16_t b)
{
	return vsraq_n_u8(a, b, 5);
}

uint8x16_t np_vsraq_n_u8_6(uint8x16_t a, uint8x16_t b)
{
	return vsraq_n_u8(a, b, 6);
}

uint8x16_t np_vsraq_n_u8_7(uint8x16_t a, uint8x16_t b)
{
	return vsraq_n_u8(a, b, 7);
}

uint8x16_t np_vsraq_n_u8_8(uint8x16_t a, uint8x16_t b)
{
	return vsraq_n_u8(a, b, 8);
}

uint16x8_t np_vsraq_n_u16_1(uint16x8_t a, uint16x8_t b)
{
	return vsraq_n_u16(a, b, 1);
}

uint16x8_t np_vsraq_n_u16_2(uint16x8_t a, uint16x8_t b)
{
	return vsraq_n_u16(a, b, 2);
}

uint16x8_t np_vsraq_n_u16_3(uint16x8_t a, uint16x8_t b)
{
	return vsraq_n_u16(a, b, 3);
}

uint16x8_t np_vsraq_n_u16_4(uint16x8_t a, uint16x8_t b)
{
	return vsraq_n_u16(a, b, 4);
}

uint16x8_t np_vsraq_n_u16_5(uint16x8_t a, uint16x8_t b)
{
	return vsraq_n_u16(a, b, 5);
}

uint16x8_t np_vsraq_n_u16_6(uint16x8_t a, uint16x8_t b)
{
	return vsraq_n_u16(a, b, 6);
}

uint16x8_t np_vsraq_n_u16_7(uint16x8_t a, uint16x8_t b)
{
	return vsraq_n_u16(a, b, 7);
}

uint16x8_t np_vsraq_n_u16_8(uint16x8_t a, uint16x8_t b)
{
	return vsraq_n_u16(a, b, 8);
}

uint16x8_t np_vsraq_n_u16_9(uint16x8_t a, uint16x8_t b)
{
	return vsraq_n_u16(a, b, 9);
}

uint16x8_t np_vsraq_n_u16_10(uint16x8_t a, uint16x8_t b)
{
	return vsraq_n_u16(a, b, 10);
}

uint16x8_t np_vsraq_n_u16_11(uint16x8_t a, uint16x8_t b)
{
	return vsraq_n_u16(a, b, 11);
}

uint16x8_t np_vsraq_n_u16_12(uint16x8_t a, uint16x8_t b)
{
	return vsraq_n_u16(a, b, 12);
}

uint16x8_t np_vsraq_n_u16_13(uint16x8_t a, uint16x8_t b)
{
	return vsraq_n_u16(a, b, 13);
}

uint16x8_t np_vsraq_n_u16_14(uint16x8_t a, uint16x8_t b)
{
	return vsraq_n_u16(a, b, 14);
}

uint16x8_t np_vsraq_n_u16_15(uint16x8_t a, uint16x8_t b)
{
	return vsraq_n_u16(a, b, 15);
}

uint16x8_t np_vsraq_n_u16_16(uint16x8_t a, uint16x8_t b)
{
	return vsraq_n_u16(a, b, 16);
}

uint32x4_t np_vsraq_n_u32_1(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 1);
}

uint32x4_t np_vsraq_n_u32_2(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 2);
}

uint32x4_t np_vsraq_n_u32_3(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 3);
}

uint32x4_t np_vsraq_n_u32_4(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 4);
}

uint32x4_t np_vsraq_n_u32_5(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 5);
}

uint32x4_t np_vsraq_n_u32_6(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 6);
}

uint32x4_t np_vsraq_n_u32_7(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 7);
}

uint32x4_t np_vsraq_n_u32_8(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 8);
}

uint32x4_t np_vsraq_n_u32_9(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 9);
}

uint32x4_t np_vsraq_n_u32_10(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 10);
}

uint32x4_t np_vsraq_n_u32_11(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 11);
}

uint32x4_t np_vsraq_n_u32_12(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 12);
}

uint32x4_t np_vsraq_n_u32_13(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 13);
}

uint32x4_t np_vsraq_n_u32_14(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 14);
}

uint32x4_t np_vsraq_n_u32_15(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 15);
}

uint32x4_t np_vsraq_n_u32_16(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 16);
}

uint32x4_t np_vsraq_n_u32_17(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 17);
}

uint32x4_t np_vsraq_n_u32_18(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 18);
}

uint32x4_t np_vsraq_n_u32_19(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 19);
}

uint32x4_t np_vsraq_n_u32_20(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 20);
}

uint32x4_t np_vsraq_n_u32_21(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 21);
}

uint32x4_t np_vsraq_n_u32_22(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 22);
}

uint32x4_t np_vsraq_n_u32_23(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 23);
}

uint32x4_t np_vsraq_n_u32_24(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 24);
}

uint32x4_t np_vsraq_n_u32_25(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 25);
}

uint32x4_t np_vsraq_n_u32_26(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 26);
}

uint32x4_t np_vsraq_n_u32_27(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 27);
}

uint32x4_t np_vsraq_n_u32_28(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 28);
}

uint32x4_t np_vsraq_n_u32_29(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 29);
}

uint32x4_t np_vsraq_n_u32_30(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 30);
}

uint32x4_t np_vsraq_n_u32_31(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 31);
}

uint32x4_t np_vsraq_n_u32_32(uint32x4_t a, uint32x4_t b)
{
	return vsraq_n_u32(a, b, 32);
}

uint64x2_t np_vsraq_n_u64_1(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 1);
}

uint64x2_t np_vsraq_n_u64_2(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 2);
}

uint64x2_t np_vsraq_n_u64_3(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 3);
}

uint64x2_t np_vsraq_n_u64_4(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 4);
}

uint64x2_t np_vsraq_n_u64_5(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 5);
}

uint64x2_t np_vsraq_n_u64_6(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 6);
}

uint64x2_t np_vsraq_n_u64_7(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 7);
}

uint64x2_t np_vsraq_n_u64_8(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 8);
}

uint64x2_t np_vsraq_n_u64_9(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 9);
}

uint64x2_t np_vsraq_n_u64_10(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 10);
}

uint64x2_t np_vsraq_n_u64_11(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 11);
}

uint64x2_t np_vsraq_n_u64_12(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 12);
}

uint64x2_t np_vsraq_n_u64_13(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 13);
}

uint64x2_t np_vsraq_n_u64_14(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 14);
}

uint64x2_t np_vsraq_n_u64_15(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 15);
}

uint64x2_t np_vsraq_n_u64_16(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 16);
}

uint64x2_t np_vsraq_n_u64_17(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 17);
}

uint64x2_t np_vsraq_n_u64_18(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 18);
}

uint64x2_t np_vsraq_n_u64_19(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 19);
}

uint64x2_t np_vsraq_n_u64_20(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 20);
}

uint64x2_t np_vsraq_n_u64_21(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 21);
}

uint64x2_t np_vsraq_n_u64_22(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 22);
}

uint64x2_t np_vsraq_n_u64_23(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 23);
}

uint64x2_t np_vsraq_n_u64_24(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 24);
}

uint64x2_t np_vsraq_n_u64_25(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 25);
}

uint64x2_t np_vsraq_n_u64_26(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 26);
}

uint64x2_t np_vsraq_n_u64_27(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 27);
}

uint64x2_t np_vsraq_n_u64_28(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 28);
}

uint64x2_t np_vsraq_n_u64_29(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 29);
}

uint64x2_t np_vsraq_n_u64_30(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 30);
}

uint64x2_t np_vsraq_n_u64_31(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 31);
}

uint64x2_t np_vsraq_n_u64_32(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 32);
}

uint64x2_t np_vsraq_n_u64_33(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 33);
}

uint64x2_t np_vsraq_n_u64_34(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 34);
}

uint64x2_t np_vsraq_n_u64_35(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 35);
}

uint64x2_t np_vsraq_n_u64_36(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 36);
}

uint64x2_t np_vsraq_n_u64_37(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 37);
}

uint64x2_t np_vsraq_n_u64_38(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 38);
}

uint64x2_t np_vsraq_n_u64_39(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 39);
}

uint64x2_t np_vsraq_n_u64_40(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 40);
}

uint64x2_t np_vsraq_n_u64_41(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 41);
}

uint64x2_t np_vsraq_n_u64_42(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 42);
}

uint64x2_t np_vsraq_n_u64_43(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 43);
}

uint64x2_t np_vsraq_n_u64_44(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 44);
}

uint64x2_t np_vsraq_n_u64_45(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 45);
}

uint64x2_t np_vsraq_n_u64_46(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 46);
}

uint64x2_t np_vsraq_n_u64_47(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 47);
}

uint64x2_t np_vsraq_n_u64_48(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 48);
}

uint64x2_t np_vsraq_n_u64_49(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 49);
}

uint64x2_t np_vsraq_n_u64_50(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 50);
}

uint64x2_t np_vsraq_n_u64_51(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 51);
}

uint64x2_t np_vsraq_n_u64_52(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 52);
}

uint64x2_t np_vsraq_n_u64_53(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 53);
}

uint64x2_t np_vsraq_n_u64_54(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 54);
}

uint64x2_t np_vsraq_n_u64_55(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 55);
}

uint64x2_t np_vsraq_n_u64_56(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 56);
}

uint64x2_t np_vsraq_n_u64_57(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 57);
}

uint64x2_t np_vsraq_n_u64_58(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 58);
}

uint64x2_t np_vsraq_n_u64_59(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 59);
}

uint64x2_t np_vsraq_n_u64_60(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 60);
}

uint64x2_t np_vsraq_n_u64_61(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 61);
}

uint64x2_t np_vsraq_n_u64_62(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 62);
}

uint64x2_t np_vsraq_n_u64_63(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 63);
}

uint64x2_t np_vsraq_n_u64_64(uint64x2_t a, uint64x2_t b)
{
	return vsraq_n_u64(a, b, 64);
}

int8x16_t np_vrsraq_n_s8_1(int8x16_t a, int8x16_t b)
{
	return vrsraq_n_s8(a, b, 1);
}

int8x16_t np_vrsraq_n_s8_2(int8x16_t a, int8x16_t b)
{
	return vrsraq_n_s8(a, b, 2);
}

int8x16_t np_vrsraq_n_s8_3(int8x16_t a, int8x16_t b)
{
	return vrsraq_n_s8(a, b, 3);
}

int8x16_t np_vrsraq_n_s8_4(int8x16_t a, int8x16_t b)
{
	return vrsraq_n_s8(a, b, 4);
}

int8x16_t np_vrsraq_n_s8_5(int8x16_t a, int8x16_t b)
{
	return vrsraq_n_s8(a, b, 5);
}

int8x16_t np_vrsraq_n_s8_6(int8x16_t a, int8x16_t b)
{
	return vrsraq_n_s8(a, b, 6);
}

int8x16_t np_vrsraq_n_s8_7(int8x16_t a, int8x16_t b)
{
	return vrsraq_n_s8(a, b, 7);
}

int8x16_t np_vrsraq_n_s8_8(int8x16_t a, int8x16_t b)
{
	return vrsraq_n_s8(a, b, 8);
}

int16x8_t np_vrsraq_n_s16_1(int16x8_t a, int16x8_t b)
{
	return vrsraq_n_s16(a, b, 1);
}

int16x8_t np_vrsraq_n_s16_2(int16x8_t a, int16x8_t b)
{
	return vrsraq_n_s16(a, b, 2);
}

int16x8_t np_vrsraq_n_s16_3(int16x8_t a, int16x8_t b)
{
	return vrsraq_n_s16(a, b, 3);
}

int16x8_t np_vrsraq_n_s16_4(int16x8_t a, int16x8_t b)
{
	return vrsraq_n_s16(a, b, 4);
}

int16x8_t np_vrsraq_n_s16_5(int16x8_t a, int16x8_t b)
{
	return vrsraq_n_s16(a, b, 5);
}

int16x8_t np_vrsraq_n_s16_6(int16x8_t a, int16x8_t b)
{
	return vrsraq_n_s16(a, b, 6);
}

int16x8_t np_vrsraq_n_s16_7(int16x8_t a, int16x8_t b)
{
	return vrsraq_n_s16(a, b, 7);
}

int16x8_t np_vrsraq_n_s16_8(int16x8_t a, int16x8_t b)
{
	return vrsraq_n_s16(a, b, 8);
}

int16x8_t np_vrsraq_n_s16_9(int16x8_t a, int16x8_t b)
{
	return vrsraq_n_s16(a, b, 9);
}

int16x8_t np_vrsraq_n_s16_10(int16x8_t a, int16x8_t b)
{
	return vrsraq_n_s16(a, b, 10);
}

int16x8_t np_vrsraq_n_s16_11(int16x8_t a, int16x8_t b)
{
	return vrsraq_n_s16(a, b, 11);
}

int16x8_t np_vrsraq_n_s16_12(int16x8_t a, int16x8_t b)
{
	return vrsraq_n_s16(a, b, 12);
}

int16x8_t np_vrsraq_n_s16_13(int16x8_t a, int16x8_t b)
{
	return vrsraq_n_s16(a, b, 13);
}

int16x8_t np_vrsraq_n_s16_14(int16x8_t a, int16x8_t b)
{
	return vrsraq_n_s16(a, b, 14);
}

int16x8_t np_vrsraq_n_s16_15(int16x8_t a, int16x8_t b)
{
	return vrsraq_n_s16(a, b, 15);
}

int16x8_t np_vrsraq_n_s16_16(int16x8_t a, int16x8_t b)
{
	return vrsraq_n_s16(a, b, 16);
}

int32x4_t np_vrsraq_n_s32_1(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 1);
}

int32x4_t np_vrsraq_n_s32_2(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 2);
}

int32x4_t np_vrsraq_n_s32_3(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 3);
}

int32x4_t np_vrsraq_n_s32_4(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 4);
}

int32x4_t np_vrsraq_n_s32_5(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 5);
}

int32x4_t np_vrsraq_n_s32_6(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 6);
}

int32x4_t np_vrsraq_n_s32_7(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 7);
}

int32x4_t np_vrsraq_n_s32_8(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 8);
}

int32x4_t np_vrsraq_n_s32_9(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 9);
}

int32x4_t np_vrsraq_n_s32_10(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 10);
}

int32x4_t np_vrsraq_n_s32_11(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 11);
}

int32x4_t np_vrsraq_n_s32_12(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 12);
}

int32x4_t np_vrsraq_n_s32_13(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 13);
}

int32x4_t np_vrsraq_n_s32_14(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 14);
}

int32x4_t np_vrsraq_n_s32_15(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 15);
}

int32x4_t np_vrsraq_n_s32_16(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 16);
}

int32x4_t np_vrsraq_n_s32_17(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 17);
}

int32x4_t np_vrsraq_n_s32_18(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 18);
}

int32x4_t np_vrsraq_n_s32_19(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 19);
}

int32x4_t np_vrsraq_n_s32_20(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 20);
}

int32x4_t np_vrsraq_n_s32_21(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 21);
}

int32x4_t np_vrsraq_n_s32_22(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 22);
}

int32x4_t np_vrsraq_n_s32_23(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 23);
}

int32x4_t np_vrsraq_n_s32_24(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 24);
}

int32x4_t np_vrsraq_n_s32_25(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 25);
}

int32x4_t np_vrsraq_n_s32_26(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 26);
}

int32x4_t np_vrsraq_n_s32_27(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 27);
}

int32x4_t np_vrsraq_n_s32_28(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 28);
}

int32x4_t np_vrsraq_n_s32_29(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 29);
}

int32x4_t np_vrsraq_n_s32_30(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 30);
}

int32x4_t np_vrsraq_n_s32_31(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 31);
}

int32x4_t np_vrsraq_n_s32_32(int32x4_t a, int32x4_t b)
{
	return vrsraq_n_s32(a, b, 32);
}

int64x2_t np_vrsraq_n_s64_1(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 1);
}

int64x2_t np_vrsraq_n_s64_2(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 2);
}

int64x2_t np_vrsraq_n_s64_3(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 3);
}

int64x2_t np_vrsraq_n_s64_4(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 4);
}

int64x2_t np_vrsraq_n_s64_5(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 5);
}

int64x2_t np_vrsraq_n_s64_6(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 6);
}

int64x2_t np_vrsraq_n_s64_7(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 7);
}

int64x2_t np_vrsraq_n_s64_8(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 8);
}

int64x2_t np_vrsraq_n_s64_9(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 9);
}

int64x2_t np_vrsraq_n_s64_10(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 10);
}

int64x2_t np_vrsraq_n_s64_11(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 11);
}

int64x2_t np_vrsraq_n_s64_12(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 12);
}

int64x2_t np_vrsraq_n_s64_13(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 13);
}

int64x2_t np_vrsraq_n_s64_14(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 14);
}

int64x2_t np_vrsraq_n_s64_15(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 15);
}

int64x2_t np_vrsraq_n_s64_16(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 16);
}

int64x2_t np_vrsraq_n_s64_17(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 17);
}

int64x2_t np_vrsraq_n_s64_18(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 18);
}

int64x2_t np_vrsraq_n_s64_19(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 19);
}

int64x2_t np_vrsraq_n_s64_20(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 20);
}

int64x2_t np_vrsraq_n_s64_21(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 21);
}

int64x2_t np_vrsraq_n_s64_22(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 22);
}

int64x2_t np_vrsraq_n_s64_23(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 23);
}

int64x2_t np_vrsraq_n_s64_24(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 24);
}

int64x2_t np_vrsraq_n_s64_25(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 25);
}

int64x2_t np_vrsraq_n_s64_26(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 26);
}

int64x2_t np_vrsraq_n_s64_27(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 27);
}

int64x2_t np_vrsraq_n_s64_28(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 28);
}

int64x2_t np_vrsraq_n_s64_29(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 29);
}

int64x2_t np_vrsraq_n_s64_30(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 30);
}

int64x2_t np_vrsraq_n_s64_31(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 31);
}

int64x2_t np_vrsraq_n_s64_32(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 32);
}

int64x2_t np_vrsraq_n_s64_33(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 33);
}

int64x2_t np_vrsraq_n_s64_34(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 34);
}

int64x2_t np_vrsraq_n_s64_35(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 35);
}

int64x2_t np_vrsraq_n_s64_36(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 36);
}

int64x2_t np_vrsraq_n_s64_37(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 37);
}

int64x2_t np_vrsraq_n_s64_38(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 38);
}

int64x2_t np_vrsraq_n_s64_39(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 39);
}

int64x2_t np_vrsraq_n_s64_40(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 40);
}

int64x2_t np_vrsraq_n_s64_41(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 41);
}

int64x2_t np_vrsraq_n_s64_42(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 42);
}

int64x2_t np_vrsraq_n_s64_43(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 43);
}

int64x2_t np_vrsraq_n_s64_44(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 44);
}

int64x2_t np_vrsraq_n_s64_45(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 45);
}

int64x2_t np_vrsraq_n_s64_46(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 46);
}

int64x2_t np_vrsraq_n_s64_47(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 47);
}

int64x2_t np_vrsraq_n_s64_48(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 48);
}

int64x2_t np_vrsraq_n_s64_49(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 49);
}

int64x2_t np_vrsraq_n_s64_50(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 50);
}

int64x2_t np_vrsraq_n_s64_51(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 51);
}

int64x2_t np_vrsraq_n_s64_52(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 52);
}

int64x2_t np_vrsraq_n_s64_53(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 53);
}

int64x2_t np_vrsraq_n_s64_54(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 54);
}

int64x2_t np_vrsraq_n_s64_55(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 55);
}

int64x2_t np_vrsraq_n_s64_56(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 56);
}

int64x2_t np_vrsraq_n_s64_57(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 57);
}

int64x2_t np_vrsraq_n_s64_58(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 58);
}

int64x2_t np_vrsraq_n_s64_59(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 59);
}

int64x2_t np_vrsraq_n_s64_60(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 60);
}

int64x2_t np_vrsraq_n_s64_61(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 61);
}

int64x2_t np_vrsraq_n_s64_62(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 62);
}

int64x2_t np_vrsraq_n_s64_63(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 63);
}

int64x2_t np_vrsraq_n_s64_64(int64x2_t a, int64x2_t b)
{
	return vrsraq_n_s64(a, b, 64);
}

uint8x16_t np_vrsraq_n_u8_1(uint8x16_t a, uint8x16_t b)
{
	return vrsraq_n_u8(a, b, 1);
}

uint8x16_t np_vrsraq_n_u8_2(uint8x16_t a, uint8x16_t b)
{
	return vrsraq_n_u8(a, b, 2);
}

uint8x16_t np_vrsraq_n_u8_3(uint8x16_t a, uint8x16_t b)
{
	return vrsraq_n_u8(a, b, 3);
}

uint8x16_t np_vrsraq_n_u8_4(uint8x16_t a, uint8x16_t b)
{
	return vrsraq_n_u8(a, b, 4);
}

uint8x16_t np_vrsraq_n_u8_5(uint8x16_t a, uint8x16_t b)
{
	return vrsraq_n_u8(a, b, 5);
}

uint8x16_t np_vrsraq_n_u8_6(uint8x16_t a, uint8x16_t b)
{
	return vrsraq_n_u8(a, b, 6);
}

uint8x16_t np_vrsraq_n_u8_7(uint8x16_t a, uint8x16_t b)
{
	return vrsraq_n_u8(a, b, 7);
}

uint8x16_t np_vrsraq_n_u8_8(uint8x16_t a, uint8x16_t b)
{
	return vrsraq_n_u8(a, b, 8);
}

uint16x8_t np_vrsraq_n_u16_1(uint16x8_t a, uint16x8_t b)
{
	return vrsraq_n_u16(a, b, 1);
}

uint16x8_t np_vrsraq_n_u16_2(uint16x8_t a, uint16x8_t b)
{
	return vrsraq_n_u16(a, b, 2);
}

uint16x8_t np_vrsraq_n_u16_3(uint16x8_t a, uint16x8_t b)
{
	return vrsraq_n_u16(a, b, 3);
}

uint16x8_t np_vrsraq_n_u16_4(uint16x8_t a, uint16x8_t b)
{
	return vrsraq_n_u16(a, b, 4);
}

uint16x8_t np_vrsraq_n_u16_5(uint16x8_t a, uint16x8_t b)
{
	return vrsraq_n_u16(a, b, 5);
}

uint16x8_t np_vrsraq_n_u16_6(uint16x8_t a, uint16x8_t b)
{
	return vrsraq_n_u16(a, b, 6);
}

uint16x8_t np_vrsraq_n_u16_7(uint16x8_t a, uint16x8_t b)
{
	return vrsraq_n_u16(a, b, 7);
}

uint16x8_t np_vrsraq_n_u16_8(uint16x8_t a, uint16x8_t b)
{
	return vrsraq_n_u16(a, b, 8);
}

uint16x8_t np_vrsraq_n_u16_9(uint16x8_t a, uint16x8_t b)
{
	return vrsraq_n_u16(a, b, 9);
}

uint16x8_t np_vrsraq_n_u16_10(uint16x8_t a, uint16x8_t b)
{
	return vrsraq_n_u16(a, b, 10);
}

uint16x8_t np_vrsraq_n_u16_11(uint16x8_t a, uint16x8_t b)
{
	return vrsraq_n_u16(a, b, 11);
}

uint16x8_t np_vrsraq_n_u16_12(uint16x8_t a, uint16x8_t b)
{
	return vrsraq_n_u16(a, b, 12);
}

uint16x8_t np_vrsraq_n_u16_13(uint16x8_t a, uint16x8_t b)
{
	return vrsraq_n_u16(a, b, 13);
}

uint16x8_t np_vrsraq_n_u16_14(uint16x8_t a, uint16x8_t b)
{
	return vrsraq_n_u16(a, b, 14);
}

uint16x8_t np_vrsraq_n_u16_15(uint16x8_t a, uint16x8_t b)
{
	return vrsraq_n_u16(a, b, 15);
}

uint16x8_t np_vrsraq_n_u16_16(uint16x8_t a, uint16x8_t b)
{
	return vrsraq_n_u16(a, b, 16);
}

uint32x4_t np_vrsraq_n_u32_1(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 1);
}

uint32x4_t np_vrsraq_n_u32_2(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 2);
}

uint32x4_t np_vrsraq_n_u32_3(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 3);
}

uint32x4_t np_vrsraq_n_u32_4(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 4);
}

uint32x4_t np_vrsraq_n_u32_5(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 5);
}

uint32x4_t np_vrsraq_n_u32_6(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 6);
}

uint32x4_t np_vrsraq_n_u32_7(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 7);
}

uint32x4_t np_vrsraq_n_u32_8(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 8);
}

uint32x4_t np_vrsraq_n_u32_9(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 9);
}

uint32x4_t np_vrsraq_n_u32_10(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 10);
}

uint32x4_t np_vrsraq_n_u32_11(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 11);
}

uint32x4_t np_vrsraq_n_u32_12(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 12);
}

uint32x4_t np_vrsraq_n_u32_13(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 13);
}

uint32x4_t np_vrsraq_n_u32_14(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 14);
}

uint32x4_t np_vrsraq_n_u32_15(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 15);
}

uint32x4_t np_vrsraq_n_u32_16(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 16);
}

uint32x4_t np_vrsraq_n_u32_17(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 17);
}

uint32x4_t np_vrsraq_n_u32_18(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 18);
}

uint32x4_t np_vrsraq_n_u32_19(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 19);
}

uint32x4_t np_vrsraq_n_u32_20(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 20);
}

uint32x4_t np_vrsraq_n_u32_21(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 21);
}

uint32x4_t np_vrsraq_n_u32_22(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 22);
}

uint32x4_t np_vrsraq_n_u32_23(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 23);
}

uint32x4_t np_vrsraq_n_u32_24(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 24);
}

uint32x4_t np_vrsraq_n_u32_25(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 25);
}

uint32x4_t np_vrsraq_n_u32_26(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 26);
}

uint32x4_t np_vrsraq_n_u32_27(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 27);
}

uint32x4_t np_vrsraq_n_u32_28(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 28);
}

uint32x4_t np_vrsraq_n_u32_29(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 29);
}

uint32x4_t np_vrsraq_n_u32_30(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 30);
}

uint32x4_t np_vrsraq_n_u32_31(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 31);
}

uint32x4_t np_vrsraq_n_u32_32(uint32x4_t a, uint32x4_t b)
{
	return vrsraq_n_u32(a, b, 32);
}

uint64x2_t np_vrsraq_n_u64_1(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 1);
}

uint64x2_t np_vrsraq_n_u64_2(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 2);
}

uint64x2_t np_vrsraq_n_u64_3(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 3);
}

uint64x2_t np_vrsraq_n_u64_4(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 4);
}

uint64x2_t np_vrsraq_n_u64_5(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 5);
}

uint64x2_t np_vrsraq_n_u64_6(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 6);
}

uint64x2_t np_vrsraq_n_u64_7(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 7);
}

uint64x2_t np_vrsraq_n_u64_8(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 8);
}

uint64x2_t np_vrsraq_n_u64_9(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 9);
}

uint64x2_t np_vrsraq_n_u64_10(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 10);
}

uint64x2_t np_vrsraq_n_u64_11(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 11);
}

uint64x2_t np_vrsraq_n_u64_12(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 12);
}

uint64x2_t np_vrsraq_n_u64_13(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 13);
}

uint64x2_t np_vrsraq_n_u64_14(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 14);
}

uint64x2_t np_vrsraq_n_u64_15(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 15);
}

uint64x2_t np_vrsraq_n_u64_16(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 16);
}

uint64x2_t np_vrsraq_n_u64_17(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 17);
}

uint64x2_t np_vrsraq_n_u64_18(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 18);
}

uint64x2_t np_vrsraq_n_u64_19(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 19);
}

uint64x2_t np_vrsraq_n_u64_20(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 20);
}

uint64x2_t np_vrsraq_n_u64_21(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 21);
}

uint64x2_t np_vrsraq_n_u64_22(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 22);
}

uint64x2_t np_vrsraq_n_u64_23(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 23);
}

uint64x2_t np_vrsraq_n_u64_24(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 24);
}

uint64x2_t np_vrsraq_n_u64_25(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 25);
}

uint64x2_t np_vrsraq_n_u64_26(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 26);
}

uint64x2_t np_vrsraq_n_u64_27(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 27);
}

uint64x2_t np_vrsraq_n_u64_28(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 28);
}

uint64x2_t np_vrsraq_n_u64_29(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 29);
}

uint64x2_t np_vrsraq_n_u64_30(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 30);
}

uint64x2_t np_vrsraq_n_u64_31(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 31);
}

uint64x2_t np_vrsraq_n_u64_32(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 32);
}

uint64x2_t np_vrsraq_n_u64_33(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 33);
}

uint64x2_t np_vrsraq_n_u64_34(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 34);
}

uint64x2_t np_vrsraq_n_u64_35(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 35);
}

uint64x2_t np_vrsraq_n_u64_36(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 36);
}

uint64x2_t np_vrsraq_n_u64_37(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 37);
}

uint64x2_t np_vrsraq_n_u64_38(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 38);
}

uint64x2_t np_vrsraq_n_u64_39(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 39);
}

uint64x2_t np_vrsraq_n_u64_40(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 40);
}

uint64x2_t np_vrsraq_n_u64_41(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 41);
}

uint64x2_t np_vrsraq_n_u64_42(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 42);
}

uint64x2_t np_vrsraq_n_u64_43(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 43);
}

uint64x2_t np_vrsraq_n_u64_44(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 44);
}

uint64x2_t np_vrsraq_n_u64_45(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 45);
}

uint64x2_t np_vrsraq_n_u64_46(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 46);
}

uint64x2_t np_vrsraq_n_u64_47(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 47);
}

uint64x2_t np_vrsraq_n_u64_48(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 48);
}

uint64x2_t np_vrsraq_n_u64_49(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 49);
}

uint64x2_t np_vrsraq_n_u64_50(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 50);
}

uint64x2_t np_vrsraq_n_u64_51(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 51);
}

uint64x2_t np_vrsraq_n_u64_52(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 52);
}

uint64x2_t np_vrsraq_n_u64_53(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 53);
}

uint64x2_t np_vrsraq_n_u64_54(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 54);
}

uint64x2_t np_vrsraq_n_u64_55(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 55);
}

uint64x2_t np_vrsraq_n_u64_56(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 56);
}

uint64x2_t np_vrsraq_n_u64_57(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 57);
}

uint64x2_t np_vrsraq_n_u64_58(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 58);
}

uint64x2_t np_vrsraq_n_u64_59(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 59);
}

uint64x2_t np_vrsraq_n_u64_60(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 60);
}

uint64x2_t np_vrsraq_n_u64_61(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 61);
}

uint64x2_t np_vrsraq_n_u64_62(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 62);
}

uint64x2_t np_vrsraq_n_u64_63(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 63);
}

uint64x2_t np_vrsraq_n_u64_64(uint64x2_t a, uint64x2_t b)
{
	return vrsraq_n_u64(a, b, 64);
}

int8x16_t np_vqshlq_n_s8_0(int8x16_t a)
{
	return vqshlq_n_s8(a, 0);
}

int8x16_t np_vqshlq_n_s8_1(int8x16_t a)
{
	return vqshlq_n_s8(a, 1);
}

int8x16_t np_vqshlq_n_s8_2(int8x16_t a)
{
	return vqshlq_n_s8(a, 2);
}

int8x16_t np_vqshlq_n_s8_3(int8x16_t a)
{
	return vqshlq_n_s8(a, 3);
}

int8x16_t np_vqshlq_n_s8_4(int8x16_t a)
{
	return vqshlq_n_s8(a, 4);
}

int8x16_t np_vqshlq_n_s8_5(int8x16_t a)
{
	return vqshlq_n_s8(a, 5);
}

int8x16_t np_vqshlq_n_s8_6(int8x16_t a)
{
	return vqshlq_n_s8(a, 6);
}

int8x16_t np_vqshlq_n_s8_7(int8x16_t a)
{
	return vqshlq_n_s8(a, 7);
}

int16x8_t np_vqshlq_n_s16_0(int16x8_t a)
{
	return vqshlq_n_s16(a, 0);
}

int16x8_t np_vqshlq_n_s16_1(int16x8_t a)
{
	return vqshlq_n_s16(a, 1);
}

int16x8_t np_vqshlq_n_s16_2(int16x8_t a)
{
	return vqshlq_n_s16(a, 2);
}

int16x8_t np_vqshlq_n_s16_3(int16x8_t a)
{
	return vqshlq_n_s16(a, 3);
}

int16x8_t np_vqshlq_n_s16_4(int16x8_t a)
{
	return vqshlq_n_s16(a, 4);
}

int16x8_t np_vqshlq_n_s16_5(int16x8_t a)
{
	return vqshlq_n_s16(a, 5);
}

int16x8_t np_vqshlq_n_s16_6(int16x8_t a)
{
	return vqshlq_n_s16(a, 6);
}

int16x8_t np_vqshlq_n_s16_7(int16x8_t a)
{
	return vqshlq_n_s16(a, 7);
}

int16x8_t np_vqshlq_n_s16_8(int16x8_t a)
{
	return vqshlq_n_s16(a, 8);
}

int16x8_t np_vqshlq_n_s16_9(int16x8_t a)
{
	return vqshlq_n_s16(a, 9);
}

int16x8_t np_vqshlq_n_s16_10(int16x8_t a)
{
	return vqshlq_n_s16(a, 10);
}

int16x8_t np_vqshlq_n_s16_11(int16x8_t a)
{
	return vqshlq_n_s16(a, 11);
}

int16x8_t np_vqshlq_n_s16_12(int16x8_t a)
{
	return vqshlq_n_s16(a, 12);
}

int16x8_t np_vqshlq_n_s16_13(int16x8_t a)
{
	return vqshlq_n_s16(a, 13);
}

int16x8_t np_vqshlq_n_s16_14(int16x8_t a)
{
	return vqshlq_n_s16(a, 14);
}

int16x8_t np_vqshlq_n_s16_15(int16x8_t a)
{
	return vqshlq_n_s16(a, 15);
}

int32x4_t np_vqshlq_n_s32_0(int32x4_t a)
{
	return vqshlq_n_s32(a, 0);
}

int32x4_t np_vqshlq_n_s32_1(int32x4_t a)
{
	return vqshlq_n_s32(a, 1);
}

int32x4_t np_vqshlq_n_s32_2(int32x4_t a)
{
	return vqshlq_n_s32(a, 2);
}

int32x4_t np_vqshlq_n_s32_3(int32x4_t a)
{
	return vqshlq_n_s32(a, 3);
}

int32x4_t np_vqshlq_n_s32_4(int32x4_t a)
{
	return vqshlq_n_s32(a, 4);
}

int32x4_t np_vqshlq_n_s32_5(int32x4_t a)
{
	return vqshlq_n_s32(a, 5);
}

int32x4_t np_vqshlq_n_s32_6(int32x4_t a)
{
	return vqshlq_n_s32(a, 6);
}

int32x4_t np_vqshlq_n_s32_7(int32x4_t a)
{
	return vqshlq_n_s32(a, 7);
}

int32x4_t np_vqshlq_n_s32_8(int32x4_t a)
{
	return vqshlq_n_s32(a, 8);
}

int32x4_t np_vqshlq_n_s32_9(int32x4_t a)
{
	return vqshlq_n_s32(a, 9);
}

int32x4_t np_vqshlq_n_s32_10(int32x4_t a)
{
	return vqshlq_n_s32(a, 10);
}

int32x4_t np_vqshlq_n_s32_11(int32x4_t a)
{
	return vqshlq_n_s32(a, 11);
}

int32x4_t np_vqshlq_n_s32_12(int32x4_t a)
{
	return vqshlq_n_s32(a, 12);
}

int32x4_t np_vqshlq_n_s32_13(int32x4_t a)
{
	return vqshlq_n_s32(a, 13);
}

int32x4_t np_vqshlq_n_s32_14(int32x4_t a)
{
	return vqshlq_n_s32(a, 14);
}

int32x4_t np_vqshlq_n_s32_15(int32x4_t a)
{
	return vqshlq_n_s32(a, 15);
}

int32x4_t np_vqshlq_n_s32_16(int32x4_t a)
{
	return vqshlq_n_s32(a, 16);
}

int32x4_t np_vqshlq_n_s32_17(int32x4_t a)
{
	return vqshlq_n_s32(a, 17);
}

int32x4_t np_vqshlq_n_s32_18(int32x4_t a)
{
	return vqshlq_n_s32(a, 18);
}

int32x4_t np_vqshlq_n_s32_19(int32x4_t a)
{
	return vqshlq_n_s32(a, 19);
}

int32x4_t np_vqshlq_n_s32_20(int32x4_t a)
{
	return vqshlq_n_s32(a, 20);
}

int32x4_t np_vqshlq_n_s32_21(int32x4_t a)
{
	return vqshlq_n_s32(a, 21);
}

int32x4_t np_vqshlq_n_s32_22(int32x4_t a)
{
	return vqshlq_n_s32(a, 22);
}

int32x4_t np_vqshlq_n_s32_23(int32x4_t a)
{
	return vqshlq_n_s32(a, 23);
}

int32x4_t np_vqshlq_n_s32_24(int32x4_t a)
{
	return vqshlq_n_s32(a, 24);
}

int32x4_t np_vqshlq_n_s32_25(int32x4_t a)
{
	return vqshlq_n_s32(a, 25);
}

int32x4_t np_vqshlq_n_s32_26(int32x4_t a)
{
	return vqshlq_n_s32(a, 26);
}

int32x4_t np_vqshlq_n_s32_27(int32x4_t a)
{
	return vqshlq_n_s32(a, 27);
}

int32x4_t np_vqshlq_n_s32_28(int32x4_t a)
{
	return vqshlq_n_s32(a, 28);
}

int32x4_t np_vqshlq_n_s32_29(int32x4_t a)
{
	return vqshlq_n_s32(a, 29);
}

int32x4_t np_vqshlq_n_s32_30(int32x4_t a)
{
	return vqshlq_n_s32(a, 30);
}

int32x4_t np_vqshlq_n_s32_31(int32x4_t a)
{
	return vqshlq_n_s32(a, 31);
}

int64x2_t np_vqshlq_n_s64_0(int64x2_t a)
{
	return vqshlq_n_s64(a, 0);
}

int64x2_t np_vqshlq_n_s64_1(int64x2_t a)
{
	return vqshlq_n_s64(a, 1);
}

int64x2_t np_vqshlq_n_s64_2(int64x2_t a)
{
	return vqshlq_n_s64(a, 2);
}

int64x2_t np_vqshlq_n_s64_3(int64x2_t a)
{
	return vqshlq_n_s64(a, 3);
}

int64x2_t np_vqshlq_n_s64_4(int64x2_t a)
{
	return vqshlq_n_s64(a, 4);
}

int64x2_t np_vqshlq_n_s64_5(int64x2_t a)
{
	return vqshlq_n_s64(a, 5);
}

int64x2_t np_vqshlq_n_s64_6(int64x2_t a)
{
	return vqshlq_n_s64(a, 6);
}

int64x2_t np_vqshlq_n_s64_7(int64x2_t a)
{
	return vqshlq_n_s64(a, 7);
}

int64x2_t np_vqshlq_n_s64_8(int64x2_t a)
{
	return vqshlq_n_s64(a, 8);
}

int64x2_t np_vqshlq_n_s64_9(int64x2_t a)
{
	return vqshlq_n_s64(a, 9);
}

int64x2_t np_vqshlq_n_s64_10(int64x2_t a)
{
	return vqshlq_n_s64(a, 10);
}

int64x2_t np_vqshlq_n_s64_11(int64x2_t a)
{
	return vqshlq_n_s64(a, 11);
}

int64x2_t np_vqshlq_n_s64_12(int64x2_t a)
{
	return vqshlq_n_s64(a, 12);
}

int64x2_t np_vqshlq_n_s64_13(int64x2_t a)
{
	return vqshlq_n_s64(a, 13);
}

int64x2_t np_vqshlq_n_s64_14(int64x2_t a)
{
	return vqshlq_n_s64(a, 14);
}

int64x2_t np_vqshlq_n_s64_15(int64x2_t a)
{
	return vqshlq_n_s64(a, 15);
}

int64x2_t np_vqshlq_n_s64_16(int64x2_t a)
{
	return vqshlq_n_s64(a, 16);
}

int64x2_t np_vqshlq_n_s64_17(int64x2_t a)
{
	return vqshlq_n_s64(a, 17);
}

int64x2_t np_vqshlq_n_s64_18(int64x2_t a)
{
	return vqshlq_n_s64(a, 18);
}

int64x2_t np_vqshlq_n_s64_19(int64x2_t a)
{
	return vqshlq_n_s64(a, 19);
}

int64x2_t np_vqshlq_n_s64_20(int64x2_t a)
{
	return vqshlq_n_s64(a, 20);
}

int64x2_t np_vqshlq_n_s64_21(int64x2_t a)
{
	return vqshlq_n_s64(a, 21);
}

int64x2_t np_vqshlq_n_s64_22(int64x2_t a)
{
	return vqshlq_n_s64(a, 22);
}

int64x2_t np_vqshlq_n_s64_23(int64x2_t a)
{
	return vqshlq_n_s64(a, 23);
}

int64x2_t np_vqshlq_n_s64_24(int64x2_t a)
{
	return vqshlq_n_s64(a, 24);
}

int64x2_t np_vqshlq_n_s64_25(int64x2_t a)
{
	return vqshlq_n_s64(a, 25);
}

int64x2_t np_vqshlq_n_s64_26(int64x2_t a)
{
	return vqshlq_n_s64(a, 26);
}

int64x2_t np_vqshlq_n_s64_27(int64x2_t a)
{
	return vqshlq_n_s64(a, 27);
}

int64x2_t np_vqshlq_n_s64_28(int64x2_t a)
{
	return vqshlq_n_s64(a, 28);
}

int64x2_t np_vqshlq_n_s64_29(int64x2_t a)
{
	return vqshlq_n_s64(a, 29);
}

int64x2_t np_vqshlq_n_s64_30(int64x2_t a)
{
	return vqshlq_n_s64(a, 30);
}

int64x2_t np_vqshlq_n_s64_31(int64x2_t a)
{
	return vqshlq_n_s64(a, 31);
}

int64x2_t np_vqshlq_n_s64_32(int64x2_t a)
{
	return vqshlq_n_s64(a, 32);
}

int64x2_t np_vqshlq_n_s64_33(int64x2_t a)
{
	return vqshlq_n_s64(a, 33);
}

int64x2_t np_vqshlq_n_s64_34(int64x2_t a)
{
	return vqshlq_n_s64(a, 34);
}

int64x2_t np_vqshlq_n_s64_35(int64x2_t a)
{
	return vqshlq_n_s64(a, 35);
}

int64x2_t np_vqshlq_n_s64_36(int64x2_t a)
{
	return vqshlq_n_s64(a, 36);
}

int64x2_t np_vqshlq_n_s64_37(int64x2_t a)
{
	return vqshlq_n_s64(a, 37);
}

int64x2_t np_vqshlq_n_s64_38(int64x2_t a)
{
	return vqshlq_n_s64(a, 38);
}

int64x2_t np_vqshlq_n_s64_39(int64x2_t a)
{
	return vqshlq_n_s64(a, 39);
}

int64x2_t np_vqshlq_n_s64_40(int64x2_t a)
{
	return vqshlq_n_s64(a, 40);
}

int64x2_t np_vqshlq_n_s64_41(int64x2_t a)
{
	return vqshlq_n_s64(a, 41);
}

int64x2_t np_vqshlq_n_s64_42(int64x2_t a)
{
	return vqshlq_n_s64(a, 42);
}

int64x2_t np_vqshlq_n_s64_43(int64x2_t a)
{
	return vqshlq_n_s64(a, 43);
}

int64x2_t np_vqshlq_n_s64_44(int64x2_t a)
{
	return vqshlq_n_s64(a, 44);
}

int64x2_t np_vqshlq_n_s64_45(int64x2_t a)
{
	return vqshlq_n_s64(a, 45);
}

int64x2_t np_vqshlq_n_s64_46(int64x2_t a)
{
	return vqshlq_n_s64(a, 46);
}

int64x2_t np_vqshlq_n_s64_47(int64x2_t a)
{
	return vqshlq_n_s64(a, 47);
}

int64x2_t np_vqshlq_n_s64_48(int64x2_t a)
{
	return vqshlq_n_s64(a, 48);
}

int64x2_t np_vqshlq_n_s64_49(int64x2_t a)
{
	return vqshlq_n_s64(a, 49);
}

int64x2_t np_vqshlq_n_s64_50(int64x2_t a)
{
	return vqshlq_n_s64(a, 50);
}

int64x2_t np_vqshlq_n_s64_51(int64x2_t a)
{
	return vqshlq_n_s64(a, 51);
}

int64x2_t np_vqshlq_n_s64_52(int64x2_t a)
{
	return vqshlq_n_s64(a, 52);
}

int64x2_t np_vqshlq_n_s64_53(int64x2_t a)
{
	return vqshlq_n_s64(a, 53);
}

int64x2_t np_vqshlq_n_s64_54(int64x2_t a)
{
	return vqshlq_n_s64(a, 54);
}

int64x2_t np_vqshlq_n_s64_55(int64x2_t a)
{
	return vqshlq_n_s64(a, 55);
}

int64x2_t np_vqshlq_n_s64_56(int64x2_t a)
{
	return vqshlq_n_s64(a, 56);
}

int64x2_t np_vqshlq_n_s64_57(int64x2_t a)
{
	return vqshlq_n_s64(a, 57);
}

int64x2_t np_vqshlq_n_s64_58(int64x2_t a)
{
	return vqshlq_n_s64(a, 58);
}

int64x2_t np_vqshlq_n_s64_59(int64x2_t a)
{
	return vqshlq_n_s64(a, 59);
}

int64x2_t np_vqshlq_n_s64_60(int64x2_t a)
{
	return vqshlq_n_s64(a, 60);
}

int64x2_t np_vqshlq_n_s64_61(int64x2_t a)
{
	return vqshlq_n_s64(a, 61);
}

int64x2_t np_vqshlq_n_s64_62(int64x2_t a)
{
	return vqshlq_n_s64(a, 62);
}

int64x2_t np_vqshlq_n_s64_63(int64x2_t a)
{
	return vqshlq_n_s64(a, 63);
}

uint8x16_t np_vqshlq_n_u8_0(uint8x16_t a)
{
	return vqshlq_n_u8(a, 0);
}

uint8x16_t np_vqshlq_n_u8_1(uint8x16_t a)
{
	return vqshlq_n_u8(a, 1);
}

uint8x16_t np_vqshlq_n_u8_2(uint8x16_t a)
{
	return vqshlq_n_u8(a, 2);
}

uint8x16_t np_vqshlq_n_u8_3(uint8x16_t a)
{
	return vqshlq_n_u8(a, 3);
}

uint8x16_t np_vqshlq_n_u8_4(uint8x16_t a)
{
	return vqshlq_n_u8(a, 4);
}

uint8x16_t np_vqshlq_n_u8_5(uint8x16_t a)
{
	return vqshlq_n_u8(a, 5);
}

uint8x16_t np_vqshlq_n_u8_6(uint8x16_t a)
{
	return vqshlq_n_u8(a, 6);
}

uint8x16_t np_vqshlq_n_u8_7(uint8x16_t a)
{
	return vqshlq_n_u8(a, 7);
}

uint16x8_t np_vqshlq_n_u16_0(uint16x8_t a)
{
	return vqshlq_n_u16(a, 0);
}

uint16x8_t np_vqshlq_n_u16_1(uint16x8_t a)
{
	return vqshlq_n_u16(a, 1);
}

uint16x8_t np_vqshlq_n_u16_2(uint16x8_t a)
{
	return vqshlq_n_u16(a, 2);
}

uint16x8_t np_vqshlq_n_u16_3(uint16x8_t a)
{
	return vqshlq_n_u16(a, 3);
}

uint16x8_t np_vqshlq_n_u16_4(uint16x8_t a)
{
	return vqshlq_n_u16(a, 4);
}

uint16x8_t np_vqshlq_n_u16_5(uint16x8_t a)
{
	return vqshlq_n_u16(a, 5);
}

uint16x8_t np_vqshlq_n_u16_6(uint16x8_t a)
{
	return vqshlq_n_u16(a, 6);
}

uint16x8_t np_vqshlq_n_u16_7(uint16x8_t a)
{
	return vqshlq_n_u16(a, 7);
}

uint16x8_t np_vqshlq_n_u16_8(uint16x8_t a)
{
	return vqshlq_n_u16(a, 8);
}

uint16x8_t np_vqshlq_n_u16_9(uint16x8_t a)
{
	return vqshlq_n_u16(a, 9);
}

uint16x8_t np_vqshlq_n_u16_10(uint16x8_t a)
{
	return vqshlq_n_u16(a, 10);
}

uint16x8_t np_vqshlq_n_u16_11(uint16x8_t a)
{
	return vqshlq_n_u16(a, 11);
}

uint16x8_t np_vqshlq_n_u16_12(uint16x8_t a)
{
	return vqshlq_n_u16(a, 12);
}

uint16x8_t np_vqshlq_n_u16_13(uint16x8_t a)
{
	return vqshlq_n_u16(a, 13);
}

uint16x8_t np_vqshlq_n_u16_14(uint16x8_t a)
{
	return vqshlq_n_u16(a, 14);
}

uint16x8_t np_vqshlq_n_u16_15(uint16x8_t a)
{
	return vqshlq_n_u16(a, 15);
}

uint32x4_t np_vqshlq_n_u32_0(uint32x4_t a)
{
	return vqshlq_n_u32(a, 0);
}

uint32x4_t np_vqshlq_n_u32_1(uint32x4_t a)
{
	return vqshlq_n_u32(a, 1);
}

uint32x4_t np_vqshlq_n_u32_2(uint32x4_t a)
{
	return vqshlq_n_u32(a, 2);
}

uint32x4_t np_vqshlq_n_u32_3(uint32x4_t a)
{
	return vqshlq_n_u32(a, 3);
}

uint32x4_t np_vqshlq_n_u32_4(uint32x4_t a)
{
	return vqshlq_n_u32(a, 4);
}

uint32x4_t np_vqshlq_n_u32_5(uint32x4_t a)
{
	return vqshlq_n_u32(a, 5);
}

uint32x4_t np_vqshlq_n_u32_6(uint32x4_t a)
{
	return vqshlq_n_u32(a, 6);
}

uint32x4_t np_vqshlq_n_u32_7(uint32x4_t a)
{
	return vqshlq_n_u32(a, 7);
}

uint32x4_t np_vqshlq_n_u32_8(uint32x4_t a)
{
	return vqshlq_n_u32(a, 8);
}

uint32x4_t np_vqshlq_n_u32_9(uint32x4_t a)
{
	return vqshlq_n_u32(a, 9);
}

uint32x4_t np_vqshlq_n_u32_10(uint32x4_t a)
{
	return vqshlq_n_u32(a, 10);
}

uint32x4_t np_vqshlq_n_u32_11(uint32x4_t a)
{
	return vqshlq_n_u32(a, 11);
}

uint32x4_t np_vqshlq_n_u32_12(uint32x4_t a)
{
	return vqshlq_n_u32(a, 12);
}

uint32x4_t np_vqshlq_n_u32_13(uint32x4_t a)
{
	return vqshlq_n_u32(a, 13);
}

uint32x4_t np_vqshlq_n_u32_14(uint32x4_t a)
{
	return vqshlq_n_u32(a, 14);
}

uint32x4_t np_vqshlq_n_u32_15(uint32x4_t a)
{
	return vqshlq_n_u32(a, 15);
}

uint32x4_t np_vqshlq_n_u32_16(uint32x4_t a)
{
	return vqshlq_n_u32(a, 16);
}

uint32x4_t np_vqshlq_n_u32_17(uint32x4_t a)
{
	return vqshlq_n_u32(a, 17);
}

uint32x4_t np_vqshlq_n_u32_18(uint32x4_t a)
{
	return vqshlq_n_u32(a, 18);
}

uint32x4_t np_vqshlq_n_u32_19(uint32x4_t a)
{
	return vqshlq_n_u32(a, 19);
}

uint32x4_t np_vqshlq_n_u32_20(uint32x4_t a)
{
	return vqshlq_n_u32(a, 20);
}

uint32x4_t np_vqshlq_n_u32_21(uint32x4_t a)
{
	return vqshlq_n_u32(a, 21);
}

uint32x4_t np_vqshlq_n_u32_22(uint32x4_t a)
{
	return vqshlq_n_u32(a, 22);
}

uint32x4_t np_vqshlq_n_u32_23(uint32x4_t a)
{
	return vqshlq_n_u32(a, 23);
}

uint32x4_t np_vqshlq_n_u32_24(uint32x4_t a)
{
	return vqshlq_n_u32(a, 24);
}

uint32x4_t np_vqshlq_n_u32_25(uint32x4_t a)
{
	return vqshlq_n_u32(a, 25);
}

uint32x4_t np_vqshlq_n_u32_26(uint32x4_t a)
{
	return vqshlq_n_u32(a, 26);
}

uint32x4_t np_vqshlq_n_u32_27(uint32x4_t a)
{
	return vqshlq_n_u32(a, 27);
}

uint32x4_t np_vqshlq_n_u32_28(uint32x4_t a)
{
	return vqshlq_n_u32(a, 28);
}

uint32x4_t np_vqshlq_n_u32_29(uint32x4_t a)
{
	return vqshlq_n_u32(a, 29);
}

uint32x4_t np_vqshlq_n_u32_30(uint32x4_t a)
{
	return vqshlq_n_u32(a, 30);
}

uint32x4_t np_vqshlq_n_u32_31(uint32x4_t a)
{
	return vqshlq_n_u32(a, 31);
}

uint64x2_t np_vqshlq_n_u64_0(uint64x2_t a)
{
	return vqshlq_n_u64(a, 0);
}

uint64x2_t np_vqshlq_n_u64_1(uint64x2_t a)
{
	return vqshlq_n_u64(a, 1);
}

uint64x2_t np_vqshlq_n_u64_2(uint64x2_t a)
{
	return vqshlq_n_u64(a, 2);
}

uint64x2_t np_vqshlq_n_u64_3(uint64x2_t a)
{
	return vqshlq_n_u64(a, 3);
}

uint64x2_t np_vqshlq_n_u64_4(uint64x2_t a)
{
	return vqshlq_n_u64(a, 4);
}

uint64x2_t np_vqshlq_n_u64_5(uint64x2_t a)
{
	return vqshlq_n_u64(a, 5);
}

uint64x2_t np_vqshlq_n_u64_6(uint64x2_t a)
{
	return vqshlq_n_u64(a, 6);
}

uint64x2_t np_vqshlq_n_u64_7(uint64x2_t a)
{
	return vqshlq_n_u64(a, 7);
}

uint64x2_t np_vqshlq_n_u64_8(uint64x2_t a)
{
	return vqshlq_n_u64(a, 8);
}

uint64x2_t np_vqshlq_n_u64_9(uint64x2_t a)
{
	return vqshlq_n_u64(a, 9);
}

uint64x2_t np_vqshlq_n_u64_10(uint64x2_t a)
{
	return vqshlq_n_u64(a, 10);
}

uint64x2_t np_vqshlq_n_u64_11(uint64x2_t a)
{
	return vqshlq_n_u64(a, 11);
}

uint64x2_t np_vqshlq_n_u64_12(uint64x2_t a)
{
	return vqshlq_n_u64(a, 12);
}

uint64x2_t np_vqshlq_n_u64_13(uint64x2_t a)
{
	return vqshlq_n_u64(a, 13);
}

uint64x2_t np_vqshlq_n_u64_14(uint64x2_t a)
{
	return vqshlq_n_u64(a, 14);
}

uint64x2_t np_vqshlq_n_u64_15(uint64x2_t a)
{
	return vqshlq_n_u64(a, 15);
}

uint64x2_t np_vqshlq_n_u64_16(uint64x2_t a)
{
	return vqshlq_n_u64(a, 16);
}

uint64x2_t np_vqshlq_n_u64_17(uint64x2_t a)
{
	return vqshlq_n_u64(a, 17);
}

uint64x2_t np_vqshlq_n_u64_18(uint64x2_t a)
{
	return vqshlq_n_u64(a, 18);
}

uint64x2_t np_vqshlq_n_u64_19(uint64x2_t a)
{
	return vqshlq_n_u64(a, 19);
}

uint64x2_t np_vqshlq_n_u64_20(uint64x2_t a)
{
	return vqshlq_n_u64(a, 20);
}

uint64x2_t np_vqshlq_n_u64_21(uint64x2_t a)
{
	return vqshlq_n_u64(a, 21);
}

uint64x2_t np_vqshlq_n_u64_22(uint64x2_t a)
{
	return vqshlq_n_u64(a, 22);
}

uint64x2_t np_vqshlq_n_u64_23(uint64x2_t a)
{
	return vqshlq_n_u64(a, 23);
}

uint64x2_t np_vqshlq_n_u64_24(uint64x2_t a)
{
	return vqshlq_n_u64(a, 24);
}

uint64x2_t np_vqshlq_n_u64_25(uint64x2_t a)
{
	return vqshlq_n_u64(a, 25);
}

uint64x2_t np_vqshlq_n_u64_26(uint64x2_t a)
{
	return vqshlq_n_u64(a, 26);
}

uint64x2_t np_vqshlq_n_u64_27(uint64x2_t a)
{
	return vqshlq_n_u64(a, 27);
}

uint64x2_t np_vqshlq_n_u64_28(uint64x2_t a)
{
	return vqshlq_n_u64(a, 28);
}

uint64x2_t np_vqshlq_n_u64_29(uint64x2_t a)
{
	return vqshlq_n_u64(a, 29);
}

uint64x2_t np_vqshlq_n_u64_30(uint64x2_t a)
{
	return vqshlq_n_u64(a, 30);
}

uint64x2_t np_vqshlq_n_u64_31(uint64x2_t a)
{
	return vqshlq_n_u64(a, 31);
}

uint64x2_t np_vqshlq_n_u64_32(uint64x2_t a)
{
	return vqshlq_n_u64(a, 32);
}

uint64x2_t np_vqshlq_n_u64_33(uint64x2_t a)
{
	return vqshlq_n_u64(a, 33);
}

uint64x2_t np_vqshlq_n_u64_34(uint64x2_t a)
{
	return vqshlq_n_u64(a, 34);
}

uint64x2_t np_vqshlq_n_u64_35(uint64x2_t a)
{
	return vqshlq_n_u64(a, 35);
}

uint64x2_t np_vqshlq_n_u64_36(uint64x2_t a)
{
	return vqshlq_n_u64(a, 36);
}

uint64x2_t np_vqshlq_n_u64_37(uint64x2_t a)
{
	return vqshlq_n_u64(a, 37);
}

uint64x2_t np_vqshlq_n_u64_38(uint64x2_t a)
{
	return vqshlq_n_u64(a, 38);
}

uint64x2_t np_vqshlq_n_u64_39(uint64x2_t a)
{
	return vqshlq_n_u64(a, 39);
}

uint64x2_t np_vqshlq_n_u64_40(uint64x2_t a)
{
	return vqshlq_n_u64(a, 40);
}

uint64x2_t np_vqshlq_n_u64_41(uint64x2_t a)
{
	return vqshlq_n_u64(a, 41);
}

uint64x2_t np_vqshlq_n_u64_42(uint64x2_t a)
{
	return vqshlq_n_u64(a, 42);
}

uint64x2_t np_vqshlq_n_u64_43(uint64x2_t a)
{
	return vqshlq_n_u64(a, 43);
}

uint64x2_t np_vqshlq_n_u64_44(uint64x2_t a)
{
	return vqshlq_n_u64(a, 44);
}

uint64x2_t np_vqshlq_n_u64_45(uint64x2_t a)
{
	return vqshlq_n_u64(a, 45);
}

uint64x2_t np_vqshlq_n_u64_46(uint64x2_t a)
{
	return vqshlq_n_u64(a, 46);
}

uint64x2_t np_vqshlq_n_u64_47(uint64x2_t a)
{
	return vqshlq_n_u64(a, 47);
}

uint64x2_t np_vqshlq_n_u64_48(uint64x2_t a)
{
	return vqshlq_n_u64(a, 48);
}

uint64x2_t np_vqshlq_n_u64_49(uint64x2_t a)
{
	return vqshlq_n_u64(a, 49);
}

uint64x2_t np_vqshlq_n_u64_50(uint64x2_t a)
{
	return vqshlq_n_u64(a, 50);
}

uint64x2_t np_vqshlq_n_u64_51(uint64x2_t a)
{
	return vqshlq_n_u64(a, 51);
}

uint64x2_t np_vqshlq_n_u64_52(uint64x2_t a)
{
	return vqshlq_n_u64(a, 52);
}

uint64x2_t np_vqshlq_n_u64_53(uint64x2_t a)
{
	return vqshlq_n_u64(a, 53);
}

uint64x2_t np_vqshlq_n_u64_54(uint64x2_t a)
{
	return vqshlq_n_u64(a, 54);
}

uint64x2_t np_vqshlq_n_u64_55(uint64x2_t a)
{
	return vqshlq_n_u64(a, 55);
}

uint64x2_t np_vqshlq_n_u64_56(uint64x2_t a)
{
	return vqshlq_n_u64(a, 56);
}

uint64x2_t np_vqshlq_n_u64_57(uint64x2_t a)
{
	return vqshlq_n_u64(a, 57);
}

uint64x2_t np_vqshlq_n_u64_58(uint64x2_t a)
{
	return vqshlq_n_u64(a, 58);
}

uint64x2_t np_vqshlq_n_u64_59(uint64x2_t a)
{
	return vqshlq_n_u64(a, 59);
}

uint64x2_t np_vqshlq_n_u64_60(uint64x2_t a)
{
	return vqshlq_n_u64(a, 60);
}

uint64x2_t np_vqshlq_n_u64_61(uint64x2_t a)
{
	return vqshlq_n_u64(a, 61);
}

uint64x2_t np_vqshlq_n_u64_62(uint64x2_t a)
{
	return vqshlq_n_u64(a, 62);
}

uint64x2_t np_vqshlq_n_u64_63(uint64x2_t a)
{
	return vqshlq_n_u64(a, 63);
}

uint8x16_t np_vqshluq_n_s8_0(int8x16_t a)
{
	return vqshluq_n_s8(a, 0);
}

uint8x16_t np_vqshluq_n_s8_1(int8x16_t a)
{
	return vqshluq_n_s8(a, 1);
}

uint8x16_t np_vqshluq_n_s8_2(int8x16_t a)
{
	return vqshluq_n_s8(a, 2);
}

uint8x16_t np_vqshluq_n_s8_3(int8x16_t a)
{
	return vqshluq_n_s8(a, 3);
}

uint8x16_t np_vqshluq_n_s8_4(int8x16_t a)
{
	return vqshluq_n_s8(a, 4);
}

uint8x16_t np_vqshluq_n_s8_5(int8x16_t a)
{
	return vqshluq_n_s8(a, 5);
}

uint8x16_t np_vqshluq_n_s8_6(int8x16_t a)
{
	return vqshluq_n_s8(a, 6);
}

uint8x16_t np_vqshluq_n_s8_7(int8x16_t a)
{
	return vqshluq_n_s8(a, 7);
}

uint16x8_t np_vqshluq_n_s16_0(int16x8_t a)
{
	return vqshluq_n_s16(a, 0);
}

uint16x8_t np_vqshluq_n_s16_1(int16x8_t a)
{
	return vqshluq_n_s16(a, 1);
}

uint16x8_t np_vqshluq_n_s16_2(int16x8_t a)
{
	return vqshluq_n_s16(a, 2);
}

uint16x8_t np_vqshluq_n_s16_3(int16x8_t a)
{
	return vqshluq_n_s16(a, 3);
}

uint16x8_t np_vqshluq_n_s16_4(int16x8_t a)
{
	return vqshluq_n_s16(a, 4);
}

uint16x8_t np_vqshluq_n_s16_5(int16x8_t a)
{
	return vqshluq_n_s16(a, 5);
}

uint16x8_t np_vqshluq_n_s16_6(int16x8_t a)
{
	return vqshluq_n_s16(a, 6);
}

uint16x8_t np_vqshluq_n_s16_7(int16x8_t a)
{
	return vqshluq_n_s16(a, 7);
}

uint16x8_t np_vqshluq_n_s16_8(int16x8_t a)
{
	return vqshluq_n_s16(a, 8);
}

uint16x8_t np_vqshluq_n_s16_9(int16x8_t a)
{
	return vqshluq_n_s16(a, 9);
}

uint16x8_t np_vqshluq_n_s16_10(int16x8_t a)
{
	return vqshluq_n_s16(a, 10);
}

uint16x8_t np_vqshluq_n_s16_11(int16x8_t a)
{
	return vqshluq_n_s16(a, 11);
}

uint16x8_t np_vqshluq_n_s16_12(int16x8_t a)
{
	return vqshluq_n_s16(a, 12);
}

uint16x8_t np_vqshluq_n_s16_13(int16x8_t a)
{
	return vqshluq_n_s16(a, 13);
}

uint16x8_t np_vqshluq_n_s16_14(int16x8_t a)
{
	return vqshluq_n_s16(a, 14);
}

uint16x8_t np_vqshluq_n_s16_15(int16x8_t a)
{
	return vqshluq_n_s16(a, 15);
}

uint32x4_t np_vqshluq_n_s32_0(int32x4_t a)
{
	return vqshluq_n_s32(a, 0);
}

uint32x4_t np_vqshluq_n_s32_1(int32x4_t a)
{
	return vqshluq_n_s32(a, 1);
}

uint32x4_t np_vqshluq_n_s32_2(int32x4_t a)
{
	return vqshluq_n_s32(a, 2);
}

uint32x4_t np_vqshluq_n_s32_3(int32x4_t a)
{
	return vqshluq_n_s32(a, 3);
}

uint32x4_t np_vqshluq_n_s32_4(int32x4_t a)
{
	return vqshluq_n_s32(a, 4);
}

uint32x4_t np_vqshluq_n_s32_5(int32x4_t a)
{
	return vqshluq_n_s32(a, 5);
}

uint32x4_t np_vqshluq_n_s32_6(int32x4_t a)
{
	return vqshluq_n_s32(a, 6);
}

uint32x4_t np_vqshluq_n_s32_7(int32x4_t a)
{
	return vqshluq_n_s32(a, 7);
}

uint32x4_t np_vqshluq_n_s32_8(int32x4_t a)
{
	return vqshluq_n_s32(a, 8);
}

uint32x4_t np_vqshluq_n_s32_9(int32x4_t a)
{
	return vqshluq_n_s32(a, 9);
}

uint32x4_t np_vqshluq_n_s32_10(int32x4_t a)
{
	return vqshluq_n_s32(a, 10);
}

uint32x4_t np_vqshluq_n_s32_11(int32x4_t a)
{
	return vqshluq_n_s32(a, 11);
}

uint32x4_t np_vqshluq_n_s32_12(int32x4_t a)
{
	return vqshluq_n_s32(a, 12);
}

uint32x4_t np_vqshluq_n_s32_13(int32x4_t a)
{
	return vqshluq_n_s32(a, 13);
}

uint32x4_t np_vqshluq_n_s32_14(int32x4_t a)
{
	return vqshluq_n_s32(a, 14);
}

uint32x4_t np_vqshluq_n_s32_15(int32x4_t a)
{
	return vqshluq_n_s32(a, 15);
}

uint32x4_t np_vqshluq_n_s32_16(int32x4_t a)
{
	return vqshluq_n_s32(a, 16);
}

uint32x4_t np_vqshluq_n_s32_17(int32x4_t a)
{
	return vqshluq_n_s32(a, 17);
}

uint32x4_t np_vqshluq_n_s32_18(int32x4_t a)
{
	return vqshluq_n_s32(a, 18);
}

uint32x4_t np_vqshluq_n_s32_19(int32x4_t a)
{
	return vqshluq_n_s32(a, 19);
}

uint32x4_t np_vqshluq_n_s32_20(int32x4_t a)
{
	return vqshluq_n_s32(a, 20);
}

uint32x4_t np_vqshluq_n_s32_21(int32x4_t a)
{
	return vqshluq_n_s32(a, 21);
}

uint32x4_t np_vqshluq_n_s32_22(int32x4_t a)
{
	return vqshluq_n_s32(a, 22);
}

uint32x4_t np_vqshluq_n_s32_23(int32x4_t a)
{
	return vqshluq_n_s32(a, 23);
}

uint32x4_t np_vqshluq_n_s32_24(int32x4_t a)
{
	return vqshluq_n_s32(a, 24);
}

uint32x4_t np_vqshluq_n_s32_25(int32x4_t a)
{
	return vqshluq_n_s32(a, 25);
}

uint32x4_t np_vqshluq_n_s32_26(int32x4_t a)
{
	return vqshluq_n_s32(a, 26);
}

uint32x4_t np_vqshluq_n_s32_27(int32x4_t a)
{
	return vqshluq_n_s32(a, 27);
}

uint32x4_t np_vqshluq_n_s32_28(int32x4_t a)
{
	return vqshluq_n_s32(a, 28);
}

uint32x4_t np_vqshluq_n_s32_29(int32x4_t a)
{
	return vqshluq_n_s32(a, 29);
}

uint32x4_t np_vqshluq_n_s32_30(int32x4_t a)
{
	return vqshluq_n_s32(a, 30);
}

uint32x4_t np_vqshluq_n_s32_31(int32x4_t a)
{
	return vqshluq_n_s32(a, 31);
}

uint64x2_t np_vqshluq_n_s64_0(int64x2_t a)
{
	return vqshluq_n_s64(a, 0);
}

uint64x2_t np_vqshluq_n_s64_1(int64x2_t a)
{
	return vqshluq_n_s64(a, 1);
}

uint64x2_t np_vqshluq_n_s64_2(int64x2_t a)
{
	return vqshluq_n_s64(a, 2);
}

uint64x2_t np_vqshluq_n_s64_3(int64x2_t a)
{
	return vqshluq_n_s64(a, 3);
}

uint64x2_t np_vqshluq_n_s64_4(int64x2_t a)
{
	return vqshluq_n_s64(a, 4);
}

uint64x2_t np_vqshluq_n_s64_5(int64x2_t a)
{
	return vqshluq_n_s64(a, 5);
}

uint64x2_t np_vqshluq_n_s64_6(int64x2_t a)
{
	return vqshluq_n_s64(a, 6);
}

uint64x2_t np_vqshluq_n_s64_7(int64x2_t a)
{
	return vqshluq_n_s64(a, 7);
}

uint64x2_t np_vqshluq_n_s64_8(int64x2_t a)
{
	return vqshluq_n_s64(a, 8);
}

uint64x2_t np_vqshluq_n_s64_9(int64x2_t a)
{
	return vqshluq_n_s64(a, 9);
}

uint64x2_t np_vqshluq_n_s64_10(int64x2_t a)
{
	return vqshluq_n_s64(a, 10);
}

uint64x2_t np_vqshluq_n_s64_11(int64x2_t a)
{
	return vqshluq_n_s64(a, 11);
}

uint64x2_t np_vqshluq_n_s64_12(int64x2_t a)
{
	return vqshluq_n_s64(a, 12);
}

uint64x2_t np_vqshluq_n_s64_13(int64x2_t a)
{
	return vqshluq_n_s64(a, 13);
}

uint64x2_t np_vqshluq_n_s64_14(int64x2_t a)
{
	return vqshluq_n_s64(a, 14);
}

uint64x2_t np_vqshluq_n_s64_15(int64x2_t a)
{
	return vqshluq_n_s64(a, 15);
}

uint64x2_t np_vqshluq_n_s64_16(int64x2_t a)
{
	return vqshluq_n_s64(a, 16);
}

uint64x2_t np_vqshluq_n_s64_17(int64x2_t a)
{
	return vqshluq_n_s64(a, 17);
}

uint64x2_t np_vqshluq_n_s64_18(int64x2_t a)
{
	return vqshluq_n_s64(a, 18);
}

uint64x2_t np_vqshluq_n_s64_19(int64x2_t a)
{
	return vqshluq_n_s64(a, 19);
}

uint64x2_t np_vqshluq_n_s64_20(int64x2_t a)
{
	return vqshluq_n_s64(a, 20);
}

uint64x2_t np_vqshluq_n_s64_21(int64x2_t a)
{
	return vqshluq_n_s64(a, 21);
}

uint64x2_t np_vqshluq_n_s64_22(int64x2_t a)
{
	return vqshluq_n_s64(a, 22);
}

uint64x2_t np_vqshluq_n_s64_23(int64x2_t a)
{
	return vqshluq_n_s64(a, 23);
}

uint64x2_t np_vqshluq_n_s64_24(int64x2_t a)
{
	return vqshluq_n_s64(a, 24);
}

uint64x2_t np_vqshluq_n_s64_25(int64x2_t a)
{
	return vqshluq_n_s64(a, 25);
}

uint64x2_t np_vqshluq_n_s64_26(int64x2_t a)
{
	return vqshluq_n_s64(a, 26);
}

uint64x2_t np_vqshluq_n_s64_27(int64x2_t a)
{
	return vqshluq_n_s64(a, 27);
}

uint64x2_t np_vqshluq_n_s64_28(int64x2_t a)
{
	return vqshluq_n_s64(a, 28);
}

uint64x2_t np_vqshluq_n_s64_29(int64x2_t a)
{
	return vqshluq_n_s64(a, 29);
}

uint64x2_t np_vqshluq_n_s64_30(int64x2_t a)
{
	return vqshluq_n_s64(a, 30);
}

uint64x2_t np_vqshluq_n_s64_31(int64x2_t a)
{
	return vqshluq_n_s64(a, 31);
}

uint64x2_t np_vqshluq_n_s64_32(int64x2_t a)
{
	return vqshluq_n_s64(a, 32);
}

uint64x2_t np_vqshluq_n_s64_33(int64x2_t a)
{
	return vqshluq_n_s64(a, 33);
}

uint64x2_t np_vqshluq_n_s64_34(int64x2_t a)
{
	return vqshluq_n_s64(a, 34);
}

uint64x2_t np_vqshluq_n_s64_35(int64x2_t a)
{
	return vqshluq_n_s64(a, 35);
}

uint64x2_t np_vqshluq_n_s64_36(int64x2_t a)
{
	return vqshluq_n_s64(a, 36);
}

uint64x2_t np_vqshluq_n_s64_37(int64x2_t a)
{
	return vqshluq_n_s64(a, 37);
}

uint64x2_t np_vqshluq_n_s64_38(int64x2_t a)
{
	return vqshluq_n_s64(a, 38);
}

uint64x2_t np_vqshluq_n_s64_39(int64x2_t a)
{
	return vqshluq_n_s64(a, 39);
}

uint64x2_t np_vqshluq_n_s64_40(int64x2_t a)
{
	return vqshluq_n_s64(a, 40);
}

uint64x2_t np_vqshluq_n_s64_41(int64x2_t a)
{
	return vqshluq_n_s64(a, 41);
}

uint64x2_t np_vqshluq_n_s64_42(int64x2_t a)
{
	return vqshluq_n_s64(a, 42);
}

uint64x2_t np_vqshluq_n_s64_43(int64x2_t a)
{
	return vqshluq_n_s64(a, 43);
}

uint64x2_t np_vqshluq_n_s64_44(int64x2_t a)
{
	return vqshluq_n_s64(a, 44);
}

uint64x2_t np_vqshluq_n_s64_45(int64x2_t a)
{
	return vqshluq_n_s64(a, 45);
}

uint64x2_t np_vqshluq_n_s64_46(int64x2_t a)
{
	return vqshluq_n_s64(a, 46);
}

uint64x2_t np_vqshluq_n_s64_47(int64x2_t a)
{
	return vqshluq_n_s64(a, 47);
}

uint64x2_t np_vqshluq_n_s64_48(int64x2_t a)
{
	return vqshluq_n_s64(a, 48);
}

uint64x2_t np_vqshluq_n_s64_49(int64x2_t a)
{
	return vqshluq_n_s64(a, 49);
}

uint64x2_t np_vqshluq_n_s64_50(int64x2_t a)
{
	return vqshluq_n_s64(a, 50);
}

uint64x2_t np_vqshluq_n_s64_51(int64x2_t a)
{
	return vqshluq_n_s64(a, 51);
}

uint64x2_t np_vqshluq_n_s64_52(int64x2_t a)
{
	return vqshluq_n_s64(a, 52);
}

uint64x2_t np_vqshluq_n_s64_53(int64x2_t a)
{
	return vqshluq_n_s64(a, 53);
}

uint64x2_t np_vqshluq_n_s64_54(int64x2_t a)
{
	return vqshluq_n_s64(a, 54);
}

uint64x2_t np_vqshluq_n_s64_55(int64x2_t a)
{
	return vqshluq_n_s64(a, 55);
}

uint64x2_t np_vqshluq_n_s64_56(int64x2_t a)
{
	return vqshluq_n_s64(a, 56);
}

uint64x2_t np_vqshluq_n_s64_57(int64x2_t a)
{
	return vqshluq_n_s64(a, 57);
}

uint64x2_t np_vqshluq_n_s64_58(int64x2_t a)
{
	return vqshluq_n_s64(a, 58);
}

uint64x2_t np_vqshluq_n_s64_59(int64x2_t a)
{
	return vqshluq_n_s64(a, 59);
}

uint64x2_t np_vqshluq_n_s64_60(int64x2_t a)
{
	return vqshluq_n_s64(a, 60);
}

uint64x2_t np_vqshluq_n_s64_61(int64x2_t a)
{
	return vqshluq_n_s64(a, 61);
}

uint64x2_t np_vqshluq_n_s64_62(int64x2_t a)
{
	return vqshluq_n_s64(a, 62);
}

uint64x2_t np_vqshluq_n_s64_63(int64x2_t a)
{
	return vqshluq_n_s64(a, 63);
}

int8x16_t np_vsriq_n_s8_1(int8x16_t a, int8x16_t b)
{
	return vsriq_n_s8(a, b, 1);
}

int8x16_t np_vsriq_n_s8_2(int8x16_t a, int8x16_t b)
{
	return vsriq_n_s8(a, b, 2);
}

int8x16_t np_vsriq_n_s8_3(int8x16_t a, int8x16_t b)
{
	return vsriq_n_s8(a, b, 3);
}

int8x16_t np_vsriq_n_s8_4(int8x16_t a, int8x16_t b)
{
	return vsriq_n_s8(a, b, 4);
}

int8x16_t np_vsriq_n_s8_5(int8x16_t a, int8x16_t b)
{
	return vsriq_n_s8(a, b, 5);
}

int8x16_t np_vsriq_n_s8_6(int8x16_t a, int8x16_t b)
{
	return vsriq_n_s8(a, b, 6);
}

int8x16_t np_vsriq_n_s8_7(int8x16_t a, int8x16_t b)
{
	return vsriq_n_s8(a, b, 7);
}

int8x16_t np_vsriq_n_s8_8(int8x16_t a, int8x16_t b)
{
	return vsriq_n_s8(a, b, 8);
}

int16x8_t np_vsriq_n_s16_1(int16x8_t a, int16x8_t b)
{
	return vsriq_n_s16(a, b, 1);
}

int16x8_t np_vsriq_n_s16_2(int16x8_t a, int16x8_t b)
{
	return vsriq_n_s16(a, b, 2);
}

int16x8_t np_vsriq_n_s16_3(int16x8_t a, int16x8_t b)
{
	return vsriq_n_s16(a, b, 3);
}

int16x8_t np_vsriq_n_s16_4(int16x8_t a, int16x8_t b)
{
	return vsriq_n_s16(a, b, 4);
}

int16x8_t np_vsriq_n_s16_5(int16x8_t a, int16x8_t b)
{
	return vsriq_n_s16(a, b, 5);
}

int16x8_t np_vsriq_n_s16_6(int16x8_t a, int16x8_t b)
{
	return vsriq_n_s16(a, b, 6);
}

int16x8_t np_vsriq_n_s16_7(int16x8_t a, int16x8_t b)
{
	return vsriq_n_s16(a, b, 7);
}

int16x8_t np_vsriq_n_s16_8(int16x8_t a, int16x8_t b)
{
	return vsriq_n_s16(a, b, 8);
}

int16x8_t np_vsriq_n_s16_9(int16x8_t a, int16x8_t b)
{
	return vsriq_n_s16(a, b, 9);
}

int16x8_t np_vsriq_n_s16_10(int16x8_t a, int16x8_t b)
{
	return vsriq_n_s16(a, b, 10);
}

int16x8_t np_vsriq_n_s16_11(int16x8_t a, int16x8_t b)
{
	return vsriq_n_s16(a, b, 11);
}

int16x8_t np_vsriq_n_s16_12(int16x8_t a, int16x8_t b)
{
	return vsriq_n_s16(a, b, 12);
}

int16x8_t np_vsriq_n_s16_13(int16x8_t a, int16x8_t b)
{
	return vsriq_n_s16(a, b, 13);
}

int16x8_t np_vsriq_n_s16_14(int16x8_t a, int16x8_t b)
{
	return vsriq_n_s16(a, b, 14);
}

int16x8_t np_vsriq_n_s16_15(int16x8_t a, int16x8_t b)
{
	return vsriq_n_s16(a, b, 15);
}

int16x8_t np_vsriq_n_s16_16(int16x8_t a, int16x8_t b)
{
	return vsriq_n_s16(a, b, 16);
}

int32x4_t np_vsriq_n_s32_1(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 1);
}

int32x4_t np_vsriq_n_s32_2(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 2);
}

int32x4_t np_vsriq_n_s32_3(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 3);
}

int32x4_t np_vsriq_n_s32_4(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 4);
}

int32x4_t np_vsriq_n_s32_5(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 5);
}

int32x4_t np_vsriq_n_s32_6(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 6);
}

int32x4_t np_vsriq_n_s32_7(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 7);
}

int32x4_t np_vsriq_n_s32_8(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 8);
}

int32x4_t np_vsriq_n_s32_9(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 9);
}

int32x4_t np_vsriq_n_s32_10(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 10);
}

int32x4_t np_vsriq_n_s32_11(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 11);
}

int32x4_t np_vsriq_n_s32_12(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 12);
}

int32x4_t np_vsriq_n_s32_13(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 13);
}

int32x4_t np_vsriq_n_s32_14(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 14);
}

int32x4_t np_vsriq_n_s32_15(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 15);
}

int32x4_t np_vsriq_n_s32_16(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 16);
}

int32x4_t np_vsriq_n_s32_17(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 17);
}

int32x4_t np_vsriq_n_s32_18(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 18);
}

int32x4_t np_vsriq_n_s32_19(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 19);
}

int32x4_t np_vsriq_n_s32_20(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 20);
}

int32x4_t np_vsriq_n_s32_21(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 21);
}

int32x4_t np_vsriq_n_s32_22(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 22);
}

int32x4_t np_vsriq_n_s32_23(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 23);
}

int32x4_t np_vsriq_n_s32_24(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 24);
}

int32x4_t np_vsriq_n_s32_25(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 25);
}

int32x4_t np_vsriq_n_s32_26(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 26);
}

int32x4_t np_vsriq_n_s32_27(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 27);
}

int32x4_t np_vsriq_n_s32_28(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 28);
}

int32x4_t np_vsriq_n_s32_29(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 29);
}

int32x4_t np_vsriq_n_s32_30(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 30);
}

int32x4_t np_vsriq_n_s32_31(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 31);
}

int32x4_t np_vsriq_n_s32_32(int32x4_t a, int32x4_t b)
{
	return vsriq_n_s32(a, b, 32);
}

int64x2_t np_vsriq_n_s64_1(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 1);
}

int64x2_t np_vsriq_n_s64_2(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 2);
}

int64x2_t np_vsriq_n_s64_3(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 3);
}

int64x2_t np_vsriq_n_s64_4(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 4);
}

int64x2_t np_vsriq_n_s64_5(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 5);
}

int64x2_t np_vsriq_n_s64_6(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 6);
}

int64x2_t np_vsriq_n_s64_7(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 7);
}

int64x2_t np_vsriq_n_s64_8(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 8);
}

int64x2_t np_vsriq_n_s64_9(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 9);
}

int64x2_t np_vsriq_n_s64_10(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 10);
}

int64x2_t np_vsriq_n_s64_11(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 11);
}

int64x2_t np_vsriq_n_s64_12(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 12);
}

int64x2_t np_vsriq_n_s64_13(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 13);
}

int64x2_t np_vsriq_n_s64_14(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 14);
}

int64x2_t np_vsriq_n_s64_15(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 15);
}

int64x2_t np_vsriq_n_s64_16(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 16);
}

int64x2_t np_vsriq_n_s64_17(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 17);
}

int64x2_t np_vsriq_n_s64_18(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 18);
}

int64x2_t np_vsriq_n_s64_19(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 19);
}

int64x2_t np_vsriq_n_s64_20(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 20);
}

int64x2_t np_vsriq_n_s64_21(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 21);
}

int64x2_t np_vsriq_n_s64_22(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 22);
}

int64x2_t np_vsriq_n_s64_23(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 23);
}

int64x2_t np_vsriq_n_s64_24(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 24);
}

int64x2_t np_vsriq_n_s64_25(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 25);
}

int64x2_t np_vsriq_n_s64_26(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 26);
}

int64x2_t np_vsriq_n_s64_27(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 27);
}

int64x2_t np_vsriq_n_s64_28(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 28);
}

int64x2_t np_vsriq_n_s64_29(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 29);
}

int64x2_t np_vsriq_n_s64_30(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 30);
}

int64x2_t np_vsriq_n_s64_31(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 31);
}

int64x2_t np_vsriq_n_s64_32(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 32);
}

int64x2_t np_vsriq_n_s64_33(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 33);
}

int64x2_t np_vsriq_n_s64_34(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 34);
}

int64x2_t np_vsriq_n_s64_35(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 35);
}

int64x2_t np_vsriq_n_s64_36(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 36);
}

int64x2_t np_vsriq_n_s64_37(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 37);
}

int64x2_t np_vsriq_n_s64_38(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 38);
}

int64x2_t np_vsriq_n_s64_39(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 39);
}

int64x2_t np_vsriq_n_s64_40(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 40);
}

int64x2_t np_vsriq_n_s64_41(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 41);
}

int64x2_t np_vsriq_n_s64_42(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 42);
}

int64x2_t np_vsriq_n_s64_43(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 43);
}

int64x2_t np_vsriq_n_s64_44(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 44);
}

int64x2_t np_vsriq_n_s64_45(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 45);
}

int64x2_t np_vsriq_n_s64_46(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 46);
}

int64x2_t np_vsriq_n_s64_47(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 47);
}

int64x2_t np_vsriq_n_s64_48(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 48);
}

int64x2_t np_vsriq_n_s64_49(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 49);
}

int64x2_t np_vsriq_n_s64_50(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 50);
}

int64x2_t np_vsriq_n_s64_51(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 51);
}

int64x2_t np_vsriq_n_s64_52(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 52);
}

int64x2_t np_vsriq_n_s64_53(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 53);
}

int64x2_t np_vsriq_n_s64_54(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 54);
}

int64x2_t np_vsriq_n_s64_55(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 55);
}

int64x2_t np_vsriq_n_s64_56(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 56);
}

int64x2_t np_vsriq_n_s64_57(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 57);
}

int64x2_t np_vsriq_n_s64_58(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 58);
}

int64x2_t np_vsriq_n_s64_59(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 59);
}

int64x2_t np_vsriq_n_s64_60(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 60);
}

int64x2_t np_vsriq_n_s64_61(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 61);
}

int64x2_t np_vsriq_n_s64_62(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 62);
}

int64x2_t np_vsriq_n_s64_63(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 63);
}

int64x2_t np_vsriq_n_s64_64(int64x2_t a, int64x2_t b)
{
	return vsriq_n_s64(a, b, 64);
}

uint8x16_t np_vsriq_n_u8_1(uint8x16_t a, uint8x16_t b)
{
	return vsriq_n_u8(a, b, 1);
}

uint8x16_t np_vsriq_n_u8_2(uint8x16_t a, uint8x16_t b)
{
	return vsriq_n_u8(a, b, 2);
}

uint8x16_t np_vsriq_n_u8_3(uint8x16_t a, uint8x16_t b)
{
	return vsriq_n_u8(a, b, 3);
}

uint8x16_t np_vsriq_n_u8_4(uint8x16_t a, uint8x16_t b)
{
	return vsriq_n_u8(a, b, 4);
}

uint8x16_t np_vsriq_n_u8_5(uint8x16_t a, uint8x16_t b)
{
	return vsriq_n_u8(a, b, 5);
}

uint8x16_t np_vsriq_n_u8_6(uint8x16_t a, uint8x16_t b)
{
	return vsriq_n_u8(a, b, 6);
}

uint8x16_t np_vsriq_n_u8_7(uint8x16_t a, uint8x16_t b)
{
	return vsriq_n_u8(a, b, 7);
}

uint8x16_t np_vsriq_n_u8_8(uint8x16_t a, uint8x16_t b)
{
	return vsriq_n_u8(a, b, 8);
}

uint16x8_t np_vsriq_n_u16_1(uint16x8_t a, uint16x8_t b)
{
	return vsriq_n_u16(a, b, 1);
}

uint16x8_t np_vsriq_n_u16_2(uint16x8_t a, uint16x8_t b)
{
	return vsriq_n_u16(a, b, 2);
}

uint16x8_t np_vsriq_n_u16_3(uint16x8_t a, uint16x8_t b)
{
	return vsriq_n_u16(a, b, 3);
}

uint16x8_t np_vsriq_n_u16_4(uint16x8_t a, uint16x8_t b)
{
	return vsriq_n_u16(a, b, 4);
}

uint16x8_t np_vsriq_n_u16_5(uint16x8_t a, uint16x8_t b)
{
	return vsriq_n_u16(a, b, 5);
}

uint16x8_t np_vsriq_n_u16_6(uint16x8_t a, uint16x8_t b)
{
	return vsriq_n_u16(a, b, 6);
}

uint16x8_t np_vsriq_n_u16_7(uint16x8_t a, uint16x8_t b)
{
	return vsriq_n_u16(a, b, 7);
}

uint16x8_t np_vsriq_n_u16_8(uint16x8_t a, uint16x8_t b)
{
	return vsriq_n_u16(a, b, 8);
}

uint16x8_t np_vsriq_n_u16_9(uint16x8_t a, uint16x8_t b)
{
	return vsriq_n_u16(a, b, 9);
}

uint16x8_t np_vsriq_n_u16_10(uint16x8_t a, uint16x8_t b)
{
	return vsriq_n_u16(a, b, 10);
}

uint16x8_t np_vsriq_n_u16_11(uint16x8_t a, uint16x8_t b)
{
	return vsriq_n_u16(a, b, 11);
}

uint16x8_t np_vsriq_n_u16_12(uint16x8_t a, uint16x8_t b)
{
	return vsriq_n_u16(a, b, 12);
}

uint16x8_t np_vsriq_n_u16_13(uint16x8_t a, uint16x8_t b)
{
	return vsriq_n_u16(a, b, 13);
}

uint16x8_t np_vsriq_n_u16_14(uint16x8_t a, uint16x8_t b)
{
	return vsriq_n_u16(a, b, 14);
}

uint16x8_t np_vsriq_n_u16_15(uint16x8_t a, uint16x8_t b)
{
	return vsriq_n_u16(a, b, 15);
}

uint16x8_t np_vsriq_n_u16_16(uint16x8_t a, uint16x8_t b)
{
	return vsriq_n_u16(a, b, 16);
}

uint32x4_t np_vsriq_n_u32_1(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 1);
}

uint32x4_t np_vsriq_n_u32_2(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 2);
}

uint32x4_t np_vsriq_n_u32_3(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 3);
}

uint32x4_t np_vsriq_n_u32_4(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 4);
}

uint32x4_t np_vsriq_n_u32_5(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 5);
}

uint32x4_t np_vsriq_n_u32_6(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 6);
}

uint32x4_t np_vsriq_n_u32_7(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 7);
}

uint32x4_t np_vsriq_n_u32_8(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 8);
}

uint32x4_t np_vsriq_n_u32_9(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 9);
}

uint32x4_t np_vsriq_n_u32_10(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 10);
}

uint32x4_t np_vsriq_n_u32_11(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 11);
}

uint32x4_t np_vsriq_n_u32_12(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 12);
}

uint32x4_t np_vsriq_n_u32_13(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 13);
}

uint32x4_t np_vsriq_n_u32_14(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 14);
}

uint32x4_t np_vsriq_n_u32_15(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 15);
}

uint32x4_t np_vsriq_n_u32_16(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 16);
}

uint32x4_t np_vsriq_n_u32_17(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 17);
}

uint32x4_t np_vsriq_n_u32_18(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 18);
}

uint32x4_t np_vsriq_n_u32_19(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 19);
}

uint32x4_t np_vsriq_n_u32_20(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 20);
}

uint32x4_t np_vsriq_n_u32_21(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 21);
}

uint32x4_t np_vsriq_n_u32_22(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 22);
}

uint32x4_t np_vsriq_n_u32_23(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 23);
}

uint32x4_t np_vsriq_n_u32_24(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 24);
}

uint32x4_t np_vsriq_n_u32_25(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 25);
}

uint32x4_t np_vsriq_n_u32_26(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 26);
}

uint32x4_t np_vsriq_n_u32_27(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 27);
}

uint32x4_t np_vsriq_n_u32_28(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 28);
}

uint32x4_t np_vsriq_n_u32_29(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 29);
}

uint32x4_t np_vsriq_n_u32_30(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 30);
}

uint32x4_t np_vsriq_n_u32_31(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 31);
}

uint32x4_t np_vsriq_n_u32_32(uint32x4_t a, uint32x4_t b)
{
	return vsriq_n_u32(a, b, 32);
}

uint64x2_t np_vsriq_n_u64_1(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 1);
}

uint64x2_t np_vsriq_n_u64_2(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 2);
}

uint64x2_t np_vsriq_n_u64_3(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 3);
}

uint64x2_t np_vsriq_n_u64_4(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 4);
}

uint64x2_t np_vsriq_n_u64_5(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 5);
}

uint64x2_t np_vsriq_n_u64_6(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 6);
}

uint64x2_t np_vsriq_n_u64_7(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 7);
}

uint64x2_t np_vsriq_n_u64_8(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 8);
}

uint64x2_t np_vsriq_n_u64_9(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 9);
}

uint64x2_t np_vsriq_n_u64_10(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 10);
}

uint64x2_t np_vsriq_n_u64_11(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 11);
}

uint64x2_t np_vsriq_n_u64_12(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 12);
}

uint64x2_t np_vsriq_n_u64_13(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 13);
}

uint64x2_t np_vsriq_n_u64_14(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 14);
}

uint64x2_t np_vsriq_n_u64_15(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 15);
}

uint64x2_t np_vsriq_n_u64_16(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 16);
}

uint64x2_t np_vsriq_n_u64_17(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 17);
}

uint64x2_t np_vsriq_n_u64_18(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 18);
}

uint64x2_t np_vsriq_n_u64_19(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 19);
}

uint64x2_t np_vsriq_n_u64_20(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 20);
}

uint64x2_t np_vsriq_n_u64_21(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 21);
}

uint64x2_t np_vsriq_n_u64_22(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 22);
}

uint64x2_t np_vsriq_n_u64_23(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 23);
}

uint64x2_t np_vsriq_n_u64_24(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 24);
}

uint64x2_t np_vsriq_n_u64_25(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 25);
}

uint64x2_t np_vsriq_n_u64_26(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 26);
}

uint64x2_t np_vsriq_n_u64_27(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 27);
}

uint64x2_t np_vsriq_n_u64_28(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 28);
}

uint64x2_t np_vsriq_n_u64_29(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 29);
}

uint64x2_t np_vsriq_n_u64_30(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 30);
}

uint64x2_t np_vsriq_n_u64_31(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 31);
}

uint64x2_t np_vsriq_n_u64_32(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 32);
}

uint64x2_t np_vsriq_n_u64_33(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 33);
}

uint64x2_t np_vsriq_n_u64_34(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 34);
}

uint64x2_t np_vsriq_n_u64_35(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 35);
}

uint64x2_t np_vsriq_n_u64_36(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 36);
}

uint64x2_t np_vsriq_n_u64_37(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 37);
}

uint64x2_t np_vsriq_n_u64_38(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 38);
}

uint64x2_t np_vsriq_n_u64_39(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 39);
}

uint64x2_t np_vsriq_n_u64_40(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 40);
}

uint64x2_t np_vsriq_n_u64_41(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 41);
}

uint64x2_t np_vsriq_n_u64_42(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 42);
}

uint64x2_t np_vsriq_n_u64_43(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 43);
}

uint64x2_t np_vsriq_n_u64_44(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 44);
}

uint64x2_t np_vsriq_n_u64_45(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 45);
}

uint64x2_t np_vsriq_n_u64_46(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 46);
}

uint64x2_t np_vsriq_n_u64_47(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 47);
}

uint64x2_t np_vsriq_n_u64_48(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 48);
}

uint64x2_t np_vsriq_n_u64_49(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 49);
}

uint64x2_t np_vsriq_n_u64_50(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 50);
}

uint64x2_t np_vsriq_n_u64_51(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 51);
}

uint64x2_t np_vsriq_n_u64_52(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 52);
}

uint64x2_t np_vsriq_n_u64_53(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 53);
}

uint64x2_t np_vsriq_n_u64_54(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 54);
}

uint64x2_t np_vsriq_n_u64_55(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 55);
}

uint64x2_t np_vsriq_n_u64_56(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 56);
}

uint64x2_t np_vsriq_n_u64_57(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 57);
}

uint64x2_t np_vsriq_n_u64_58(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 58);
}

uint64x2_t np_vsriq_n_u64_59(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 59);
}

uint64x2_t np_vsriq_n_u64_60(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 60);
}

uint64x2_t np_vsriq_n_u64_61(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 61);
}

uint64x2_t np_vsriq_n_u64_62(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 62);
}

uint64x2_t np_vsriq_n_u64_63(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 63);
}

uint64x2_t np_vsriq_n_u64_64(uint64x2_t a, uint64x2_t b)
{
	return vsriq_n_u64(a, b, 64);
}

poly8x16_t np_vsriq_n_p8_1(poly8x16_t a, poly8x16_t b)
{
	return vsriq_n_p8(a, b, 1);
}

poly8x16_t np_vsriq_n_p8_2(poly8x16_t a, poly8x16_t b)
{
	return vsriq_n_p8(a, b, 2);
}

poly8x16_t np_vsriq_n_p8_3(poly8x16_t a, poly8x16_t b)
{
	return vsriq_n_p8(a, b, 3);
}

poly8x16_t np_vsriq_n_p8_4(poly8x16_t a, poly8x16_t b)
{
	return vsriq_n_p8(a, b, 4);
}

poly8x16_t np_vsriq_n_p8_5(poly8x16_t a, poly8x16_t b)
{
	return vsriq_n_p8(a, b, 5);
}

poly8x16_t np_vsriq_n_p8_6(poly8x16_t a, poly8x16_t b)
{
	return vsriq_n_p8(a, b, 6);
}

poly8x16_t np_vsriq_n_p8_7(poly8x16_t a, poly8x16_t b)
{
	return vsriq_n_p8(a, b, 7);
}

poly8x16_t np_vsriq_n_p8_8(poly8x16_t a, poly8x16_t b)
{
	return vsriq_n_p8(a, b, 8);
}

poly16x8_t np_vsriq_n_p16_1(poly16x8_t a, poly16x8_t b)
{
	return vsriq_n_p16(a, b, 1);
}

poly16x8_t np_vsriq_n_p16_2(poly16x8_t a, poly16x8_t b)
{
	return vsriq_n_p16(a, b, 2);
}

poly16x8_t np_vsriq_n_p16_3(poly16x8_t a, poly16x8_t b)
{
	return vsriq_n_p16(a, b, 3);
}

poly16x8_t np_vsriq_n_p16_4(poly16x8_t a, poly16x8_t b)
{
	return vsriq_n_p16(a, b, 4);
}

poly16x8_t np_vsriq_n_p16_5(poly16x8_t a, poly16x8_t b)
{
	return vsriq_n_p16(a, b, 5);
}

poly16x8_t np_vsriq_n_p16_6(poly16x8_t a, poly16x8_t b)
{
	return vsriq_n_p16(a, b, 6);
}

poly16x8_t np_vsriq_n_p16_7(poly16x8_t a, poly16x8_t b)
{
	return vsriq_n_p16(a, b, 7);
}

poly16x8_t np_vsriq_n_p16_8(poly16x8_t a, poly16x8_t b)
{
	return vsriq_n_p16(a, b, 8);
}

poly16x8_t np_vsriq_n_p16_9(poly16x8_t a, poly16x8_t b)
{
	return vsriq_n_p16(a, b, 9);
}

poly16x8_t np_vsriq_n_p16_10(poly16x8_t a, poly16x8_t b)
{
	return vsriq_n_p16(a, b, 10);
}

poly16x8_t np_vsriq_n_p16_11(poly16x8_t a, poly16x8_t b)
{
	return vsriq_n_p16(a, b, 11);
}

poly16x8_t np_vsriq_n_p16_12(poly16x8_t a, poly16x8_t b)
{
	return vsriq_n_p16(a, b, 12);
}

poly16x8_t np_vsriq_n_p16_13(poly16x8_t a, poly16x8_t b)
{
	return vsriq_n_p16(a, b, 13);
}

poly16x8_t np_vsriq_n_p16_14(poly16x8_t a, poly16x8_t b)
{
	return vsriq_n_p16(a, b, 14);
}

poly16x8_t np_vsriq_n_p16_15(poly16x8_t a, poly16x8_t b)
{
	return vsriq_n_p16(a, b, 15);
}

poly16x8_t np_vsriq_n_p16_16(poly16x8_t a, poly16x8_t b)
{
	return vsriq_n_p16(a, b, 16);
}

int8x16_t np_vsliq_n_s8_0(int8x16_t a, int8x16_t b)
{
	return vsliq_n_s8(a, b, 0);
}

int8x16_t np_vsliq_n_s8_1(int8x16_t a, int8x16_t b)
{
	return vsliq_n_s8(a, b, 1);
}

int8x16_t np_vsliq_n_s8_2(int8x16_t a, int8x16_t b)
{
	return vsliq_n_s8(a, b, 2);
}

int8x16_t np_vsliq_n_s8_3(int8x16_t a, int8x16_t b)
{
	return vsliq_n_s8(a, b, 3);
}

int8x16_t np_vsliq_n_s8_4(int8x16_t a, int8x16_t b)
{
	return vsliq_n_s8(a, b, 4);
}

int8x16_t np_vsliq_n_s8_5(int8x16_t a, int8x16_t b)
{
	return vsliq_n_s8(a, b, 5);
}

int8x16_t np_vsliq_n_s8_6(int8x16_t a, int8x16_t b)
{
	return vsliq_n_s8(a, b, 6);
}

int8x16_t np_vsliq_n_s8_7(int8x16_t a, int8x16_t b)
{
	return vsliq_n_s8(a, b, 7);
}

int16x8_t np_vsliq_n_s16_0(int16x8_t a, int16x8_t b)
{
	return vsliq_n_s16(a, b, 0);
}

int16x8_t np_vsliq_n_s16_1(int16x8_t a, int16x8_t b)
{
	return vsliq_n_s16(a, b, 1);
}

int16x8_t np_vsliq_n_s16_2(int16x8_t a, int16x8_t b)
{
	return vsliq_n_s16(a, b, 2);
}

int16x8_t np_vsliq_n_s16_3(int16x8_t a, int16x8_t b)
{
	return vsliq_n_s16(a, b, 3);
}

int16x8_t np_vsliq_n_s16_4(int16x8_t a, int16x8_t b)
{
	return vsliq_n_s16(a, b, 4);
}

int16x8_t np_vsliq_n_s16_5(int16x8_t a, int16x8_t b)
{
	return vsliq_n_s16(a, b, 5);
}

int16x8_t np_vsliq_n_s16_6(int16x8_t a, int16x8_t b)
{
	return vsliq_n_s16(a, b, 6);
}

int16x8_t np_vsliq_n_s16_7(int16x8_t a, int16x8_t b)
{
	return vsliq_n_s16(a, b, 7);
}

int16x8_t np_vsliq_n_s16_8(int16x8_t a, int16x8_t b)
{
	return vsliq_n_s16(a, b, 8);
}

int16x8_t np_vsliq_n_s16_9(int16x8_t a, int16x8_t b)
{
	return vsliq_n_s16(a, b, 9);
}

int16x8_t np_vsliq_n_s16_10(int16x8_t a, int16x8_t b)
{
	return vsliq_n_s16(a, b, 10);
}

int16x8_t np_vsliq_n_s16_11(int16x8_t a, int16x8_t b)
{
	return vsliq_n_s16(a, b, 11);
}

int16x8_t np_vsliq_n_s16_12(int16x8_t a, int16x8_t b)
{
	return vsliq_n_s16(a, b, 12);
}

int16x8_t np_vsliq_n_s16_13(int16x8_t a, int16x8_t b)
{
	return vsliq_n_s16(a, b, 13);
}

int16x8_t np_vsliq_n_s16_14(int16x8_t a, int16x8_t b)
{
	return vsliq_n_s16(a, b, 14);
}

int16x8_t np_vsliq_n_s16_15(int16x8_t a, int16x8_t b)
{
	return vsliq_n_s16(a, b, 15);
}

int32x4_t np_vsliq_n_s32_0(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 0);
}

int32x4_t np_vsliq_n_s32_1(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 1);
}

int32x4_t np_vsliq_n_s32_2(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 2);
}

int32x4_t np_vsliq_n_s32_3(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 3);
}

int32x4_t np_vsliq_n_s32_4(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 4);
}

int32x4_t np_vsliq_n_s32_5(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 5);
}

int32x4_t np_vsliq_n_s32_6(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 6);
}

int32x4_t np_vsliq_n_s32_7(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 7);
}

int32x4_t np_vsliq_n_s32_8(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 8);
}

int32x4_t np_vsliq_n_s32_9(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 9);
}

int32x4_t np_vsliq_n_s32_10(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 10);
}

int32x4_t np_vsliq_n_s32_11(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 11);
}

int32x4_t np_vsliq_n_s32_12(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 12);
}

int32x4_t np_vsliq_n_s32_13(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 13);
}

int32x4_t np_vsliq_n_s32_14(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 14);
}

int32x4_t np_vsliq_n_s32_15(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 15);
}

int32x4_t np_vsliq_n_s32_16(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 16);
}

int32x4_t np_vsliq_n_s32_17(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 17);
}

int32x4_t np_vsliq_n_s32_18(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 18);
}

int32x4_t np_vsliq_n_s32_19(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 19);
}

int32x4_t np_vsliq_n_s32_20(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 20);
}

int32x4_t np_vsliq_n_s32_21(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 21);
}

int32x4_t np_vsliq_n_s32_22(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 22);
}

int32x4_t np_vsliq_n_s32_23(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 23);
}

int32x4_t np_vsliq_n_s32_24(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 24);
}

int32x4_t np_vsliq_n_s32_25(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 25);
}

int32x4_t np_vsliq_n_s32_26(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 26);
}

int32x4_t np_vsliq_n_s32_27(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 27);
}

int32x4_t np_vsliq_n_s32_28(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 28);
}

int32x4_t np_vsliq_n_s32_29(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 29);
}

int32x4_t np_vsliq_n_s32_30(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 30);
}

int32x4_t np_vsliq_n_s32_31(int32x4_t a, int32x4_t b)
{
	return vsliq_n_s32(a, b, 31);
}

int64x2_t np_vsliq_n_s64_0(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 0);
}

int64x2_t np_vsliq_n_s64_1(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 1);
}

int64x2_t np_vsliq_n_s64_2(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 2);
}

int64x2_t np_vsliq_n_s64_3(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 3);
}

int64x2_t np_vsliq_n_s64_4(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 4);
}

int64x2_t np_vsliq_n_s64_5(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 5);
}

int64x2_t np_vsliq_n_s64_6(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 6);
}

int64x2_t np_vsliq_n_s64_7(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 7);
}

int64x2_t np_vsliq_n_s64_8(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 8);
}

int64x2_t np_vsliq_n_s64_9(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 9);
}

int64x2_t np_vsliq_n_s64_10(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 10);
}

int64x2_t np_vsliq_n_s64_11(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 11);
}

int64x2_t np_vsliq_n_s64_12(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 12);
}

int64x2_t np_vsliq_n_s64_13(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 13);
}

int64x2_t np_vsliq_n_s64_14(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 14);
}

int64x2_t np_vsliq_n_s64_15(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 15);
}

int64x2_t np_vsliq_n_s64_16(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 16);
}

int64x2_t np_vsliq_n_s64_17(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 17);
}

int64x2_t np_vsliq_n_s64_18(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 18);
}

int64x2_t np_vsliq_n_s64_19(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 19);
}

int64x2_t np_vsliq_n_s64_20(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 20);
}

int64x2_t np_vsliq_n_s64_21(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 21);
}

int64x2_t np_vsliq_n_s64_22(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 22);
}

int64x2_t np_vsliq_n_s64_23(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 23);
}

int64x2_t np_vsliq_n_s64_24(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 24);
}

int64x2_t np_vsliq_n_s64_25(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 25);
}

int64x2_t np_vsliq_n_s64_26(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 26);
}

int64x2_t np_vsliq_n_s64_27(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 27);
}

int64x2_t np_vsliq_n_s64_28(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 28);
}

int64x2_t np_vsliq_n_s64_29(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 29);
}

int64x2_t np_vsliq_n_s64_30(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 30);
}

int64x2_t np_vsliq_n_s64_31(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 31);
}

int64x2_t np_vsliq_n_s64_32(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 32);
}

int64x2_t np_vsliq_n_s64_33(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 33);
}

int64x2_t np_vsliq_n_s64_34(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 34);
}

int64x2_t np_vsliq_n_s64_35(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 35);
}

int64x2_t np_vsliq_n_s64_36(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 36);
}

int64x2_t np_vsliq_n_s64_37(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 37);
}

int64x2_t np_vsliq_n_s64_38(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 38);
}

int64x2_t np_vsliq_n_s64_39(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 39);
}

int64x2_t np_vsliq_n_s64_40(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 40);
}

int64x2_t np_vsliq_n_s64_41(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 41);
}

int64x2_t np_vsliq_n_s64_42(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 42);
}

int64x2_t np_vsliq_n_s64_43(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 43);
}

int64x2_t np_vsliq_n_s64_44(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 44);
}

int64x2_t np_vsliq_n_s64_45(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 45);
}

int64x2_t np_vsliq_n_s64_46(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 46);
}

int64x2_t np_vsliq_n_s64_47(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 47);
}

int64x2_t np_vsliq_n_s64_48(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 48);
}

int64x2_t np_vsliq_n_s64_49(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 49);
}

int64x2_t np_vsliq_n_s64_50(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 50);
}

int64x2_t np_vsliq_n_s64_51(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 51);
}

int64x2_t np_vsliq_n_s64_52(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 52);
}

int64x2_t np_vsliq_n_s64_53(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 53);
}

int64x2_t np_vsliq_n_s64_54(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 54);
}

int64x2_t np_vsliq_n_s64_55(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 55);
}

int64x2_t np_vsliq_n_s64_56(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 56);
}

int64x2_t np_vsliq_n_s64_57(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 57);
}

int64x2_t np_vsliq_n_s64_58(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 58);
}

int64x2_t np_vsliq_n_s64_59(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 59);
}

int64x2_t np_vsliq_n_s64_60(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 60);
}

int64x2_t np_vsliq_n_s64_61(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 61);
}

int64x2_t np_vsliq_n_s64_62(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 62);
}

int64x2_t np_vsliq_n_s64_63(int64x2_t a, int64x2_t b)
{
	return vsliq_n_s64(a, b, 63);
}

uint8x16_t np_vsliq_n_u8_0(uint8x16_t a, uint8x16_t b)
{
	return vsliq_n_u8(a, b, 0);
}

uint8x16_t np_vsliq_n_u8_1(uint8x16_t a, uint8x16_t b)
{
	return vsliq_n_u8(a, b, 1);
}

uint8x16_t np_vsliq_n_u8_2(uint8x16_t a, uint8x16_t b)
{
	return vsliq_n_u8(a, b, 2);
}

uint8x16_t np_vsliq_n_u8_3(uint8x16_t a, uint8x16_t b)
{
	return vsliq_n_u8(a, b, 3);
}

uint8x16_t np_vsliq_n_u8_4(uint8x16_t a, uint8x16_t b)
{
	return vsliq_n_u8(a, b, 4);
}

uint8x16_t np_vsliq_n_u8_5(uint8x16_t a, uint8x16_t b)
{
	return vsliq_n_u8(a, b, 5);
}

uint8x16_t np_vsliq_n_u8_6(uint8x16_t a, uint8x16_t b)
{
	return vsliq_n_u8(a, b, 6);
}

uint8x16_t np_vsliq_n_u8_7(uint8x16_t a, uint8x16_t b)
{
	return vsliq_n_u8(a, b, 7);
}

uint16x8_t np_vsliq_n_u16_0(uint16x8_t a, uint16x8_t b)
{
	return vsliq_n_u16(a, b, 0);
}

uint16x8_t np_vsliq_n_u16_1(uint16x8_t a, uint16x8_t b)
{
	return vsliq_n_u16(a, b, 1);
}

uint16x8_t np_vsliq_n_u16_2(uint16x8_t a, uint16x8_t b)
{
	return vsliq_n_u16(a, b, 2);
}

uint16x8_t np_vsliq_n_u16_3(uint16x8_t a, uint16x8_t b)
{
	return vsliq_n_u16(a, b, 3);
}

uint16x8_t np_vsliq_n_u16_4(uint16x8_t a, uint16x8_t b)
{
	return vsliq_n_u16(a, b, 4);
}

uint16x8_t np_vsliq_n_u16_5(uint16x8_t a, uint16x8_t b)
{
	return vsliq_n_u16(a, b, 5);
}

uint16x8_t np_vsliq_n_u16_6(uint16x8_t a, uint16x8_t b)
{
	return vsliq_n_u16(a, b, 6);
}

uint16x8_t np_vsliq_n_u16_7(uint16x8_t a, uint16x8_t b)
{
	return vsliq_n_u16(a, b, 7);
}

uint16x8_t np_vsliq_n_u16_8(uint16x8_t a, uint16x8_t b)
{
	return vsliq_n_u16(a, b, 8);
}

uint16x8_t np_vsliq_n_u16_9(uint16x8_t a, uint16x8_t b)
{
	return vsliq_n_u16(a, b, 9);
}

uint16x8_t np_vsliq_n_u16_10(uint16x8_t a, uint16x8_t b)
{
	return vsliq_n_u16(a, b, 10);
}

uint16x8_t np_vsliq_n_u16_11(uint16x8_t a, uint16x8_t b)
{
	return vsliq_n_u16(a, b, 11);
}

uint16x8_t np_vsliq_n_u16_12(uint16x8_t a, uint16x8_t b)
{
	return vsliq_n_u16(a, b, 12);
}

uint16x8_t np_vsliq_n_u16_13(uint16x8_t a, uint16x8_t b)
{
	return vsliq_n_u16(a, b, 13);
}

uint16x8_t np_vsliq_n_u16_14(uint16x8_t a, uint16x8_t b)
{
	return vsliq_n_u16(a, b, 14);
}

uint16x8_t np_vsliq_n_u16_15(uint16x8_t a, uint16x8_t b)
{
	return vsliq_n_u16(a, b, 15);
}

uint32x4_t np_vsliq_n_u32_0(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 0);
}

uint32x4_t np_vsliq_n_u32_1(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 1);
}

uint32x4_t np_vsliq_n_u32_2(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 2);
}

uint32x4_t np_vsliq_n_u32_3(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 3);
}

uint32x4_t np_vsliq_n_u32_4(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 4);
}

uint32x4_t np_vsliq_n_u32_5(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 5);
}

uint32x4_t np_vsliq_n_u32_6(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 6);
}

uint32x4_t np_vsliq_n_u32_7(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 7);
}

uint32x4_t np_vsliq_n_u32_8(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 8);
}

uint32x4_t np_vsliq_n_u32_9(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 9);
}

uint32x4_t np_vsliq_n_u32_10(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 10);
}

uint32x4_t np_vsliq_n_u32_11(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 11);
}

uint32x4_t np_vsliq_n_u32_12(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 12);
}

uint32x4_t np_vsliq_n_u32_13(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 13);
}

uint32x4_t np_vsliq_n_u32_14(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 14);
}

uint32x4_t np_vsliq_n_u32_15(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 15);
}

uint32x4_t np_vsliq_n_u32_16(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 16);
}

uint32x4_t np_vsliq_n_u32_17(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 17);
}

uint32x4_t np_vsliq_n_u32_18(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 18);
}

uint32x4_t np_vsliq_n_u32_19(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 19);
}

uint32x4_t np_vsliq_n_u32_20(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 20);
}

uint32x4_t np_vsliq_n_u32_21(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 21);
}

uint32x4_t np_vsliq_n_u32_22(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 22);
}

uint32x4_t np_vsliq_n_u32_23(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 23);
}

uint32x4_t np_vsliq_n_u32_24(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 24);
}

uint32x4_t np_vsliq_n_u32_25(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 25);
}

uint32x4_t np_vsliq_n_u32_26(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 26);
}

uint32x4_t np_vsliq_n_u32_27(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 27);
}

uint32x4_t np_vsliq_n_u32_28(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 28);
}

uint32x4_t np_vsliq_n_u32_29(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 29);
}

uint32x4_t np_vsliq_n_u32_30(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 30);
}

uint32x4_t np_vsliq_n_u32_31(uint32x4_t a, uint32x4_t b)
{
	return vsliq_n_u32(a, b, 31);
}

uint64x2_t np_vsliq_n_u64_0(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 0);
}

uint64x2_t np_vsliq_n_u64_1(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 1);
}

uint64x2_t np_vsliq_n_u64_2(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 2);
}

uint64x2_t np_vsliq_n_u64_3(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 3);
}

uint64x2_t np_vsliq_n_u64_4(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 4);
}

uint64x2_t np_vsliq_n_u64_5(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 5);
}

uint64x2_t np_vsliq_n_u64_6(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 6);
}

uint64x2_t np_vsliq_n_u64_7(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 7);
}

uint64x2_t np_vsliq_n_u64_8(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 8);
}

uint64x2_t np_vsliq_n_u64_9(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 9);
}

uint64x2_t np_vsliq_n_u64_10(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 10);
}

uint64x2_t np_vsliq_n_u64_11(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 11);
}

uint64x2_t np_vsliq_n_u64_12(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 12);
}

uint64x2_t np_vsliq_n_u64_13(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 13);
}

uint64x2_t np_vsliq_n_u64_14(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 14);
}

uint64x2_t np_vsliq_n_u64_15(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 15);
}

uint64x2_t np_vsliq_n_u64_16(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 16);
}

uint64x2_t np_vsliq_n_u64_17(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 17);
}

uint64x2_t np_vsliq_n_u64_18(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 18);
}

uint64x2_t np_vsliq_n_u64_19(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 19);
}

uint64x2_t np_vsliq_n_u64_20(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 20);
}

uint64x2_t np_vsliq_n_u64_21(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 21);
}

uint64x2_t np_vsliq_n_u64_22(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 22);
}

uint64x2_t np_vsliq_n_u64_23(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 23);
}

uint64x2_t np_vsliq_n_u64_24(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 24);
}

uint64x2_t np_vsliq_n_u64_25(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 25);
}

uint64x2_t np_vsliq_n_u64_26(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 26);
}

uint64x2_t np_vsliq_n_u64_27(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 27);
}

uint64x2_t np_vsliq_n_u64_28(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 28);
}

uint64x2_t np_vsliq_n_u64_29(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 29);
}

uint64x2_t np_vsliq_n_u64_30(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 30);
}

uint64x2_t np_vsliq_n_u64_31(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 31);
}

uint64x2_t np_vsliq_n_u64_32(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 32);
}

uint64x2_t np_vsliq_n_u64_33(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 33);
}

uint64x2_t np_vsliq_n_u64_34(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 34);
}

uint64x2_t np_vsliq_n_u64_35(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 35);
}

uint64x2_t np_vsliq_n_u64_36(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 36);
}

uint64x2_t np_vsliq_n_u64_37(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 37);
}

uint64x2_t np_vsliq_n_u64_38(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 38);
}

uint64x2_t np_vsliq_n_u64_39(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 39);
}

uint64x2_t np_vsliq_n_u64_40(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 40);
}

uint64x2_t np_vsliq_n_u64_41(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 41);
}

uint64x2_t np_vsliq_n_u64_42(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 42);
}

uint64x2_t np_vsliq_n_u64_43(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 43);
}

uint64x2_t np_vsliq_n_u64_44(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 44);
}

uint64x2_t np_vsliq_n_u64_45(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 45);
}

uint64x2_t np_vsliq_n_u64_46(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 46);
}

uint64x2_t np_vsliq_n_u64_47(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 47);
}

uint64x2_t np_vsliq_n_u64_48(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 48);
}

uint64x2_t np_vsliq_n_u64_49(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 49);
}

uint64x2_t np_vsliq_n_u64_50(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 50);
}

uint64x2_t np_vsliq_n_u64_51(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 51);
}

uint64x2_t np_vsliq_n_u64_52(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 52);
}

uint64x2_t np_vsliq_n_u64_53(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 53);
}

uint64x2_t np_vsliq_n_u64_54(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 54);
}

uint64x2_t np_vsliq_n_u64_55(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 55);
}

uint64x2_t np_vsliq_n_u64_56(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 56);
}

uint64x2_t np_vsliq_n_u64_57(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 57);
}

uint64x2_t np_vsliq_n_u64_58(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 58);
}

uint64x2_t np_vsliq_n_u64_59(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 59);
}

uint64x2_t np_vsliq_n_u64_60(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 60);
}

uint64x2_t np_vsliq_n_u64_61(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 61);
}

uint64x2_t np_vsliq_n_u64_62(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 62);
}

uint64x2_t np_vsliq_n_u64_63(uint64x2_t a, uint64x2_t b)
{
	return vsliq_n_u64(a, b, 63);
}

poly8x16_t np_vsliq_n_p8_0(poly8x16_t a, poly8x16_t b)
{
	return vsliq_n_p8(a, b, 0);
}

poly8x16_t np_vsliq_n_p8_1(poly8x16_t a, poly8x16_t b)
{
	return vsliq_n_p8(a, b, 1);
}

poly8x16_t np_vsliq_n_p8_2(poly8x16_t a, poly8x16_t b)
{
	return vsliq_n_p8(a, b, 2);
}

poly8x16_t np_vsliq_n_p8_3(poly8x16_t a, poly8x16_t b)
{
	return vsliq_n_p8(a, b, 3);
}

poly8x16_t np_vsliq_n_p8_4(poly8x16_t a, poly8x16_t b)
{
	return vsliq_n_p8(a, b, 4);
}

poly8x16_t np_vsliq_n_p8_5(poly8x16_t a, poly8x16_t b)
{
	return vsliq_n_p8(a, b, 5);
}

poly8x16_t np_vsliq_n_p8_6(poly8x16_t a, poly8x16_t b)
{
	return vsliq_n_p8(a, b, 6);
}

poly8x16_t np_vsliq_n_p8_7(poly8x16_t a, poly8x16_t b)
{
	return vsliq_n_p8(a, b, 7);
}

poly16x8_t np_vsliq_n_p16_0(poly16x8_t a, poly16x8_t b)
{
	return vsliq_n_p16(a, b, 0);
}

poly16x8_t np_vsliq_n_p16_1(poly16x8_t a, poly16x8_t b)
{
	return vsliq_n_p16(a, b, 1);
}

poly16x8_t np_vsliq_n_p16_2(poly16x8_t a, poly16x8_t b)
{
	return vsliq_n_p16(a, b, 2);
}

poly16x8_t np_vsliq_n_p16_3(poly16x8_t a, poly16x8_t b)
{
	return vsliq_n_p16(a, b, 3);
}

poly16x8_t np_vsliq_n_p16_4(poly16x8_t a, poly16x8_t b)
{
	return vsliq_n_p16(a, b, 4);
}

poly16x8_t np_vsliq_n_p16_5(poly16x8_t a, poly16x8_t b)
{
	return vsliq_n_p16(a, b, 5);
}

poly16x8_t np_vsliq_n_p16_6(poly16x8_t a, poly16x8_t b)
{
	return vsliq_n_p16(a, b, 6);
}

poly16x8_t np_vsliq_n_p16_7(poly16x8_t a, poly16x8_t b)
{
	return vsliq_n_p16(a, b, 7);
}

poly16x8_t np_vsliq_n_p16_8(poly16x8_t a, poly16x8_t b)
{
	return vsliq_n_p16(a, b, 8);
}

poly16x8_t np_vsliq_n_p16_9(poly16x8_t a, poly16x8_t b)
{
	return vsliq_n_p16(a, b, 9);
}

poly16x8_t np_vsliq_n_p16_10(poly16x8_t a, poly16x8_t b)
{
	return vsliq_n_p16(a, b, 10);
}

poly16x8_t np_vsliq_n_p16_11(poly16x8_t a, poly16x8_t b)
{
	return vsliq_n_p16(a, b, 11);
}

poly16x8_t np_vsliq_n_p16_12(poly16x8_t a, poly16x8_t b)
{
	return vsliq_n_p16(a, b, 12);
}

poly16x8_t np_vsliq_n_p16_13(poly16x8_t a, poly16x8_t b)
{
	return vsliq_n_p16(a, b, 13);
}

poly16x8_t np_vsliq_n_p16_14(poly16x8_t a, poly16x8_t b)
{
	return vsliq_n_p16(a, b, 14);
}

poly16x8_t np_vsliq_n_p16_15(poly16x8_t a, poly16x8_t b)
{
	return vsliq_n_p16(a, b, 15);
}

uint8x16_t np_vld1q_u8(uint8_t const * ptr)
{
	return vld1q_u8(ptr);
}

uint16x8_t np_vld1q_u16(uint16_t const * ptr)
{
	return vld1q_u16(ptr);
}

uint32x4_t np_vld1q_u32(uint32_t const * ptr)
{
	return vld1q_u32(ptr);
}

uint64x2_t np_vld1q_u64(uint64_t const * ptr)
{
	return vld1q_u64(ptr);
}

int8x16_t np_vld1q_s8(int8_t const * ptr)
{
	return vld1q_s8(ptr);
}

int16x8_t np_vld1q_s16(int16_t const * ptr)
{
	return vld1q_s16(ptr);
}

int32x4_t np_vld1q_s32(int32_t const * ptr)
{
	return vld1q_s32(ptr);
}

int64x2_t np_vld1q_s64(int64_t const * ptr)
{
	return vld1q_s64(ptr);
}

float32x4_t np_vld1q_f32(float32_t const * ptr)
{
	return vld1q_f32(ptr);
}

poly8x16_t np_vld1q_p8(poly8_t const * ptr)
{
	return vld1q_p8(ptr);
}

poly16x8_t np_vld1q_p16(poly16_t const * ptr)
{
	return vld1q_p16(ptr);
}

uint8x16_t np_vld1q_lane_u8_0(uint8_t const * ptr, uint8x16_t vec)
{
	return vld1q_lane_u8(ptr, vec, 0);
}

uint8x16_t np_vld1q_lane_u8_1(uint8_t const * ptr, uint8x16_t vec)
{
	return vld1q_lane_u8(ptr, vec, 1);
}

uint8x16_t np_vld1q_lane_u8_2(uint8_t const * ptr, uint8x16_t vec)
{
	return vld1q_lane_u8(ptr, vec, 2);
}

uint8x16_t np_vld1q_lane_u8_3(uint8_t const * ptr, uint8x16_t vec)
{
	return vld1q_lane_u8(ptr, vec, 3);
}

uint8x16_t np_vld1q_lane_u8_4(uint8_t const * ptr, uint8x16_t vec)
{
	return vld1q_lane_u8(ptr, vec, 4);
}

uint8x16_t np_vld1q_lane_u8_5(uint8_t const * ptr, uint8x16_t vec)
{
	return vld1q_lane_u8(ptr, vec, 5);
}

uint8x16_t np_vld1q_lane_u8_6(uint8_t const * ptr, uint8x16_t vec)
{
	return vld1q_lane_u8(ptr, vec, 6);
}

uint8x16_t np_vld1q_lane_u8_7(uint8_t const * ptr, uint8x16_t vec)
{
	return vld1q_lane_u8(ptr, vec, 7);
}

uint8x16_t np_vld1q_lane_u8_8(uint8_t const * ptr, uint8x16_t vec)
{
	return vld1q_lane_u8(ptr, vec, 8);
}

uint8x16_t np_vld1q_lane_u8_9(uint8_t const * ptr, uint8x16_t vec)
{
	return vld1q_lane_u8(ptr, vec, 9);
}

uint8x16_t np_vld1q_lane_u8_10(uint8_t const * ptr, uint8x16_t vec)
{
	return vld1q_lane_u8(ptr, vec, 10);
}

uint8x16_t np_vld1q_lane_u8_11(uint8_t const * ptr, uint8x16_t vec)
{
	return vld1q_lane_u8(ptr, vec, 11);
}

uint8x16_t np_vld1q_lane_u8_12(uint8_t const * ptr, uint8x16_t vec)
{
	return vld1q_lane_u8(ptr, vec, 12);
}

uint8x16_t np_vld1q_lane_u8_13(uint8_t const * ptr, uint8x16_t vec)
{
	return vld1q_lane_u8(ptr, vec, 13);
}

uint8x16_t np_vld1q_lane_u8_14(uint8_t const * ptr, uint8x16_t vec)
{
	return vld1q_lane_u8(ptr, vec, 14);
}

uint8x16_t np_vld1q_lane_u8_15(uint8_t const * ptr, uint8x16_t vec)
{
	return vld1q_lane_u8(ptr, vec, 15);
}

uint16x8_t np_vld1q_lane_u16_0(uint16_t const * ptr, uint16x8_t vec)
{
	return vld1q_lane_u16(ptr, vec, 0);
}

uint16x8_t np_vld1q_lane_u16_1(uint16_t const * ptr, uint16x8_t vec)
{
	return vld1q_lane_u16(ptr, vec, 1);
}

uint16x8_t np_vld1q_lane_u16_2(uint16_t const * ptr, uint16x8_t vec)
{
	return vld1q_lane_u16(ptr, vec, 2);
}

uint16x8_t np_vld1q_lane_u16_3(uint16_t const * ptr, uint16x8_t vec)
{
	return vld1q_lane_u16(ptr, vec, 3);
}

uint16x8_t np_vld1q_lane_u16_4(uint16_t const * ptr, uint16x8_t vec)
{
	return vld1q_lane_u16(ptr, vec, 4);
}

uint16x8_t np_vld1q_lane_u16_5(uint16_t const * ptr, uint16x8_t vec)
{
	return vld1q_lane_u16(ptr, vec, 5);
}

uint16x8_t np_vld1q_lane_u16_6(uint16_t const * ptr, uint16x8_t vec)
{
	return vld1q_lane_u16(ptr, vec, 6);
}

uint16x8_t np_vld1q_lane_u16_7(uint16_t const * ptr, uint16x8_t vec)
{
	return vld1q_lane_u16(ptr, vec, 7);
}

uint32x4_t np_vld1q_lane_u32_0(uint32_t const * ptr, uint32x4_t vec)
{
	return vld1q_lane_u32(ptr, vec, 0);
}

uint32x4_t np_vld1q_lane_u32_1(uint32_t const * ptr, uint32x4_t vec)
{
	return vld1q_lane_u32(ptr, vec, 1);
}

uint32x4_t np_vld1q_lane_u32_2(uint32_t const * ptr, uint32x4_t vec)
{
	return vld1q_lane_u32(ptr, vec, 2);
}

uint32x4_t np_vld1q_lane_u32_3(uint32_t const * ptr, uint32x4_t vec)
{
	return vld1q_lane_u32(ptr, vec, 3);
}

int8x16_t np_vld1q_lane_s8_0(int8_t const * ptr, int8x16_t vec)
{
	return vld1q_lane_s8(ptr, vec, 0);
}

int8x16_t np_vld1q_lane_s8_1(int8_t const * ptr, int8x16_t vec)
{
	return vld1q_lane_s8(ptr, vec, 1);
}

int8x16_t np_vld1q_lane_s8_2(int8_t const * ptr, int8x16_t vec)
{
	return vld1q_lane_s8(ptr, vec, 2);
}

int8x16_t np_vld1q_lane_s8_3(int8_t const * ptr, int8x16_t vec)
{
	return vld1q_lane_s8(ptr, vec, 3);
}

int8x16_t np_vld1q_lane_s8_4(int8_t const * ptr, int8x16_t vec)
{
	return vld1q_lane_s8(ptr, vec, 4);
}

int8x16_t np_vld1q_lane_s8_5(int8_t const * ptr, int8x16_t vec)
{
	return vld1q_lane_s8(ptr, vec, 5);
}

int8x16_t np_vld1q_lane_s8_6(int8_t const * ptr, int8x16_t vec)
{
	return vld1q_lane_s8(ptr, vec, 6);
}

int8x16_t np_vld1q_lane_s8_7(int8_t const * ptr, int8x16_t vec)
{
	return vld1q_lane_s8(ptr, vec, 7);
}

int8x16_t np_vld1q_lane_s8_8(int8_t const * ptr, int8x16_t vec)
{
	return vld1q_lane_s8(ptr, vec, 8);
}

int8x16_t np_vld1q_lane_s8_9(int8_t const * ptr, int8x16_t vec)
{
	return vld1q_lane_s8(ptr, vec, 9);
}

int8x16_t np_vld1q_lane_s8_10(int8_t const * ptr, int8x16_t vec)
{
	return vld1q_lane_s8(ptr, vec, 10);
}

int8x16_t np_vld1q_lane_s8_11(int8_t const * ptr, int8x16_t vec)
{
	return vld1q_lane_s8(ptr, vec, 11);
}

int8x16_t np_vld1q_lane_s8_12(int8_t const * ptr, int8x16_t vec)
{
	return vld1q_lane_s8(ptr, vec, 12);
}

int8x16_t np_vld1q_lane_s8_13(int8_t const * ptr, int8x16_t vec)
{
	return vld1q_lane_s8(ptr, vec, 13);
}

int8x16_t np_vld1q_lane_s8_14(int8_t const * ptr, int8x16_t vec)
{
	return vld1q_lane_s8(ptr, vec, 14);
}

int8x16_t np_vld1q_lane_s8_15(int8_t const * ptr, int8x16_t vec)
{
	return vld1q_lane_s8(ptr, vec, 15);
}

int16x8_t np_vld1q_lane_s16_0(int16_t const * ptr, int16x8_t vec)
{
	return vld1q_lane_s16(ptr, vec, 0);
}

int16x8_t np_vld1q_lane_s16_1(int16_t const * ptr, int16x8_t vec)
{
	return vld1q_lane_s16(ptr, vec, 1);
}

int16x8_t np_vld1q_lane_s16_2(int16_t const * ptr, int16x8_t vec)
{
	return vld1q_lane_s16(ptr, vec, 2);
}

int16x8_t np_vld1q_lane_s16_3(int16_t const * ptr, int16x8_t vec)
{
	return vld1q_lane_s16(ptr, vec, 3);
}

int16x8_t np_vld1q_lane_s16_4(int16_t const * ptr, int16x8_t vec)
{
	return vld1q_lane_s16(ptr, vec, 4);
}

int16x8_t np_vld1q_lane_s16_5(int16_t const * ptr, int16x8_t vec)
{
	return vld1q_lane_s16(ptr, vec, 5);
}

int16x8_t np_vld1q_lane_s16_6(int16_t const * ptr, int16x8_t vec)
{
	return vld1q_lane_s16(ptr, vec, 6);
}

int16x8_t np_vld1q_lane_s16_7(int16_t const * ptr, int16x8_t vec)
{
	return vld1q_lane_s16(ptr, vec, 7);
}

int32x4_t np_vld1q_lane_s32_0(int32_t const * ptr, int32x4_t vec)
{
	return vld1q_lane_s32(ptr, vec, 0);
}

int32x4_t np_vld1q_lane_s32_1(int32_t const * ptr, int32x4_t vec)
{
	return vld1q_lane_s32(ptr, vec, 1);
}

int32x4_t np_vld1q_lane_s32_2(int32_t const * ptr, int32x4_t vec)
{
	return vld1q_lane_s32(ptr, vec, 2);
}

int32x4_t np_vld1q_lane_s32_3(int32_t const * ptr, int32x4_t vec)
{
	return vld1q_lane_s32(ptr, vec, 3);
}

float32x4_t np_vld1q_lane_f32_0(float32_t const * ptr, float32x4_t vec)
{
	return vld1q_lane_f32(ptr, vec, 0);
}

float32x4_t np_vld1q_lane_f32_1(float32_t const * ptr, float32x4_t vec)
{
	return vld1q_lane_f32(ptr, vec, 1);
}

float32x4_t np_vld1q_lane_f32_2(float32_t const * ptr, float32x4_t vec)
{
	return vld1q_lane_f32(ptr, vec, 2);
}

float32x4_t np_vld1q_lane_f32_3(float32_t const * ptr, float32x4_t vec)
{
	return vld1q_lane_f32(ptr, vec, 3);
}

poly8x16_t np_vld1q_lane_p8_0(poly8_t const * ptr, poly8x16_t vec)
{
	return vld1q_lane_p8(ptr, vec, 0);
}

poly8x16_t np_vld1q_lane_p8_1(poly8_t const * ptr, poly8x16_t vec)
{
	return vld1q_lane_p8(ptr, vec, 1);
}

poly8x16_t np_vld1q_lane_p8_2(poly8_t const * ptr, poly8x16_t vec)
{
	return vld1q_lane_p8(ptr, vec, 2);
}

poly8x16_t np_vld1q_lane_p8_3(poly8_t const * ptr, poly8x16_t vec)
{
	return vld1q_lane_p8(ptr, vec, 3);
}

poly8x16_t np_vld1q_lane_p8_4(poly8_t const * ptr, poly8x16_t vec)
{
	return vld1q_lane_p8(ptr, vec, 4);
}

poly8x16_t np_vld1q_lane_p8_5(poly8_t const * ptr, poly8x16_t vec)
{
	return vld1q_lane_p8(ptr, vec, 5);
}

poly8x16_t np_vld1q_lane_p8_6(poly8_t const * ptr, poly8x16_t vec)
{
	return vld1q_lane_p8(ptr, vec, 6);
}

poly8x16_t np_vld1q_lane_p8_7(poly8_t const * ptr, poly8x16_t vec)
{
	return vld1q_lane_p8(ptr, vec, 7);
}

poly8x16_t np_vld1q_lane_p8_8(poly8_t const * ptr, poly8x16_t vec)
{
	return vld1q_lane_p8(ptr, vec, 8);
}

poly8x16_t np_vld1q_lane_p8_9(poly8_t const * ptr, poly8x16_t vec)
{
	return vld1q_lane_p8(ptr, vec, 9);
}

poly8x16_t np_vld1q_lane_p8_10(poly8_t const * ptr, poly8x16_t vec)
{
	return vld1q_lane_p8(ptr, vec, 10);
}

poly8x16_t np_vld1q_lane_p8_11(poly8_t const * ptr, poly8x16_t vec)
{
	return vld1q_lane_p8(ptr, vec, 11);
}

poly8x16_t np_vld1q_lane_p8_12(poly8_t const * ptr, poly8x16_t vec)
{
	return vld1q_lane_p8(ptr, vec, 12);
}

poly8x16_t np_vld1q_lane_p8_13(poly8_t const * ptr, poly8x16_t vec)
{
	return vld1q_lane_p8(ptr, vec, 13);
}

poly8x16_t np_vld1q_lane_p8_14(poly8_t const * ptr, poly8x16_t vec)
{
	return vld1q_lane_p8(ptr, vec, 14);
}

poly8x16_t np_vld1q_lane_p8_15(poly8_t const * ptr, poly8x16_t vec)
{
	return vld1q_lane_p8(ptr, vec, 15);
}

poly16x8_t np_vld1q_lane_p16_0(poly16_t const * ptr, poly16x8_t vec)
{
	return vld1q_lane_p16(ptr, vec, 0);
}

poly16x8_t np_vld1q_lane_p16_1(poly16_t const * ptr, poly16x8_t vec)
{
	return vld1q_lane_p16(ptr, vec, 1);
}

poly16x8_t np_vld1q_lane_p16_2(poly16_t const * ptr, poly16x8_t vec)
{
	return vld1q_lane_p16(ptr, vec, 2);
}

poly16x8_t np_vld1q_lane_p16_3(poly16_t const * ptr, poly16x8_t vec)
{
	return vld1q_lane_p16(ptr, vec, 3);
}

poly16x8_t np_vld1q_lane_p16_4(poly16_t const * ptr, poly16x8_t vec)
{
	return vld1q_lane_p16(ptr, vec, 4);
}

poly16x8_t np_vld1q_lane_p16_5(poly16_t const * ptr, poly16x8_t vec)
{
	return vld1q_lane_p16(ptr, vec, 5);
}

poly16x8_t np_vld1q_lane_p16_6(poly16_t const * ptr, poly16x8_t vec)
{
	return vld1q_lane_p16(ptr, vec, 6);
}

poly16x8_t np_vld1q_lane_p16_7(poly16_t const * ptr, poly16x8_t vec)
{
	return vld1q_lane_p16(ptr, vec, 7);
}

uint8x16_t np_vld1q_dup_u8(uint8_t const * ptr)
{
	return vld1q_dup_u8(ptr);
}

uint16x8_t np_vld1q_dup_u16(uint16_t const * ptr)
{
	return vld1q_dup_u16(ptr);
}

uint32x4_t np_vld1q_dup_u32(uint32_t const * ptr)
{
	return vld1q_dup_u32(ptr);
}

int8x16_t np_vld1q_dup_s8(int8_t const * ptr)
{
	return vld1q_dup_s8(ptr);
}

int16x8_t np_vld1q_dup_s16(int16_t const * ptr)
{
	return vld1q_dup_s16(ptr);
}

int32x4_t np_vld1q_dup_s32(int32_t const * ptr)
{
	return vld1q_dup_s32(ptr);
}

float32x4_t np_vld1q_dup_f32(float32_t const * ptr)
{
	return vld1q_dup_f32(ptr);
}

poly8x16_t np_vld1q_dup_p8(poly8_t const * ptr)
{
	return vld1q_dup_p8(ptr);
}

poly16x8_t np_vld1q_dup_p16(poly16_t const * ptr)
{
	return vld1q_dup_p16(ptr);
}

void np_vst1q_u8(uint8_t * ptr, uint8x16_t val)
{
	vst1q_u8(ptr, val);
}

void np_vst1q_u16(uint16_t * ptr, uint16x8_t val)
{
	vst1q_u16(ptr, val);
}

void np_vst1q_u32(uint32_t * ptr, uint32x4_t val)
{
	vst1q_u32(ptr, val);
}

void np_vst1q_u64(uint64_t * ptr, uint64x2_t val)
{
	vst1q_u64(ptr, val);
}

void np_vst1q_s8(int8_t * ptr, int8x16_t val)
{
	vst1q_s8(ptr, val);
}

void np_vst1q_s16(int16_t * ptr, int16x8_t val)
{
	vst1q_s16(ptr, val);
}

void np_vst1q_s32(int32_t * ptr, int32x4_t val)
{
	vst1q_s32(ptr, val);
}

void np_vst1q_s64(int64_t * ptr, int64x2_t val)
{
	vst1q_s64(ptr, val);
}

void np_vst1q_f32(float32_t * ptr, float32x4_t val)
{
	vst1q_f32(ptr, val);
}

void np_vst1q_p8(poly8_t * ptr, poly8x16_t val)
{
	vst1q_p8(ptr, val);
}

void np_vst1q_p16(poly16_t * ptr, poly16x8_t val)
{
	vst1q_p16(ptr, val);
}

uint8x16x2_t np_vld2q_u8(uint8_t const * ptr)
{
	return vld2q_u8(ptr);
}

uint16x8x2_t np_vld2q_u16(uint16_t const * ptr)
{
	return vld2q_u16(ptr);
}

uint32x4x2_t np_vld2q_u32(uint32_t const * ptr)
{
	return vld2q_u32(ptr);
}

int8x16x2_t np_vld2q_s8(int8_t const * ptr)
{
	return vld2q_s8(ptr);
}

int16x8x2_t np_vld2q_s16(int16_t const * ptr)
{
	return vld2q_s16(ptr);
}

int32x4x2_t np_vld2q_s32(int32_t const * ptr)
{
	return vld2q_s32(ptr);
}

float32x4x2_t np_vld2q_f32(float32_t const * ptr)
{
	return vld2q_f32(ptr);
}

poly8x16x2_t np_vld2q_p8(poly8_t const * ptr)
{
	return vld2q_p8(ptr);
}

poly16x8x2_t np_vld2q_p16(poly16_t const * ptr)
{
	return vld2q_p16(ptr);
}

uint8x16x3_t np_vld3q_u8(uint8_t const * ptr)
{
	return vld3q_u8(ptr);
}

uint16x8x3_t np_vld3q_u16(uint16_t const * ptr)
{
	return vld3q_u16(ptr);
}

uint32x4x3_t np_vld3q_u32(uint32_t const * ptr)
{
	return vld3q_u32(ptr);
}

int8x16x3_t np_vld3q_s8(int8_t const * ptr)
{
	return vld3q_s8(ptr);
}

int16x8x3_t np_vld3q_s16(int16_t const * ptr)
{
	return vld3q_s16(ptr);
}

int32x4x3_t np_vld3q_s32(int32_t const * ptr)
{
	return vld3q_s32(ptr);
}

float32x4x3_t np_vld3q_f32(float32_t const * ptr)
{
	return vld3q_f32(ptr);
}

poly8x16x3_t np_vld3q_p8(poly8_t const * ptr)
{
	return vld3q_p8(ptr);
}

poly16x8x3_t np_vld3q_p16(poly16_t const * ptr)
{
	return vld3q_p16(ptr);
}

uint8x16x4_t np_vld4q_u8(uint8_t const * ptr)
{
	return vld4q_u8(ptr);
}

uint16x8x4_t np_vld4q_u16(uint16_t const * ptr)
{
	return vld4q_u16(ptr);
}

uint32x4x4_t np_vld4q_u32(uint32_t const * ptr)
{
	return vld4q_u32(ptr);
}

int8x16x4_t np_vld4q_s8(int8_t const * ptr)
{
	return vld4q_s8(ptr);
}

int16x8x4_t np_vld4q_s16(int16_t const * ptr)
{
	return vld4q_s16(ptr);
}

int32x4x4_t np_vld4q_s32(int32_t const * ptr)
{
	return vld4q_s32(ptr);
}

float32x4x4_t np_vld4q_f32(float32_t const * ptr)
{
	return vld4q_f32(ptr);
}

poly8x16x4_t np_vld4q_p8(poly8_t const * ptr)
{
	return vld4q_p8(ptr);
}

poly16x8x4_t np_vld4q_p16(poly16_t const * ptr)
{
	return vld4q_p16(ptr);
}

uint8_t np_vgetq_lane_u8_0(uint8x16_t vec)
{
	return vgetq_lane_u8(vec, 0);
}

uint8_t np_vgetq_lane_u8_1(uint8x16_t vec)
{
	return vgetq_lane_u8(vec, 1);
}

uint8_t np_vgetq_lane_u8_2(uint8x16_t vec)
{
	return vgetq_lane_u8(vec, 2);
}

uint8_t np_vgetq_lane_u8_3(uint8x16_t vec)
{
	return vgetq_lane_u8(vec, 3);
}

uint8_t np_vgetq_lane_u8_4(uint8x16_t vec)
{
	return vgetq_lane_u8(vec, 4);
}

uint8_t np_vgetq_lane_u8_5(uint8x16_t vec)
{
	return vgetq_lane_u8(vec, 5);
}

uint8_t np_vgetq_lane_u8_6(uint8x16_t vec)
{
	return vgetq_lane_u8(vec, 6);
}

uint8_t np_vgetq_lane_u8_7(uint8x16_t vec)
{
	return vgetq_lane_u8(vec, 7);
}

uint8_t np_vgetq_lane_u8_8(uint8x16_t vec)
{
	return vgetq_lane_u8(vec, 8);
}

uint8_t np_vgetq_lane_u8_9(uint8x16_t vec)
{
	return vgetq_lane_u8(vec, 9);
}

uint8_t np_vgetq_lane_u8_10(uint8x16_t vec)
{
	return vgetq_lane_u8(vec, 10);
}

uint8_t np_vgetq_lane_u8_11(uint8x16_t vec)
{
	return vgetq_lane_u8(vec, 11);
}

uint8_t np_vgetq_lane_u8_12(uint8x16_t vec)
{
	return vgetq_lane_u8(vec, 12);
}

uint8_t np_vgetq_lane_u8_13(uint8x16_t vec)
{
	return vgetq_lane_u8(vec, 13);
}

uint8_t np_vgetq_lane_u8_14(uint8x16_t vec)
{
	return vgetq_lane_u8(vec, 14);
}

uint8_t np_vgetq_lane_u8_15(uint8x16_t vec)
{
	return vgetq_lane_u8(vec, 15);
}

uint16_t np_vgetq_lane_u16_0(uint16x8_t vec)
{
	return vgetq_lane_u16(vec, 0);
}

uint16_t np_vgetq_lane_u16_1(uint16x8_t vec)
{
	return vgetq_lane_u16(vec, 1);
}

uint16_t np_vgetq_lane_u16_2(uint16x8_t vec)
{
	return vgetq_lane_u16(vec, 2);
}

uint16_t np_vgetq_lane_u16_3(uint16x8_t vec)
{
	return vgetq_lane_u16(vec, 3);
}

uint16_t np_vgetq_lane_u16_4(uint16x8_t vec)
{
	return vgetq_lane_u16(vec, 4);
}

uint16_t np_vgetq_lane_u16_5(uint16x8_t vec)
{
	return vgetq_lane_u16(vec, 5);
}

uint16_t np_vgetq_lane_u16_6(uint16x8_t vec)
{
	return vgetq_lane_u16(vec, 6);
}

uint16_t np_vgetq_lane_u16_7(uint16x8_t vec)
{
	return vgetq_lane_u16(vec, 7);
}

uint32_t np_vgetq_lane_u32_0(uint32x4_t vec)
{
	return vgetq_lane_u32(vec, 0);
}

uint32_t np_vgetq_lane_u32_1(uint32x4_t vec)
{
	return vgetq_lane_u32(vec, 1);
}

uint32_t np_vgetq_lane_u32_2(uint32x4_t vec)
{
	return vgetq_lane_u32(vec, 2);
}

uint32_t np_vgetq_lane_u32_3(uint32x4_t vec)
{
	return vgetq_lane_u32(vec, 3);
}

int8_t np_vgetq_lane_s8_0(int8x16_t vec)
{
	return vgetq_lane_s8(vec, 0);
}

int8_t np_vgetq_lane_s8_1(int8x16_t vec)
{
	return vgetq_lane_s8(vec, 1);
}

int8_t np_vgetq_lane_s8_2(int8x16_t vec)
{
	return vgetq_lane_s8(vec, 2);
}

int8_t np_vgetq_lane_s8_3(int8x16_t vec)
{
	return vgetq_lane_s8(vec, 3);
}

int8_t np_vgetq_lane_s8_4(int8x16_t vec)
{
	return vgetq_lane_s8(vec, 4);
}

int8_t np_vgetq_lane_s8_5(int8x16_t vec)
{
	return vgetq_lane_s8(vec, 5);
}

int8_t np_vgetq_lane_s8_6(int8x16_t vec)
{
	return vgetq_lane_s8(vec, 6);
}

int8_t np_vgetq_lane_s8_7(int8x16_t vec)
{
	return vgetq_lane_s8(vec, 7);
}

int8_t np_vgetq_lane_s8_8(int8x16_t vec)
{
	return vgetq_lane_s8(vec, 8);
}

int8_t np_vgetq_lane_s8_9(int8x16_t vec)
{
	return vgetq_lane_s8(vec, 9);
}

int8_t np_vgetq_lane_s8_10(int8x16_t vec)
{
	return vgetq_lane_s8(vec, 10);
}

int8_t np_vgetq_lane_s8_11(int8x16_t vec)
{
	return vgetq_lane_s8(vec, 11);
}

int8_t np_vgetq_lane_s8_12(int8x16_t vec)
{
	return vgetq_lane_s8(vec, 12);
}

int8_t np_vgetq_lane_s8_13(int8x16_t vec)
{
	return vgetq_lane_s8(vec, 13);
}

int8_t np_vgetq_lane_s8_14(int8x16_t vec)
{
	return vgetq_lane_s8(vec, 14);
}

int8_t np_vgetq_lane_s8_15(int8x16_t vec)
{
	return vgetq_lane_s8(vec, 15);
}

int16_t np_vgetq_lane_s16_0(int16x8_t vec)
{
	return vgetq_lane_s16(vec, 0);
}

int16_t np_vgetq_lane_s16_1(int16x8_t vec)
{
	return vgetq_lane_s16(vec, 1);
}

int16_t np_vgetq_lane_s16_2(int16x8_t vec)
{
	return vgetq_lane_s16(vec, 2);
}

int16_t np_vgetq_lane_s16_3(int16x8_t vec)
{
	return vgetq_lane_s16(vec, 3);
}

int16_t np_vgetq_lane_s16_4(int16x8_t vec)
{
	return vgetq_lane_s16(vec, 4);
}

int16_t np_vgetq_lane_s16_5(int16x8_t vec)
{
	return vgetq_lane_s16(vec, 5);
}

int16_t np_vgetq_lane_s16_6(int16x8_t vec)
{
	return vgetq_lane_s16(vec, 6);
}

int16_t np_vgetq_lane_s16_7(int16x8_t vec)
{
	return vgetq_lane_s16(vec, 7);
}

int32_t np_vgetq_lane_s32_0(int32x4_t vec)
{
	return vgetq_lane_s32(vec, 0);
}

int32_t np_vgetq_lane_s32_1(int32x4_t vec)
{
	return vgetq_lane_s32(vec, 1);
}

int32_t np_vgetq_lane_s32_2(int32x4_t vec)
{
	return vgetq_lane_s32(vec, 2);
}

int32_t np_vgetq_lane_s32_3(int32x4_t vec)
{
	return vgetq_lane_s32(vec, 3);
}

poly8_t np_vgetq_lane_p8_0(poly8x16_t vec)
{
	return vgetq_lane_p8(vec, 0);
}

poly8_t np_vgetq_lane_p8_1(poly8x16_t vec)
{
	return vgetq_lane_p8(vec, 1);
}

poly8_t np_vgetq_lane_p8_2(poly8x16_t vec)
{
	return vgetq_lane_p8(vec, 2);
}

poly8_t np_vgetq_lane_p8_3(poly8x16_t vec)
{
	return vgetq_lane_p8(vec, 3);
}

poly8_t np_vgetq_lane_p8_4(poly8x16_t vec)
{
	return vgetq_lane_p8(vec, 4);
}

poly8_t np_vgetq_lane_p8_5(poly8x16_t vec)
{
	return vgetq_lane_p8(vec, 5);
}

poly8_t np_vgetq_lane_p8_6(poly8x16_t vec)
{
	return vgetq_lane_p8(vec, 6);
}

poly8_t np_vgetq_lane_p8_7(poly8x16_t vec)
{
	return vgetq_lane_p8(vec, 7);
}

poly8_t np_vgetq_lane_p8_8(poly8x16_t vec)
{
	return vgetq_lane_p8(vec, 8);
}

poly8_t np_vgetq_lane_p8_9(poly8x16_t vec)
{
	return vgetq_lane_p8(vec, 9);
}

poly8_t np_vgetq_lane_p8_10(poly8x16_t vec)
{
	return vgetq_lane_p8(vec, 10);
}

poly8_t np_vgetq_lane_p8_11(poly8x16_t vec)
{
	return vgetq_lane_p8(vec, 11);
}

poly8_t np_vgetq_lane_p8_12(poly8x16_t vec)
{
	return vgetq_lane_p8(vec, 12);
}

poly8_t np_vgetq_lane_p8_13(poly8x16_t vec)
{
	return vgetq_lane_p8(vec, 13);
}

poly8_t np_vgetq_lane_p8_14(poly8x16_t vec)
{
	return vgetq_lane_p8(vec, 14);
}

poly8_t np_vgetq_lane_p8_15(poly8x16_t vec)
{
	return vgetq_lane_p8(vec, 15);
}

poly16_t np_vgetq_lane_p16_0(poly16x8_t vec)
{
	return vgetq_lane_p16(vec, 0);
}

poly16_t np_vgetq_lane_p16_1(poly16x8_t vec)
{
	return vgetq_lane_p16(vec, 1);
}

poly16_t np_vgetq_lane_p16_2(poly16x8_t vec)
{
	return vgetq_lane_p16(vec, 2);
}

poly16_t np_vgetq_lane_p16_3(poly16x8_t vec)
{
	return vgetq_lane_p16(vec, 3);
}

poly16_t np_vgetq_lane_p16_4(poly16x8_t vec)
{
	return vgetq_lane_p16(vec, 4);
}

poly16_t np_vgetq_lane_p16_5(poly16x8_t vec)
{
	return vgetq_lane_p16(vec, 5);
}

poly16_t np_vgetq_lane_p16_6(poly16x8_t vec)
{
	return vgetq_lane_p16(vec, 6);
}

poly16_t np_vgetq_lane_p16_7(poly16x8_t vec)
{
	return vgetq_lane_p16(vec, 7);
}

float32_t np_vgetq_lane_f32_0(float32x4_t vec)
{
	return vgetq_lane_f32(vec, 0);
}

float32_t np_vgetq_lane_f32_1(float32x4_t vec)
{
	return vgetq_lane_f32(vec, 1);
}

float32_t np_vgetq_lane_f32_2(float32x4_t vec)
{
	return vgetq_lane_f32(vec, 2);
}

float32_t np_vgetq_lane_f32_3(float32x4_t vec)
{
	return vgetq_lane_f32(vec, 3);
}

int64_t np_vgetq_lane_s64_0(int64x2_t vec)
{
	return vgetq_lane_s64(vec, 0);
}

int64_t np_vgetq_lane_s64_1(int64x2_t vec)
{
	return vgetq_lane_s64(vec, 1);
}

uint64_t np_vgetq_lane_u64_0(uint64x2_t vec)
{
	return vgetq_lane_u64(vec, 0);
}

uint64_t np_vgetq_lane_u64_1(uint64x2_t vec)
{
	return vgetq_lane_u64(vec, 1);
}

uint8x16_t np_vsetq_lane_u8_0(uint8_t value, uint8x16_t vec)
{
	return vsetq_lane_u8(value, vec, 0);
}

uint8x16_t np_vsetq_lane_u8_1(uint8_t value, uint8x16_t vec)
{
	return vsetq_lane_u8(value, vec, 1);
}

uint8x16_t np_vsetq_lane_u8_2(uint8_t value, uint8x16_t vec)
{
	return vsetq_lane_u8(value, vec, 2);
}

uint8x16_t np_vsetq_lane_u8_3(uint8_t value, uint8x16_t vec)
{
	return vsetq_lane_u8(value, vec, 3);
}

uint8x16_t np_vsetq_lane_u8_4(uint8_t value, uint8x16_t vec)
{
	return vsetq_lane_u8(value, vec, 4);
}

uint8x16_t np_vsetq_lane_u8_5(uint8_t value, uint8x16_t vec)
{
	return vsetq_lane_u8(value, vec, 5);
}

uint8x16_t np_vsetq_lane_u8_6(uint8_t value, uint8x16_t vec)
{
	return vsetq_lane_u8(value, vec, 6);
}

uint8x16_t np_vsetq_lane_u8_7(uint8_t value, uint8x16_t vec)
{
	return vsetq_lane_u8(value, vec, 7);
}

uint8x16_t np_vsetq_lane_u8_8(uint8_t value, uint8x16_t vec)
{
	return vsetq_lane_u8(value, vec, 8);
}

uint8x16_t np_vsetq_lane_u8_9(uint8_t value, uint8x16_t vec)
{
	return vsetq_lane_u8(value, vec, 9);
}

uint8x16_t np_vsetq_lane_u8_10(uint8_t value, uint8x16_t vec)
{
	return vsetq_lane_u8(value, vec, 10);
}

uint8x16_t np_vsetq_lane_u8_11(uint8_t value, uint8x16_t vec)
{
	return vsetq_lane_u8(value, vec, 11);
}

uint8x16_t np_vsetq_lane_u8_12(uint8_t value, uint8x16_t vec)
{
	return vsetq_lane_u8(value, vec, 12);
}

uint8x16_t np_vsetq_lane_u8_13(uint8_t value, uint8x16_t vec)
{
	return vsetq_lane_u8(value, vec, 13);
}

uint8x16_t np_vsetq_lane_u8_14(uint8_t value, uint8x16_t vec)
{
	return vsetq_lane_u8(value, vec, 14);
}

uint8x16_t np_vsetq_lane_u8_15(uint8_t value, uint8x16_t vec)
{
	return vsetq_lane_u8(value, vec, 15);
}

uint16x8_t np_vsetq_lane_u16_0(uint16_t value, uint16x8_t vec)
{
	return vsetq_lane_u16(value, vec, 0);
}

uint16x8_t np_vsetq_lane_u16_1(uint16_t value, uint16x8_t vec)
{
	return vsetq_lane_u16(value, vec, 1);
}

uint16x8_t np_vsetq_lane_u16_2(uint16_t value, uint16x8_t vec)
{
	return vsetq_lane_u16(value, vec, 2);
}

uint16x8_t np_vsetq_lane_u16_3(uint16_t value, uint16x8_t vec)
{
	return vsetq_lane_u16(value, vec, 3);
}

uint16x8_t np_vsetq_lane_u16_4(uint16_t value, uint16x8_t vec)
{
	return vsetq_lane_u16(value, vec, 4);
}

uint16x8_t np_vsetq_lane_u16_5(uint16_t value, uint16x8_t vec)
{
	return vsetq_lane_u16(value, vec, 5);
}

uint16x8_t np_vsetq_lane_u16_6(uint16_t value, uint16x8_t vec)
{
	return vsetq_lane_u16(value, vec, 6);
}

uint16x8_t np_vsetq_lane_u16_7(uint16_t value, uint16x8_t vec)
{
	return vsetq_lane_u16(value, vec, 7);
}

uint32x4_t np_vsetq_lane_u32_0(uint32_t value, uint32x4_t vec)
{
	return vsetq_lane_u32(value, vec, 0);
}

uint32x4_t np_vsetq_lane_u32_1(uint32_t value, uint32x4_t vec)
{
	return vsetq_lane_u32(value, vec, 1);
}

uint32x4_t np_vsetq_lane_u32_2(uint32_t value, uint32x4_t vec)
{
	return vsetq_lane_u32(value, vec, 2);
}

uint32x4_t np_vsetq_lane_u32_3(uint32_t value, uint32x4_t vec)
{
	return vsetq_lane_u32(value, vec, 3);
}

int8x16_t np_vsetq_lane_s8_0(int8_t value, int8x16_t vec)
{
	return vsetq_lane_s8(value, vec, 0);
}

int8x16_t np_vsetq_lane_s8_1(int8_t value, int8x16_t vec)
{
	return vsetq_lane_s8(value, vec, 1);
}

int8x16_t np_vsetq_lane_s8_2(int8_t value, int8x16_t vec)
{
	return vsetq_lane_s8(value, vec, 2);
}

int8x16_t np_vsetq_lane_s8_3(int8_t value, int8x16_t vec)
{
	return vsetq_lane_s8(value, vec, 3);
}

int8x16_t np_vsetq_lane_s8_4(int8_t value, int8x16_t vec)
{
	return vsetq_lane_s8(value, vec, 4);
}

int8x16_t np_vsetq_lane_s8_5(int8_t value, int8x16_t vec)
{
	return vsetq_lane_s8(value, vec, 5);
}

int8x16_t np_vsetq_lane_s8_6(int8_t value, int8x16_t vec)
{
	return vsetq_lane_s8(value, vec, 6);
}

int8x16_t np_vsetq_lane_s8_7(int8_t value, int8x16_t vec)
{
	return vsetq_lane_s8(value, vec, 7);
}

int8x16_t np_vsetq_lane_s8_8(int8_t value, int8x16_t vec)
{
	return vsetq_lane_s8(value, vec, 8);
}

int8x16_t np_vsetq_lane_s8_9(int8_t value, int8x16_t vec)
{
	return vsetq_lane_s8(value, vec, 9);
}

int8x16_t np_vsetq_lane_s8_10(int8_t value, int8x16_t vec)
{
	return vsetq_lane_s8(value, vec, 10);
}

int8x16_t np_vsetq_lane_s8_11(int8_t value, int8x16_t vec)
{
	return vsetq_lane_s8(value, vec, 11);
}

int8x16_t np_vsetq_lane_s8_12(int8_t value, int8x16_t vec)
{
	return vsetq_lane_s8(value, vec, 12);
}

int8x16_t np_vsetq_lane_s8_13(int8_t value, int8x16_t vec)
{
	return vsetq_lane_s8(value, vec, 13);
}

int8x16_t np_vsetq_lane_s8_14(int8_t value, int8x16_t vec)
{
	return vsetq_lane_s8(value, vec, 14);
}

int8x16_t np_vsetq_lane_s8_15(int8_t value, int8x16_t vec)
{
	return vsetq_lane_s8(value, vec, 15);
}

int16x8_t np_vsetq_lane_s16_0(int16_t value, int16x8_t vec)
{
	return vsetq_lane_s16(value, vec, 0);
}

int16x8_t np_vsetq_lane_s16_1(int16_t value, int16x8_t vec)
{
	return vsetq_lane_s16(value, vec, 1);
}

int16x8_t np_vsetq_lane_s16_2(int16_t value, int16x8_t vec)
{
	return vsetq_lane_s16(value, vec, 2);
}

int16x8_t np_vsetq_lane_s16_3(int16_t value, int16x8_t vec)
{
	return vsetq_lane_s16(value, vec, 3);
}

int16x8_t np_vsetq_lane_s16_4(int16_t value, int16x8_t vec)
{
	return vsetq_lane_s16(value, vec, 4);
}

int16x8_t np_vsetq_lane_s16_5(int16_t value, int16x8_t vec)
{
	return vsetq_lane_s16(value, vec, 5);
}

int16x8_t np_vsetq_lane_s16_6(int16_t value, int16x8_t vec)
{
	return vsetq_lane_s16(value, vec, 6);
}

int16x8_t np_vsetq_lane_s16_7(int16_t value, int16x8_t vec)
{
	return vsetq_lane_s16(value, vec, 7);
}

int32x4_t np_vsetq_lane_s32_0(int32_t value, int32x4_t vec)
{
	return vsetq_lane_s32(value, vec, 0);
}

int32x4_t np_vsetq_lane_s32_1(int32_t value, int32x4_t vec)
{
	return vsetq_lane_s32(value, vec, 1);
}

int32x4_t np_vsetq_lane_s32_2(int32_t value, int32x4_t vec)
{
	return vsetq_lane_s32(value, vec, 2);
}

int32x4_t np_vsetq_lane_s32_3(int32_t value, int32x4_t vec)
{
	return vsetq_lane_s32(value, vec, 3);
}

poly8x16_t np_vsetq_lane_p8_0(poly8_t value, poly8x16_t vec)
{
	return vsetq_lane_p8(value, vec, 0);
}

poly8x16_t np_vsetq_lane_p8_1(poly8_t value, poly8x16_t vec)
{
	return vsetq_lane_p8(value, vec, 1);
}

poly8x16_t np_vsetq_lane_p8_2(poly8_t value, poly8x16_t vec)
{
	return vsetq_lane_p8(value, vec, 2);
}

poly8x16_t np_vsetq_lane_p8_3(poly8_t value, poly8x16_t vec)
{
	return vsetq_lane_p8(value, vec, 3);
}

poly8x16_t np_vsetq_lane_p8_4(poly8_t value, poly8x16_t vec)
{
	return vsetq_lane_p8(value, vec, 4);
}

poly8x16_t np_vsetq_lane_p8_5(poly8_t value, poly8x16_t vec)
{
	return vsetq_lane_p8(value, vec, 5);
}

poly8x16_t np_vsetq_lane_p8_6(poly8_t value, poly8x16_t vec)
{
	return vsetq_lane_p8(value, vec, 6);
}

poly8x16_t np_vsetq_lane_p8_7(poly8_t value, poly8x16_t vec)
{
	return vsetq_lane_p8(value, vec, 7);
}

poly8x16_t np_vsetq_lane_p8_8(poly8_t value, poly8x16_t vec)
{
	return vsetq_lane_p8(value, vec, 8);
}

poly8x16_t np_vsetq_lane_p8_9(poly8_t value, poly8x16_t vec)
{
	return vsetq_lane_p8(value, vec, 9);
}

poly8x16_t np_vsetq_lane_p8_10(poly8_t value, poly8x16_t vec)
{
	return vsetq_lane_p8(value, vec, 10);
}

poly8x16_t np_vsetq_lane_p8_11(poly8_t value, poly8x16_t vec)
{
	return vsetq_lane_p8(value, vec, 11);
}

poly8x16_t np_vsetq_lane_p8_12(poly8_t value, poly8x16_t vec)
{
	return vsetq_lane_p8(value, vec, 12);
}

poly8x16_t np_vsetq_lane_p8_13(poly8_t value, poly8x16_t vec)
{
	return vsetq_lane_p8(value, vec, 13);
}

poly8x16_t np_vsetq_lane_p8_14(poly8_t value, poly8x16_t vec)
{
	return vsetq_lane_p8(value, vec, 14);
}

poly8x16_t np_vsetq_lane_p8_15(poly8_t value, poly8x16_t vec)
{
	return vsetq_lane_p8(value, vec, 15);
}

poly16x8_t np_vsetq_lane_p16_0(poly16_t value, poly16x8_t vec)
{
	return vsetq_lane_p16(value, vec, 0);
}

poly16x8_t np_vsetq_lane_p16_1(poly16_t value, poly16x8_t vec)
{
	return vsetq_lane_p16(value, vec, 1);
}

poly16x8_t np_vsetq_lane_p16_2(poly16_t value, poly16x8_t vec)
{
	return vsetq_lane_p16(value, vec, 2);
}

poly16x8_t np_vsetq_lane_p16_3(poly16_t value, poly16x8_t vec)
{
	return vsetq_lane_p16(value, vec, 3);
}

poly16x8_t np_vsetq_lane_p16_4(poly16_t value, poly16x8_t vec)
{
	return vsetq_lane_p16(value, vec, 4);
}

poly16x8_t np_vsetq_lane_p16_5(poly16_t value, poly16x8_t vec)
{
	return vsetq_lane_p16(value, vec, 5);
}

poly16x8_t np_vsetq_lane_p16_6(poly16_t value, poly16x8_t vec)
{
	return vsetq_lane_p16(value, vec, 6);
}

poly16x8_t np_vsetq_lane_p16_7(poly16_t value, poly16x8_t vec)
{
	return vsetq_lane_p16(value, vec, 7);
}

float32x4_t np_vsetq_lane_f32_0(float32_t value, float32x4_t vec)
{
	return vsetq_lane_f32(value, vec, 0);
}

float32x4_t np_vsetq_lane_f32_1(float32_t value, float32x4_t vec)
{
	return vsetq_lane_f32(value, vec, 1);
}

float32x4_t np_vsetq_lane_f32_2(float32_t value, float32x4_t vec)
{
	return vsetq_lane_f32(value, vec, 2);
}

float32x4_t np_vsetq_lane_f32_3(float32_t value, float32x4_t vec)
{
	return vsetq_lane_f32(value, vec, 3);
}

int64x2_t np_vsetq_lane_s64_0(int64_t value, int64x2_t vec)
{
	return vsetq_lane_s64(value, vec, 0);
}

int64x2_t np_vsetq_lane_s64_1(int64_t value, int64x2_t vec)
{
	return vsetq_lane_s64(value, vec, 1);
}

uint64x2_t np_vsetq_lane_u64_0(uint64_t value, uint64x2_t vec)
{
	return vsetq_lane_u64(value, vec, 0);
}

uint64x2_t np_vsetq_lane_u64_1(uint64_t value, uint64x2_t vec)
{
	return vsetq_lane_u64(value, vec, 1);
}

uint8x16_t np_vdupq_n_u8(uint8_t value)
{
	return vdupq_n_u8(value);
}

uint16x8_t np_vdupq_n_u16(uint16_t value)
{
	return vdupq_n_u16(value);
}

uint32x4_t np_vdupq_n_u32(uint32_t value)
{
	return vdupq_n_u32(value);
}

int8x16_t np_vdupq_n_s8(int8_t value)
{
	return vdupq_n_s8(value);
}

int16x8_t np_vdupq_n_s16(int16_t value)
{
	return vdupq_n_s16(value);
}

int32x4_t np_vdupq_n_s32(int32_t value)
{
	return vdupq_n_s32(value);
}

poly8x16_t np_vdupq_n_p8(poly8_t value)
{
	return vdupq_n_p8(value);
}

poly16x8_t np_vdupq_n_p16(poly16_t value)
{
	return vdupq_n_p16(value);
}

float32x4_t np_vdupq_n_f32(float32_t value)
{
	return vdupq_n_f32(value);
}

int64x2_t np_vdupq_n_s64(int64_t value)
{
	return vdupq_n_s64(value);
}

uint64x2_t np_vdupq_n_u64(uint64_t value)
{
	return vdupq_n_u64(value);
}

uint8x16_t np_vmovq_n_u8(uint8_t value)
{
	return vmovq_n_u8(value);
}

uint16x8_t np_vmovq_n_u16(uint16_t value)
{
	return vmovq_n_u16(value);
}

uint32x4_t np_vmovq_n_u32(uint32_t value)
{
	return vmovq_n_u32(value);
}

int8x16_t np_vmovq_n_s8(int8_t value)
{
	return vmovq_n_s8(value);
}

int16x8_t np_vmovq_n_s16(int16_t value)
{
	return vmovq_n_s16(value);
}

int32x4_t np_vmovq_n_s32(int32_t value)
{
	return vmovq_n_s32(value);
}

poly8x16_t np_vmovq_n_p8(poly8_t value)
{
	return vmovq_n_p8(value);
}

poly16x8_t np_vmovq_n_p16(poly16_t value)
{
	return vmovq_n_p16(value);
}

float32x4_t np_vmovq_n_f32(float32_t value)
{
	return vmovq_n_f32(value);
}

int64x2_t np_vmovq_n_s64(int64_t value)
{
	return vmovq_n_s64(value);
}

uint64x2_t np_vmovq_n_u64(uint64_t value)
{
	return vmovq_n_u64(value);
}

int32x4_t np_vcvtq_s32_f32(float32x4_t a)
{
	return vcvtq_s32_f32(a);
}

uint32x4_t np_vcvtq_u32_f32(float32x4_t a)
{
	return vcvtq_u32_f32(a);
}

int32x4_t np_vcvtq_n_s32_f32_1(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 1);
}

int32x4_t np_vcvtq_n_s32_f32_2(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 2);
}

int32x4_t np_vcvtq_n_s32_f32_3(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 3);
}

int32x4_t np_vcvtq_n_s32_f32_4(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 4);
}

int32x4_t np_vcvtq_n_s32_f32_5(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 5);
}

int32x4_t np_vcvtq_n_s32_f32_6(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 6);
}

int32x4_t np_vcvtq_n_s32_f32_7(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 7);
}

int32x4_t np_vcvtq_n_s32_f32_8(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 8);
}

int32x4_t np_vcvtq_n_s32_f32_9(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 9);
}

int32x4_t np_vcvtq_n_s32_f32_10(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 10);
}

int32x4_t np_vcvtq_n_s32_f32_11(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 11);
}

int32x4_t np_vcvtq_n_s32_f32_12(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 12);
}

int32x4_t np_vcvtq_n_s32_f32_13(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 13);
}

int32x4_t np_vcvtq_n_s32_f32_14(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 14);
}

int32x4_t np_vcvtq_n_s32_f32_15(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 15);
}

int32x4_t np_vcvtq_n_s32_f32_16(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 16);
}

int32x4_t np_vcvtq_n_s32_f32_17(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 17);
}

int32x4_t np_vcvtq_n_s32_f32_18(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 18);
}

int32x4_t np_vcvtq_n_s32_f32_19(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 19);
}

int32x4_t np_vcvtq_n_s32_f32_20(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 20);
}

int32x4_t np_vcvtq_n_s32_f32_21(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 21);
}

int32x4_t np_vcvtq_n_s32_f32_22(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 22);
}

int32x4_t np_vcvtq_n_s32_f32_23(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 23);
}

int32x4_t np_vcvtq_n_s32_f32_24(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 24);
}

int32x4_t np_vcvtq_n_s32_f32_25(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 25);
}

int32x4_t np_vcvtq_n_s32_f32_26(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 26);
}

int32x4_t np_vcvtq_n_s32_f32_27(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 27);
}

int32x4_t np_vcvtq_n_s32_f32_28(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 28);
}

int32x4_t np_vcvtq_n_s32_f32_29(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 29);
}

int32x4_t np_vcvtq_n_s32_f32_30(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 30);
}

int32x4_t np_vcvtq_n_s32_f32_31(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 31);
}

int32x4_t np_vcvtq_n_s32_f32_32(float32x4_t a)
{
	return vcvtq_n_s32_f32(a, 32);
}

uint32x4_t np_vcvtq_n_u32_f32_1(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 1);
}

uint32x4_t np_vcvtq_n_u32_f32_2(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 2);
}

uint32x4_t np_vcvtq_n_u32_f32_3(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 3);
}

uint32x4_t np_vcvtq_n_u32_f32_4(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 4);
}

uint32x4_t np_vcvtq_n_u32_f32_5(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 5);
}

uint32x4_t np_vcvtq_n_u32_f32_6(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 6);
}

uint32x4_t np_vcvtq_n_u32_f32_7(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 7);
}

uint32x4_t np_vcvtq_n_u32_f32_8(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 8);
}

uint32x4_t np_vcvtq_n_u32_f32_9(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 9);
}

uint32x4_t np_vcvtq_n_u32_f32_10(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 10);
}

uint32x4_t np_vcvtq_n_u32_f32_11(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 11);
}

uint32x4_t np_vcvtq_n_u32_f32_12(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 12);
}

uint32x4_t np_vcvtq_n_u32_f32_13(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 13);
}

uint32x4_t np_vcvtq_n_u32_f32_14(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 14);
}

uint32x4_t np_vcvtq_n_u32_f32_15(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 15);
}

uint32x4_t np_vcvtq_n_u32_f32_16(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 16);
}

uint32x4_t np_vcvtq_n_u32_f32_17(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 17);
}

uint32x4_t np_vcvtq_n_u32_f32_18(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 18);
}

uint32x4_t np_vcvtq_n_u32_f32_19(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 19);
}

uint32x4_t np_vcvtq_n_u32_f32_20(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 20);
}

uint32x4_t np_vcvtq_n_u32_f32_21(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 21);
}

uint32x4_t np_vcvtq_n_u32_f32_22(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 22);
}

uint32x4_t np_vcvtq_n_u32_f32_23(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 23);
}

uint32x4_t np_vcvtq_n_u32_f32_24(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 24);
}

uint32x4_t np_vcvtq_n_u32_f32_25(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 25);
}

uint32x4_t np_vcvtq_n_u32_f32_26(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 26);
}

uint32x4_t np_vcvtq_n_u32_f32_27(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 27);
}

uint32x4_t np_vcvtq_n_u32_f32_28(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 28);
}

uint32x4_t np_vcvtq_n_u32_f32_29(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 29);
}

uint32x4_t np_vcvtq_n_u32_f32_30(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 30);
}

uint32x4_t np_vcvtq_n_u32_f32_31(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 31);
}

uint32x4_t np_vcvtq_n_u32_f32_32(float32x4_t a)
{
	return vcvtq_n_u32_f32(a, 32);
}

float32x4_t np_vcvtq_f32_s32(int32x4_t a)
{
	return vcvtq_f32_s32(a);
}

float32x4_t np_vcvtq_f32_u32(uint32x4_t a)
{
	return vcvtq_f32_u32(a);
}

float32x4_t np_vcvtq_n_f32_s32_1(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 1);
}

float32x4_t np_vcvtq_n_f32_s32_2(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 2);
}

float32x4_t np_vcvtq_n_f32_s32_3(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 3);
}

float32x4_t np_vcvtq_n_f32_s32_4(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 4);
}

float32x4_t np_vcvtq_n_f32_s32_5(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 5);
}

float32x4_t np_vcvtq_n_f32_s32_6(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 6);
}

float32x4_t np_vcvtq_n_f32_s32_7(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 7);
}

float32x4_t np_vcvtq_n_f32_s32_8(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 8);
}

float32x4_t np_vcvtq_n_f32_s32_9(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 9);
}

float32x4_t np_vcvtq_n_f32_s32_10(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 10);
}

float32x4_t np_vcvtq_n_f32_s32_11(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 11);
}

float32x4_t np_vcvtq_n_f32_s32_12(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 12);
}

float32x4_t np_vcvtq_n_f32_s32_13(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 13);
}

float32x4_t np_vcvtq_n_f32_s32_14(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 14);
}

float32x4_t np_vcvtq_n_f32_s32_15(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 15);
}

float32x4_t np_vcvtq_n_f32_s32_16(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 16);
}

float32x4_t np_vcvtq_n_f32_s32_17(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 17);
}

float32x4_t np_vcvtq_n_f32_s32_18(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 18);
}

float32x4_t np_vcvtq_n_f32_s32_19(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 19);
}

float32x4_t np_vcvtq_n_f32_s32_20(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 20);
}

float32x4_t np_vcvtq_n_f32_s32_21(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 21);
}

float32x4_t np_vcvtq_n_f32_s32_22(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 22);
}

float32x4_t np_vcvtq_n_f32_s32_23(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 23);
}

float32x4_t np_vcvtq_n_f32_s32_24(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 24);
}

float32x4_t np_vcvtq_n_f32_s32_25(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 25);
}

float32x4_t np_vcvtq_n_f32_s32_26(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 26);
}

float32x4_t np_vcvtq_n_f32_s32_27(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 27);
}

float32x4_t np_vcvtq_n_f32_s32_28(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 28);
}

float32x4_t np_vcvtq_n_f32_s32_29(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 29);
}

float32x4_t np_vcvtq_n_f32_s32_30(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 30);
}

float32x4_t np_vcvtq_n_f32_s32_31(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 31);
}

float32x4_t np_vcvtq_n_f32_s32_32(int32x4_t a)
{
	return vcvtq_n_f32_s32(a, 32);
}

float32x4_t np_vcvtq_n_f32_u32_1(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 1);
}

float32x4_t np_vcvtq_n_f32_u32_2(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 2);
}

float32x4_t np_vcvtq_n_f32_u32_3(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 3);
}

float32x4_t np_vcvtq_n_f32_u32_4(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 4);
}

float32x4_t np_vcvtq_n_f32_u32_5(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 5);
}

float32x4_t np_vcvtq_n_f32_u32_6(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 6);
}

float32x4_t np_vcvtq_n_f32_u32_7(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 7);
}

float32x4_t np_vcvtq_n_f32_u32_8(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 8);
}

float32x4_t np_vcvtq_n_f32_u32_9(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 9);
}

float32x4_t np_vcvtq_n_f32_u32_10(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 10);
}

float32x4_t np_vcvtq_n_f32_u32_11(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 11);
}

float32x4_t np_vcvtq_n_f32_u32_12(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 12);
}

float32x4_t np_vcvtq_n_f32_u32_13(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 13);
}

float32x4_t np_vcvtq_n_f32_u32_14(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 14);
}

float32x4_t np_vcvtq_n_f32_u32_15(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 15);
}

float32x4_t np_vcvtq_n_f32_u32_16(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 16);
}

float32x4_t np_vcvtq_n_f32_u32_17(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 17);
}

float32x4_t np_vcvtq_n_f32_u32_18(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 18);
}

float32x4_t np_vcvtq_n_f32_u32_19(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 19);
}

float32x4_t np_vcvtq_n_f32_u32_20(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 20);
}

float32x4_t np_vcvtq_n_f32_u32_21(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 21);
}

float32x4_t np_vcvtq_n_f32_u32_22(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 22);
}

float32x4_t np_vcvtq_n_f32_u32_23(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 23);
}

float32x4_t np_vcvtq_n_f32_u32_24(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 24);
}

float32x4_t np_vcvtq_n_f32_u32_25(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 25);
}

float32x4_t np_vcvtq_n_f32_u32_26(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 26);
}

float32x4_t np_vcvtq_n_f32_u32_27(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 27);
}

float32x4_t np_vcvtq_n_f32_u32_28(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 28);
}

float32x4_t np_vcvtq_n_f32_u32_29(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 29);
}

float32x4_t np_vcvtq_n_f32_u32_30(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 30);
}

float32x4_t np_vcvtq_n_f32_u32_31(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 31);
}

float32x4_t np_vcvtq_n_f32_u32_32(uint32x4_t a)
{
	return vcvtq_n_f32_u32(a, 32);
}

int16x8_t np_vmulq_n_s16(int16x8_t a, int16_t b)
{
	return vmulq_n_s16(a, b);
}

int32x4_t np_vmulq_n_s32(int32x4_t a, int32_t b)
{
	return vmulq_n_s32(a, b);
}

float32x4_t np_vmulq_n_f32(float32x4_t a, float32_t b)
{
	return vmulq_n_f32(a, b);
}

uint16x8_t np_vmulq_n_u16(uint16x8_t a, uint16_t b)
{
	return vmulq_n_u16(a, b);
}

uint32x4_t np_vmulq_n_u32(uint32x4_t a, uint32_t b)
{
	return vmulq_n_u32(a, b);
}

int16x8_t np_vqdmulhq_n_s16(int16x8_t vec1, int16_t val2)
{
	return vqdmulhq_n_s16(vec1, val2);
}

int32x4_t np_vqdmulhq_n_s32(int32x4_t vec1, int32_t val2)
{
	return vqdmulhq_n_s32(vec1, val2);
}

int16x8_t np_vqrdmulhq_n_s16(int16x8_t vec1, int16_t val2)
{
	return vqrdmulhq_n_s16(vec1, val2);
}

int32x4_t np_vqrdmulhq_n_s32(int32x4_t vec1, int32_t val2)
{
	return vqrdmulhq_n_s32(vec1, val2);
}

int16x8_t np_vmlaq_n_s16(int16x8_t a, int16x8_t b, int16_t c)
{
	return vmlaq_n_s16(a, b, c);
}

int32x4_t np_vmlaq_n_s32(int32x4_t a, int32x4_t b, int32_t c)
{
	return vmlaq_n_s32(a, b, c);
}

uint16x8_t np_vmlaq_n_u16(uint16x8_t a, uint16x8_t b, uint16_t c)
{
	return vmlaq_n_u16(a, b, c);
}

uint32x4_t np_vmlaq_n_u32(uint32x4_t a, uint32x4_t b, uint32_t c)
{
	return vmlaq_n_u32(a, b, c);
}

float32x4_t np_vmlaq_n_f32(float32x4_t a, float32x4_t b, float32_t c)
{
	return vmlaq_n_f32(a, b, c);
}

int16x8_t np_vmlsq_n_s16(int16x8_t a, int16x8_t b, int16_t c)
{
	return vmlsq_n_s16(a, b, c);
}

int32x4_t np_vmlsq_n_s32(int32x4_t a, int32x4_t b, int32_t c)
{
	return vmlsq_n_s32(a, b, c);
}

uint16x8_t np_vmlsq_n_u16(uint16x8_t a, uint16x8_t b, uint16_t c)
{
	return vmlsq_n_u16(a, b, c);
}

uint32x4_t np_vmlsq_n_u32(uint32x4_t a, uint32x4_t b, uint32_t c)
{
	return vmlsq_n_u32(a, b, c);
}

float32x4_t np_vmlsq_n_f32(float32x4_t a, float32x4_t b, float32_t c)
{
	return vmlsq_n_f32(a, b, c);
}

int8x16_t np_vextq_s8_0(int8x16_t a, int8x16_t b)
{
	return vextq_s8(a, b, 0);
}

int8x16_t np_vextq_s8_1(int8x16_t a, int8x16_t b)
{
	return vextq_s8(a, b, 1);
}

int8x16_t np_vextq_s8_2(int8x16_t a, int8x16_t b)
{
	return vextq_s8(a, b, 2);
}

int8x16_t np_vextq_s8_3(int8x16_t a, int8x16_t b)
{
	return vextq_s8(a, b, 3);
}

int8x16_t np_vextq_s8_4(int8x16_t a, int8x16_t b)
{
	return vextq_s8(a, b, 4);
}

int8x16_t np_vextq_s8_5(int8x16_t a, int8x16_t b)
{
	return vextq_s8(a, b, 5);
}

int8x16_t np_vextq_s8_6(int8x16_t a, int8x16_t b)
{
	return vextq_s8(a, b, 6);
}

int8x16_t np_vextq_s8_7(int8x16_t a, int8x16_t b)
{
	return vextq_s8(a, b, 7);
}

int8x16_t np_vextq_s8_8(int8x16_t a, int8x16_t b)
{
	return vextq_s8(a, b, 8);
}

int8x16_t np_vextq_s8_9(int8x16_t a, int8x16_t b)
{
	return vextq_s8(a, b, 9);
}

int8x16_t np_vextq_s8_10(int8x16_t a, int8x16_t b)
{
	return vextq_s8(a, b, 10);
}

int8x16_t np_vextq_s8_11(int8x16_t a, int8x16_t b)
{
	return vextq_s8(a, b, 11);
}

int8x16_t np_vextq_s8_12(int8x16_t a, int8x16_t b)
{
	return vextq_s8(a, b, 12);
}

int8x16_t np_vextq_s8_13(int8x16_t a, int8x16_t b)
{
	return vextq_s8(a, b, 13);
}

int8x16_t np_vextq_s8_14(int8x16_t a, int8x16_t b)
{
	return vextq_s8(a, b, 14);
}

int8x16_t np_vextq_s8_15(int8x16_t a, int8x16_t b)
{
	return vextq_s8(a, b, 15);
}

uint8x16_t np_vextq_u8_0(uint8x16_t a, uint8x16_t b)
{
	return vextq_u8(a, b, 0);
}

uint8x16_t np_vextq_u8_1(uint8x16_t a, uint8x16_t b)
{
	return vextq_u8(a, b, 1);
}

uint8x16_t np_vextq_u8_2(uint8x16_t a, uint8x16_t b)
{
	return vextq_u8(a, b, 2);
}

uint8x16_t np_vextq_u8_3(uint8x16_t a, uint8x16_t b)
{
	return vextq_u8(a, b, 3);
}

uint8x16_t np_vextq_u8_4(uint8x16_t a, uint8x16_t b)
{
	return vextq_u8(a, b, 4);
}

uint8x16_t np_vextq_u8_5(uint8x16_t a, uint8x16_t b)
{
	return vextq_u8(a, b, 5);
}

uint8x16_t np_vextq_u8_6(uint8x16_t a, uint8x16_t b)
{
	return vextq_u8(a, b, 6);
}

uint8x16_t np_vextq_u8_7(uint8x16_t a, uint8x16_t b)
{
	return vextq_u8(a, b, 7);
}

uint8x16_t np_vextq_u8_8(uint8x16_t a, uint8x16_t b)
{
	return vextq_u8(a, b, 8);
}

uint8x16_t np_vextq_u8_9(uint8x16_t a, uint8x16_t b)
{
	return vextq_u8(a, b, 9);
}

uint8x16_t np_vextq_u8_10(uint8x16_t a, uint8x16_t b)
{
	return vextq_u8(a, b, 10);
}

uint8x16_t np_vextq_u8_11(uint8x16_t a, uint8x16_t b)
{
	return vextq_u8(a, b, 11);
}

uint8x16_t np_vextq_u8_12(uint8x16_t a, uint8x16_t b)
{
	return vextq_u8(a, b, 12);
}

uint8x16_t np_vextq_u8_13(uint8x16_t a, uint8x16_t b)
{
	return vextq_u8(a, b, 13);
}

uint8x16_t np_vextq_u8_14(uint8x16_t a, uint8x16_t b)
{
	return vextq_u8(a, b, 14);
}

uint8x16_t np_vextq_u8_15(uint8x16_t a, uint8x16_t b)
{
	return vextq_u8(a, b, 15);
}

poly8x16_t np_vextq_p8_0(poly8x16_t a, poly8x16_t b)
{
	return vextq_p8(a, b, 0);
}

poly8x16_t np_vextq_p8_1(poly8x16_t a, poly8x16_t b)
{
	return vextq_p8(a, b, 1);
}

poly8x16_t np_vextq_p8_2(poly8x16_t a, poly8x16_t b)
{
	return vextq_p8(a, b, 2);
}

poly8x16_t np_vextq_p8_3(poly8x16_t a, poly8x16_t b)
{
	return vextq_p8(a, b, 3);
}

poly8x16_t np_vextq_p8_4(poly8x16_t a, poly8x16_t b)
{
	return vextq_p8(a, b, 4);
}

poly8x16_t np_vextq_p8_5(poly8x16_t a, poly8x16_t b)
{
	return vextq_p8(a, b, 5);
}

poly8x16_t np_vextq_p8_6(poly8x16_t a, poly8x16_t b)
{
	return vextq_p8(a, b, 6);
}

poly8x16_t np_vextq_p8_7(poly8x16_t a, poly8x16_t b)
{
	return vextq_p8(a, b, 7);
}

poly8x16_t np_vextq_p8_8(poly8x16_t a, poly8x16_t b)
{
	return vextq_p8(a, b, 8);
}

poly8x16_t np_vextq_p8_9(poly8x16_t a, poly8x16_t b)
{
	return vextq_p8(a, b, 9);
}

poly8x16_t np_vextq_p8_10(poly8x16_t a, poly8x16_t b)
{
	return vextq_p8(a, b, 10);
}

poly8x16_t np_vextq_p8_11(poly8x16_t a, poly8x16_t b)
{
	return vextq_p8(a, b, 11);
}

poly8x16_t np_vextq_p8_12(poly8x16_t a, poly8x16_t b)
{
	return vextq_p8(a, b, 12);
}

poly8x16_t np_vextq_p8_13(poly8x16_t a, poly8x16_t b)
{
	return vextq_p8(a, b, 13);
}

poly8x16_t np_vextq_p8_14(poly8x16_t a, poly8x16_t b)
{
	return vextq_p8(a, b, 14);
}

poly8x16_t np_vextq_p8_15(poly8x16_t a, poly8x16_t b)
{
	return vextq_p8(a, b, 15);
}

int16x8_t np_vextq_s16_0(int16x8_t a, int16x8_t b)
{
	return vextq_s16(a, b, 0);
}

int16x8_t np_vextq_s16_1(int16x8_t a, int16x8_t b)
{
	return vextq_s16(a, b, 1);
}

int16x8_t np_vextq_s16_2(int16x8_t a, int16x8_t b)
{
	return vextq_s16(a, b, 2);
}

int16x8_t np_vextq_s16_3(int16x8_t a, int16x8_t b)
{
	return vextq_s16(a, b, 3);
}

int16x8_t np_vextq_s16_4(int16x8_t a, int16x8_t b)
{
	return vextq_s16(a, b, 4);
}

int16x8_t np_vextq_s16_5(int16x8_t a, int16x8_t b)
{
	return vextq_s16(a, b, 5);
}

int16x8_t np_vextq_s16_6(int16x8_t a, int16x8_t b)
{
	return vextq_s16(a, b, 6);
}

int16x8_t np_vextq_s16_7(int16x8_t a, int16x8_t b)
{
	return vextq_s16(a, b, 7);
}

uint16x8_t np_vextq_u16_0(uint16x8_t a, uint16x8_t b)
{
	return vextq_u16(a, b, 0);
}

uint16x8_t np_vextq_u16_1(uint16x8_t a, uint16x8_t b)
{
	return vextq_u16(a, b, 1);
}

uint16x8_t np_vextq_u16_2(uint16x8_t a, uint16x8_t b)
{
	return vextq_u16(a, b, 2);
}

uint16x8_t np_vextq_u16_3(uint16x8_t a, uint16x8_t b)
{
	return vextq_u16(a, b, 3);
}

uint16x8_t np_vextq_u16_4(uint16x8_t a, uint16x8_t b)
{
	return vextq_u16(a, b, 4);
}

uint16x8_t np_vextq_u16_5(uint16x8_t a, uint16x8_t b)
{
	return vextq_u16(a, b, 5);
}

uint16x8_t np_vextq_u16_6(uint16x8_t a, uint16x8_t b)
{
	return vextq_u16(a, b, 6);
}

uint16x8_t np_vextq_u16_7(uint16x8_t a, uint16x8_t b)
{
	return vextq_u16(a, b, 7);
}

poly16x8_t np_vextq_p16_0(poly16x8_t a, poly16x8_t b)
{
	return vextq_p16(a, b, 0);
}

poly16x8_t np_vextq_p16_1(poly16x8_t a, poly16x8_t b)
{
	return vextq_p16(a, b, 1);
}

poly16x8_t np_vextq_p16_2(poly16x8_t a, poly16x8_t b)
{
	return vextq_p16(a, b, 2);
}

poly16x8_t np_vextq_p16_3(poly16x8_t a, poly16x8_t b)
{
	return vextq_p16(a, b, 3);
}

poly16x8_t np_vextq_p16_4(poly16x8_t a, poly16x8_t b)
{
	return vextq_p16(a, b, 4);
}

poly16x8_t np_vextq_p16_5(poly16x8_t a, poly16x8_t b)
{
	return vextq_p16(a, b, 5);
}

poly16x8_t np_vextq_p16_6(poly16x8_t a, poly16x8_t b)
{
	return vextq_p16(a, b, 6);
}

poly16x8_t np_vextq_p16_7(poly16x8_t a, poly16x8_t b)
{
	return vextq_p16(a, b, 7);
}

int32x4_t np_vextq_s32_0(int32x4_t a, int32x4_t b)
{
	return vextq_s32(a, b, 0);
}

int32x4_t np_vextq_s32_1(int32x4_t a, int32x4_t b)
{
	return vextq_s32(a, b, 1);
}

int32x4_t np_vextq_s32_2(int32x4_t a, int32x4_t b)
{
	return vextq_s32(a, b, 2);
}

int32x4_t np_vextq_s32_3(int32x4_t a, int32x4_t b)
{
	return vextq_s32(a, b, 3);
}

uint32x4_t np_vextq_u32_0(uint32x4_t a, uint32x4_t b)
{
	return vextq_u32(a, b, 0);
}

uint32x4_t np_vextq_u32_1(uint32x4_t a, uint32x4_t b)
{
	return vextq_u32(a, b, 1);
}

uint32x4_t np_vextq_u32_2(uint32x4_t a, uint32x4_t b)
{
	return vextq_u32(a, b, 2);
}

uint32x4_t np_vextq_u32_3(uint32x4_t a, uint32x4_t b)
{
	return vextq_u32(a, b, 3);
}

int64x2_t np_vextq_s64_0(int64x2_t a, int64x2_t b)
{
	return vextq_s64(a, b, 0);
}

int64x2_t np_vextq_s64_1(int64x2_t a, int64x2_t b)
{
	return vextq_s64(a, b, 1);
}

uint64x2_t np_vextq_u64_0(uint64x2_t a, uint64x2_t b)
{
	return vextq_u64(a, b, 0);
}

uint64x2_t np_vextq_u64_1(uint64x2_t a, uint64x2_t b)
{
	return vextq_u64(a, b, 1);
}

float32x4_t np_vextq_f32_0(float32x4_t a, float32x4_t b)
{
	return vextq_f32(a, b, 0);
}

float32x4_t np_vextq_f32_1(float32x4_t a, float32x4_t b)
{
	return vextq_f32(a, b, 1);
}

float32x4_t np_vextq_f32_2(float32x4_t a, float32x4_t b)
{
	return vextq_f32(a, b, 2);
}

float32x4_t np_vextq_f32_3(float32x4_t a, float32x4_t b)
{
	return vextq_f32(a, b, 3);
}

int8x16_t np_vrev64q_s8(int8x16_t vec)
{
	return vrev64q_s8(vec);
}

int16x8_t np_vrev64q_s16(int16x8_t vec)
{
	return vrev64q_s16(vec);
}

int32x4_t np_vrev64q_s32(int32x4_t vec)
{
	return vrev64q_s32(vec);
}

uint8x16_t np_vrev64q_u8(uint8x16_t vec)
{
	return vrev64q_u8(vec);
}

uint16x8_t np_vrev64q_u16(uint16x8_t vec)
{
	return vrev64q_u16(vec);
}

uint32x4_t np_vrev64q_u32(uint32x4_t vec)
{
	return vrev64q_u32(vec);
}

poly8x16_t np_vrev64q_p8(poly8x16_t vec)
{
	return vrev64q_p8(vec);
}

poly16x8_t np_vrev64q_p16(poly16x8_t vec)
{
	return vrev64q_p16(vec);
}

float32x4_t np_vrev64q_f32(float32x4_t vec)
{
	return vrev64q_f32(vec);
}

int8x16_t np_vrev32q_s8(int8x16_t vec)
{
	return vrev32q_s8(vec);
}

int16x8_t np_vrev32q_s16(int16x8_t vec)
{
	return vrev32q_s16(vec);
}

uint8x16_t np_vrev32q_u8(uint8x16_t vec)
{
	return vrev32q_u8(vec);
}

uint16x8_t np_vrev32q_u16(uint16x8_t vec)
{
	return vrev32q_u16(vec);
}

poly8x16_t np_vrev32q_p8(poly8x16_t vec)
{
	return vrev32q_p8(vec);
}

poly16x8_t np_vrev32q_p16(poly16x8_t vec)
{
	return vrev32q_p16(vec);
}

int8x16_t np_vrev16q_s8(int8x16_t vec)
{
	return vrev16q_s8(vec);
}

uint8x16_t np_vrev16q_u8(uint8x16_t vec)
{
	return vrev16q_u8(vec);
}

poly8x16_t np_vrev16q_p8(poly8x16_t vec)
{
	return vrev16q_p8(vec);
}

int8x16_t np_vabsq_s8(int8x16_t a)
{
	return vabsq_s8(a);
}

int16x8_t np_vabsq_s16(int16x8_t a)
{
	return vabsq_s16(a);
}

int32x4_t np_vabsq_s32(int32x4_t a)
{
	return vabsq_s32(a);
}

float32x4_t np_vabsq_f32(float32x4_t a)
{
	return vabsq_f32(a);
}

int8x16_t np_vqabsq_s8(int8x16_t a)
{
	return vqabsq_s8(a);
}

int16x8_t np_vqabsq_s16(int16x8_t a)
{
	return vqabsq_s16(a);
}

int32x4_t np_vqabsq_s32(int32x4_t a)
{
	return vqabsq_s32(a);
}

int8x16_t np_vnegq_s8(int8x16_t a)
{
	return vnegq_s8(a);
}

int16x8_t np_vnegq_s16(int16x8_t a)
{
	return vnegq_s16(a);
}

int32x4_t np_vnegq_s32(int32x4_t a)
{
	return vnegq_s32(a);
}

float32x4_t np_vnegq_f32(float32x4_t a)
{
	return vnegq_f32(a);
}

int8x16_t np_vqnegq_s8(int8x16_t a)
{
	return vqnegq_s8(a);
}

int16x8_t np_vqnegq_s16(int16x8_t a)
{
	return vqnegq_s16(a);
}

int32x4_t np_vqnegq_s32(int32x4_t a)
{
	return vqnegq_s32(a);
}

int8x16_t np_vclsq_s8(int8x16_t a)
{
	return vclsq_s8(a);
}

int16x8_t np_vclsq_s16(int16x8_t a)
{
	return vclsq_s16(a);
}

int32x4_t np_vclsq_s32(int32x4_t a)
{
	return vclsq_s32(a);
}

int8x16_t np_vclzq_s8(int8x16_t a)
{
	return vclzq_s8(a);
}

int16x8_t np_vclzq_s16(int16x8_t a)
{
	return vclzq_s16(a);
}

int32x4_t np_vclzq_s32(int32x4_t a)
{
	return vclzq_s32(a);
}

uint8x16_t np_vclzq_u8(uint8x16_t a)
{
	return vclzq_u8(a);
}

uint16x8_t np_vclzq_u16(uint16x8_t a)
{
	return vclzq_u16(a);
}

uint32x4_t np_vclzq_u32(uint32x4_t a)
{
	return vclzq_u32(a);
}

uint8x16_t np_vcntq_u8(uint8x16_t a)
{
	return vcntq_u8(a);
}

int8x16_t np_vcntq_s8(int8x16_t a)
{
	return vcntq_s8(a);
}

poly8x16_t np_vcntq_p8(poly8x16_t a)
{
	return vcntq_p8(a);
}

float32x4_t np_vrecpeq_f32(float32x4_t a)
{
	return vrecpeq_f32(a);
}

uint32x4_t np_vrecpeq_u32(uint32x4_t a)
{
	return vrecpeq_u32(a);
}

float32x4_t np_vrsqrteq_f32(float32x4_t a)
{
	return vrsqrteq_f32(a);
}

uint32x4_t np_vrsqrteq_u32(uint32x4_t a)
{
	return vrsqrteq_u32(a);
}

int8x16_t np_vmvnq_s8(int8x16_t a)
{
	return vmvnq_s8(a);
}

int16x8_t np_vmvnq_s16(int16x8_t a)
{
	return vmvnq_s16(a);
}

int32x4_t np_vmvnq_s32(int32x4_t a)
{
	return vmvnq_s32(a);
}

uint8x16_t np_vmvnq_u8(uint8x16_t a)
{
	return vmvnq_u8(a);
}

uint16x8_t np_vmvnq_u16(uint16x8_t a)
{
	return vmvnq_u16(a);
}

uint32x4_t np_vmvnq_u32(uint32x4_t a)
{
	return vmvnq_u32(a);
}

poly8x16_t np_vmvnq_p8(poly8x16_t a)
{
	return vmvnq_p8(a);
}

int8x16_t np_vandq_s8(int8x16_t a, int8x16_t b)
{
	return vandq_s8(a, b);
}

int16x8_t np_vandq_s16(int16x8_t a, int16x8_t b)
{
	return vandq_s16(a, b);
}

int32x4_t np_vandq_s32(int32x4_t a, int32x4_t b)
{
	return vandq_s32(a, b);
}

int64x2_t np_vandq_s64(int64x2_t a, int64x2_t b)
{
	return vandq_s64(a, b);
}

uint8x16_t np_vandq_u8(uint8x16_t a, uint8x16_t b)
{
	return vandq_u8(a, b);
}

uint16x8_t np_vandq_u16(uint16x8_t a, uint16x8_t b)
{
	return vandq_u16(a, b);
}

uint32x4_t np_vandq_u32(uint32x4_t a, uint32x4_t b)
{
	return vandq_u32(a, b);
}

uint64x2_t np_vandq_u64(uint64x2_t a, uint64x2_t b)
{
	return vandq_u64(a, b);
}

int8x16_t np_vorrq_s8(int8x16_t a, int8x16_t b)
{
	return vorrq_s8(a, b);
}

int16x8_t np_vorrq_s16(int16x8_t a, int16x8_t b)
{
	return vorrq_s16(a, b);
}

int32x4_t np_vorrq_s32(int32x4_t a, int32x4_t b)
{
	return vorrq_s32(a, b);
}

int64x2_t np_vorrq_s64(int64x2_t a, int64x2_t b)
{
	return vorrq_s64(a, b);
}

uint8x16_t np_vorrq_u8(uint8x16_t a, uint8x16_t b)
{
	return vorrq_u8(a, b);
}

uint16x8_t np_vorrq_u16(uint16x8_t a, uint16x8_t b)
{
	return vorrq_u16(a, b);
}

uint32x4_t np_vorrq_u32(uint32x4_t a, uint32x4_t b)
{
	return vorrq_u32(a, b);
}

uint64x2_t np_vorrq_u64(uint64x2_t a, uint64x2_t b)
{
	return vorrq_u64(a, b);
}

int8x16_t np_veorq_s8(int8x16_t a, int8x16_t b)
{
	return veorq_s8(a, b);
}

int16x8_t np_veorq_s16(int16x8_t a, int16x8_t b)
{
	return veorq_s16(a, b);
}

int32x4_t np_veorq_s32(int32x4_t a, int32x4_t b)
{
	return veorq_s32(a, b);
}

int64x2_t np_veorq_s64(int64x2_t a, int64x2_t b)
{
	return veorq_s64(a, b);
}

uint8x16_t np_veorq_u8(uint8x16_t a, uint8x16_t b)
{
	return veorq_u8(a, b);
}

uint16x8_t np_veorq_u16(uint16x8_t a, uint16x8_t b)
{
	return veorq_u16(a, b);
}

uint32x4_t np_veorq_u32(uint32x4_t a, uint32x4_t b)
{
	return veorq_u32(a, b);
}

uint64x2_t np_veorq_u64(uint64x2_t a, uint64x2_t b)
{
	return veorq_u64(a, b);
}

int8x16_t np_vbicq_s8(int8x16_t a, int8x16_t b)
{
	return vbicq_s8(a, b);
}

int16x8_t np_vbicq_s16(int16x8_t a, int16x8_t b)
{
	return vbicq_s16(a, b);
}

int32x4_t np_vbicq_s32(int32x4_t a, int32x4_t b)
{
	return vbicq_s32(a, b);
}

int64x2_t np_vbicq_s64(int64x2_t a, int64x2_t b)
{
	return vbicq_s64(a, b);
}

uint8x16_t np_vbicq_u8(uint8x16_t a, uint8x16_t b)
{
	return vbicq_u8(a, b);
}

uint16x8_t np_vbicq_u16(uint16x8_t a, uint16x8_t b)
{
	return vbicq_u16(a, b);
}

uint32x4_t np_vbicq_u32(uint32x4_t a, uint32x4_t b)
{
	return vbicq_u32(a, b);
}

uint64x2_t np_vbicq_u64(uint64x2_t a, uint64x2_t b)
{
	return vbicq_u64(a, b);
}

int8x16_t np_vornq_s8(int8x16_t a, int8x16_t b)
{
	return vornq_s8(a, b);
}

int16x8_t np_vornq_s16(int16x8_t a, int16x8_t b)
{
	return vornq_s16(a, b);
}

int32x4_t np_vornq_s32(int32x4_t a, int32x4_t b)
{
	return vornq_s32(a, b);
}

int64x2_t np_vornq_s64(int64x2_t a, int64x2_t b)
{
	return vornq_s64(a, b);
}

uint8x16_t np_vornq_u8(uint8x16_t a, uint8x16_t b)
{
	return vornq_u8(a, b);
}

uint16x8_t np_vornq_u16(uint16x8_t a, uint16x8_t b)
{
	return vornq_u16(a, b);
}

uint32x4_t np_vornq_u32(uint32x4_t a, uint32x4_t b)
{
	return vornq_u32(a, b);
}

uint64x2_t np_vornq_u64(uint64x2_t a, uint64x2_t b)
{
	return vornq_u64(a, b);
}

int8x16_t np_vbslq_s8(uint8x16_t a, int8x16_t b, int8x16_t c)
{
	return vbslq_s8(a, b, c);
}

int16x8_t np_vbslq_s16(uint16x8_t a, int16x8_t b, int16x8_t c)
{
	return vbslq_s16(a, b, c);
}

int32x4_t np_vbslq_s32(uint32x4_t a, int32x4_t b, int32x4_t c)
{
	return vbslq_s32(a, b, c);
}

int64x2_t np_vbslq_s64(uint64x2_t a, int64x2_t b, int64x2_t c)
{
	return vbslq_s64(a, b, c);
}

uint8x16_t np_vbslq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c)
{
	return vbslq_u8(a, b, c);
}

uint16x8_t np_vbslq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c)
{
	return vbslq_u16(a, b, c);
}

uint32x4_t np_vbslq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c)
{
	return vbslq_u32(a, b, c);
}

uint64x2_t np_vbslq_u64(uint64x2_t a, uint64x2_t b, uint64x2_t c)
{
	return vbslq_u64(a, b, c);
}

float32x4_t np_vbslq_f32(uint32x4_t a, float32x4_t b, float32x4_t c)
{
	return vbslq_f32(a, b, c);
}

poly8x16_t np_vbslq_p8(uint8x16_t a, poly8x16_t b, poly8x16_t c)
{
	return vbslq_p8(a, b, c);
}

poly16x8_t np_vbslq_p16(uint16x8_t a, poly16x8_t b, poly16x8_t c)
{
	return vbslq_p16(a, b, c);
}

int8x16x2_t np_vtrnq_s8(int8x16_t a, int8x16_t b)
{
	return vtrnq_s8(a, b);
}

int16x8x2_t np_vtrnq_s16(int16x8_t a, int16x8_t b)
{
	return vtrnq_s16(a, b);
}

int32x4x2_t np_vtrnq_s32(int32x4_t a, int32x4_t b)
{
	return vtrnq_s32(a, b);
}

uint8x16x2_t np_vtrnq_u8(uint8x16_t a, uint8x16_t b)
{
	return vtrnq_u8(a, b);
}

uint16x8x2_t np_vtrnq_u16(uint16x8_t a, uint16x8_t b)
{
	return vtrnq_u16(a, b);
}

uint32x4x2_t np_vtrnq_u32(uint32x4_t a, uint32x4_t b)
{
	return vtrnq_u32(a, b);
}

float32x4x2_t np_vtrnq_f32(float32x4_t a, float32x4_t b)
{
	return vtrnq_f32(a, b);
}

poly8x16x2_t np_vtrnq_p8(poly8x16_t a, poly8x16_t b)
{
	return vtrnq_p8(a, b);
}

poly16x8x2_t np_vtrnq_p16(poly16x8_t a, poly16x8_t b)
{
	return vtrnq_p16(a, b);
}

int8x16x2_t np_vzipq_s8(int8x16_t a, int8x16_t b)
{
	return vzipq_s8(a, b);
}

int16x8x2_t np_vzipq_s16(int16x8_t a, int16x8_t b)
{
	return vzipq_s16(a, b);
}

int32x4x2_t np_vzipq_s32(int32x4_t a, int32x4_t b)
{
	return vzipq_s32(a, b);
}

uint8x16x2_t np_vzipq_u8(uint8x16_t a, uint8x16_t b)
{
	return vzipq_u8(a, b);
}

uint16x8x2_t np_vzipq_u16(uint16x8_t a, uint16x8_t b)
{
	return vzipq_u16(a, b);
}

uint32x4x2_t np_vzipq_u32(uint32x4_t a, uint32x4_t b)
{
	return vzipq_u32(a, b);
}

float32x4x2_t np_vzipq_f32(float32x4_t a, float32x4_t b)
{
	return vzipq_f32(a, b);
}

poly8x16x2_t np_vzipq_p8(poly8x16_t a, poly8x16_t b)
{
	return vzipq_p8(a, b);
}

poly16x8x2_t np_vzipq_p16(poly16x8_t a, poly16x8_t b)
{
	return vzipq_p16(a, b);
}

int8x16x2_t np_vuzpq_s8(int8x16_t a, int8x16_t b)
{
	return vuzpq_s8(a, b);
}

int16x8x2_t np_vuzpq_s16(int16x8_t a, int16x8_t b)
{
	return vuzpq_s16(a, b);
}

int32x4x2_t np_vuzpq_s32(int32x4_t a, int32x4_t b)
{
	return vuzpq_s32(a, b);
}

uint8x16x2_t np_vuzpq_u8(uint8x16_t a, uint8x16_t b)
{
	return vuzpq_u8(a, b);
}

uint16x8x2_t np_vuzpq_u16(uint16x8_t a, uint16x8_t b)
{
	return vuzpq_u16(a, b);
}

uint32x4x2_t np_vuzpq_u32(uint32x4_t a, uint32x4_t b)
{
	return vuzpq_u32(a, b);
}

float32x4x2_t np_vuzpq_f32(float32x4_t a, float32x4_t b)
{
	return vuzpq_f32(a, b);
}

poly8x16x2_t np_vuzpq_p8(poly8x16_t a, poly8x16_t b)
{
	return vuzpq_p8(a, b);
}

poly16x8x2_t np_vuzpq_p16(poly16x8_t a, poly16x8_t b)
{
	return vuzpq_p16(a, b);
}

#else

int npCanUseSIMD()
{
	return 0;
}

#endif
