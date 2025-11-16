#pragma once

#ifdef MRBL_PLATFORM_WINDOWS
	#ifdef MRBL_BUILD_DLL
		#define MRBL_API __declspec(dllexport)
	#else
		#define MRBL_API __declspec(dllimport)
	#endif
#else
	#error Mrbl only supports Windows!
#endif

#ifdef MRBL_ENABLE_ASSERTS
	#define MRBL_ASSERT(x, ...) { if(!(x)) { MRBL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define MRBL_CORE_ASSERT(x, ...) { if(!(x)) { MRBL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define MRBL_ASSERT(x, ...)
	#define MRBL_CORE_ASSERT(x, ...)
#endif

// used for the eventCategory definition
#define BIT(x) (1 << x)