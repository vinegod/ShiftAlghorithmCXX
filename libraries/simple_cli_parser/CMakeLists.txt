add_library(simple_cli_parser
    include/cli_parser.hpp
    src/cli_parser.cpp                   
)

target_include_directories(simple_cli_parser PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")