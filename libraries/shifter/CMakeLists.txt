add_library(shifter_lib
    include/shifter.hpp
    src/shifter.cpp                   
)

target_include_directories(shifter_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")