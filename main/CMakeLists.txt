add_executable(shifter_bin main.cpp)

target_link_libraries(shifter_bin PRIVATE shifter_lib simple_cli_parser)