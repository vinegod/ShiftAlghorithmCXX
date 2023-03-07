#include "shifter.hpp"
#include "gtest/gtest.h"
#include <string>

/**
 * @brief If we will pass to constructor only "a" it will shift all letters to 1 position
 */
TEST(EncoderTests, one_shift) {
    {
        Encoder<std::string> encoder("b");
        std::string string_to_encode = "a";
        std::string expected_string = "b";
        EXPECT_EQ(encoder(string_to_encode), expected_string);
    }
    {
        Encoder<std::string> encoder("bbbbbb");
        std::string string_to_encode = "a";
        std::string expected_string = "b";
        EXPECT_EQ(encoder(string_to_encode), expected_string);
    }
    {
        Encoder<std::string> encoder("b");
        std::string string_to_encode = "aaaaaa";
        std::string expected_string = "bbbbbb";
        EXPECT_EQ(encoder(string_to_encode), expected_string);
    }
    {
        Encoder<std::string> encoder("b");
        std::string string_to_encode = "abcdefg";
        std::string expected_string = "bcdefgh";
        EXPECT_EQ(encoder(string_to_encode), expected_string);
    }
}

/**
 * @brief If we will pass to constructor only "d" it will perform as Caesar algorithm
 */
TEST(EncoderTests, caesar_shift) {
    {
        Encoder<std::string> encoder("d");
        std::string string_to_encode = "a";
        std::string expected_string = "d";
        EXPECT_EQ(encoder(string_to_encode), expected_string);
    }
    {
        Encoder<std::string> encoder("dddddd");
        std::string string_to_encode = "a";
        std::string expected_string = "d";
        EXPECT_EQ(encoder(string_to_encode), expected_string);
    }
    {
        Encoder<std::string> encoder("d");
        std::string string_to_encode = "aaaaaa";
        std::string expected_string = "dddddd";
        EXPECT_EQ(encoder(string_to_encode), expected_string);
    }
    {
        Encoder<std::string> encoder("d");
        std::string string_to_encode = "abcdefg";
        std::string expected_string = "defghij";
        EXPECT_EQ(encoder(string_to_encode), expected_string);
    }
}

/**
 * @brief Another combination of symbols will call Vigenere algorithm
 */
TEST(EncoderTests, Vigenere) {
    {
        Encoder<std::string> encoder("lion");
        std::string string_to_encode = "thequickbrownfoxjumpsoverthelazydog";
        std::string expected_string = "epsdfqqxmzcjynckucacdwjrcbvrwinlowu";
        EXPECT_EQ(encoder(string_to_encode), expected_string);
    }
}