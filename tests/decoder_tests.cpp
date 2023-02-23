#include "shifter.hpp"
#include "gtest/gtest.h"
#include <string>

/**
 * @brief If we will pass to constructor only "a" it will shift all letters to 1 position
 */
TEST(DecoderTests, one_shift) {
    {
        auto decoder = Decoder<std::string>("b");
        std::string string_to_decode = "b";
        std::string expected_string = "a";
        EXPECT_EQ(decoder(string_to_decode), expected_string);
    }
    {
        auto decoder = Decoder<std::string>("bbbbbb");
        std::string string_to_decode = "b";
        std::string expected_string = "a";
        EXPECT_EQ(decoder(string_to_decode), expected_string);
    }
    {
        auto decoder = Decoder<std::string>("b");
        std::string string_to_decode = "bbbbbb";
        std::string expected_string = "aaaaaa";
        EXPECT_EQ(decoder(string_to_decode), expected_string);
    }
    {
        auto decoder = Decoder<std::string>("b");
        std::string string_to_decode = "bcdefgh";
        std::string expected_string = "abcdefg";
        EXPECT_EQ(decoder(string_to_decode), expected_string);
    }
}

/**
 * @brief If we will pass to constructor only "c" it will perform as Caesar algorithm
 */
TEST(DecoderTests, caesar_shift) {
    {
        auto decoder = Decoder<std::string>("d");
        std::string string_to_decode = "d";
        std::string expected_string = "a";
        EXPECT_EQ(decoder(string_to_decode), expected_string);
    }
    {
        auto decoder = Decoder<std::string>("dddddd");
        std::string string_to_decode = "d";
        std::string expected_string = "a";
        EXPECT_EQ(decoder(string_to_decode), expected_string);
    }
    {
        auto decoder = Decoder<std::string>("d");
        std::string string_to_decode = "dddddd";
        std::string expected_string = "aaaaaa";
        EXPECT_EQ(decoder(string_to_decode), expected_string);
    }
    {
        auto decoder = Decoder<std::string>("d");
        std::string string_to_decode = "defghij";
        std::string expected_string = "abcdefg";
        EXPECT_EQ(decoder(string_to_decode), expected_string);
    }
}

/**
 * @brief Another combination of symbols will call Vigenere algorithm
 */
TEST(DecoderTests, Vigenere) {
    {
        auto decoder = Decoder<std::string>("lion");
        std::string string_to_decode = "epsdfqqxmzcjynckucacdwjrcbvrwinlowu";
        std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";
        EXPECT_EQ(decoder(string_to_decode), expected_string);
    }
}