cmake_minimum_required(VERSION 3.10)
project(BayesianPortfolioOptimizer)

set(CMAKE_CXX_STANDARD 17)

# Include Eigen manually (update path if needed)
include_directories("C:\Users\shahj\Desktop\Baysian Portfolio Optimizer/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Include QuadProg++
include_directories(external/QuadProg++)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Build with QuadProg++.cc
add_executable(optimizer ${SOURCES} external/QuadProg++/QuadProg++.cc)
