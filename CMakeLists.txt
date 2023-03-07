cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME shifter)

project($(PROJECT_NAME) VERSION 0.1)

set(CMAKE_CXX_STANDATD 17)
set(CMAKE_CXX_FALGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_CACHEFILE_DIR ${PROJECT_SOURCE_DIR}/build)

add_subdirectory(libraries)

add_subdirectory(main)

set(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)
set(CMAKE_CXX_CLANG_TIDY  clang-tidy;
    -header-filter=libraries/; 
    -checks='-*,cppcoreguidelines-*,google-*,modernize-*,readability-*,-modernize-use-trailing-return-type,bugprone-*,clang-analyzer-*;
    #-warnings-as-errors=*;
    -p=./build;
)


enable_testing()
add_subdirectory(googletest)
add_subdirectory(tests)