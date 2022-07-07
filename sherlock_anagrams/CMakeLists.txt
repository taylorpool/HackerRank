cmake_minimum_required(VERSION 3.10)

project(SherlockAnagrams)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(sherlock src/sherlock.cpp)
target_include_directories(sherlock PUBLIC include)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_main test/test_main.cpp)
target_link_libraries(test_main gtest_main sherlock)

include(GoogleTest)
gtest_discover_tests(test_main)