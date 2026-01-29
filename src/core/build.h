
#pragma once

// cmake options
#if !defined(BUILD_DEBUG) && !defined(BUILD_RELEASE)
    #define BUILD_DEBUG
#endif

// debug options
#if defined(BUILD_DEBUG)
    #define ENABLE_ASSERTS 1
    #define ENABLE_LOGGING 1
#else
    #define ENABLE_ASSERTS 0
    #define ENABLE_LOGGING 1
#endif

// testing options
#if defined(ENABLE_TESTS)
    #define TESTING_FRAMEWORK_UNITTESTC 1
#endif
