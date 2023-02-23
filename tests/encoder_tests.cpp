#include "shifter.hpp"
#include "gtest/gtest.h"
#include <string>

/**
 * @brief If we will pass to constructor only "a" it will shift all letters to 1 position
 */
TEST(EncoderTests, one_shift) {
    {
        auto encoder = Encoder<std::string>("b");
        std::string string_to_encode = "a";
        std::string expected_string = "b";
        EXPECT_EQ(encoder(string_to_encode), expected_string);
    }
    {
        auto encoder = Encoder<std::string>("bbbbbb");
        std::string string_to_encode = "a";
        std::string expected_string = "b";
        EXPECT_EQ(encoder(string_to_encode), expected_string);
    }
    {
        auto encoder = Encoder<std::string>("b");
        std::string string_to_encode = "aaaaaa";
        std::string expected_string = "bbbbbb";
        EXPECT_EQ(encoder(string_to_encode), expected_string);
    }
    {
        auto encoder = Encoder<std::string>("b");
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
        auto encoder = Encoder<std::string>("d");
        std::string string_to_encode = "a";
        std::string expected_string = "d";
        EXPECT_EQ(encoder(string_to_encode), expected_string);
    }
    {
        auto encoder = Encoder<std::string>("dddddd");
        std::string string_to_encode = "a";
        std::string expected_string = "d";
        EXPECT_EQ(encoder(string_to_encode), expected_string);
    }
    {
        auto encoder = Encoder<std::string>("d");
        std::string string_to_encode = "aaaaaa";
        std::string expected_string = "dddddd";
        EXPECT_EQ(encoder(string_to_encode), expected_string);
    }
    {
        auto encoder = Encoder<std::string>("d");
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
        auto encoder = Encoder<std::string>("lion");
        std::string string_to_encode = "thequickbrownfoxjumpsoverthelazydog";
        std::string expected_string = "epsdfqqxmzcjynckucacdwjrcbvrwinlowu";
        EXPECT_EQ(encoder(string_to_encode), expected_string);
    }
}