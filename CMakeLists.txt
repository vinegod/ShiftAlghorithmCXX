cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME shifter)

project($(PROJECT_NAME) VERSION 0.1)

set(CMAKE_CXX_STANDATD 17)
set(CMAKE_CXX_FALGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(shifter)
add_subdirectory(simple_cli_parser)

add_subdirectory(main)

enable_testing()
add_subdirectory(googletest)
add_subdirectory(tests)