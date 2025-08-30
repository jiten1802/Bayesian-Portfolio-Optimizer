cmake_minimum_required(VERSION 3.10)
project(BayesianPortfolioOptimizer)

set(CMAKE_CXX_STANDARD 17)

# Include Eigen headers
include_directories(external/eigen)

# Include QuadProg++
include_directories(external/QuadProd++)


# Source files
file(GLOB SOURCES "src/*.cpp")

# Build with QuadProg++.cc
add_executable(optimizer ${SOURCES} external/QuadProd++/QuadProg++.cc)
