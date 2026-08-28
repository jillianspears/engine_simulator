cmake_minimum_required(VERSION 3.14)
project(engine_simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Your library ---
add_library(truth_model
    truth_model/numerical_integrators/src/numerical_integrators.cpp
)
target_include_directories(truth_model PUBLIC
    truth_model/numerical_integrators/include
)

# --- GoogleTest via FetchContent ---
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: force shared runtime to match gtest defaults
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# --- Your test executable ---
add_executable(run_tests
    truth_model/numerical_integrators/test/test_numerical_integrators.cpp
)
target_link_libraries(run_tests
    truth_model
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(run_tests)