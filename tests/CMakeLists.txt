set(This Tests)

add_executable(${This} prepare_text_tests.cpp encoder_tests.cpp decoder_tests.cpp algorithm_tests.cpp)

target_link_libraries(${This} PUBLIC gtest_main shifter_lib)

add_test(
    NAME TextPreparation
    COMMAND ${This}
)
add_test(
    NAME EncoderTests
    COMMAND ${This}
)
add_test(
    NAME DecoderTests
    COMMAND ${This}
)
add_test(
    NAME AlgorithmTests
    COMMAND ${This}
)
