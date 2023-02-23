set(This Tests)

add_executable(${This} prepare_text_tests.cpp)

target_link_libraries(${This} PUBLIC gtest_main shifter_lib)

add_test(
    NAME TextPreparation
    COMMAND ${This}
)