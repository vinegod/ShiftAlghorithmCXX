#include "shifter.hpp"
#include "gtest/gtest.h"
#include <string>

TEST(AlgorithmTests, simple_shift) {
    {
        auto encoder = Encoder<std::string>("b");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "thequickbrownfoxjumpsoverthelazydog";
        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), original_string);
    }
    {
        auto encoder = Encoder<std::string>("b");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "thequickbrownfoxjumpsoverthelazydog";
        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), original_string);
    }
    {
        auto encoder = Encoder<std::string>("d");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "thequickbrownfoxjumpsoverthelazydog";
        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), original_string);
    }
    {
        auto encoder = Encoder<std::string>("b");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "thequickbrownfoxjumpsoverthelazydog";
        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), original_string);
    }
}

TEST(AlgorithmTests, text_preparation_with_shift) {
    {
        auto encoder = Encoder<std::string>("b");
        Decoder<decltype(encoder)::type> decoder(encoder);

        const std::string original_string = "The quick brown fox jumps over the lazy dog.";
        const std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";

        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), expected_string);
    }
    {
        auto encoder = Encoder<std::string>("b");
        Decoder<decltype(encoder)::type> decoder(encoder);

        const std::string original_string = "The quick brown fox jumps over the lazy dog.";
        const std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";

        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), expected_string);
    }
    {
        auto encoder = Encoder<std::string>("d");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "The quick brown fox jumps over the lazy dog.";
        const std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";

        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), expected_string);
    }
    {
        auto encoder = Encoder<std::string>("b");
        Decoder<decltype(encoder)::type> decoder(encoder);

        const std::string original_string = "The quick brown fox jumps over the lazy dog.";
        const std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";

        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), expected_string);
    }
}

TEST(AlgorithmTests, Vigenere) {
    {
        auto encoder = Encoder<std::string>("badas");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "thequickbrownfoxjumpsoverthelazydog";
        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), original_string);
    }
    {
        auto encoder = Encoder<std::string>("key");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "thequickbrownfoxjumpsoverthelazydog";
        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), original_string);
    }
    {
        auto encoder = Encoder<std::string>("LION");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "thequickbrownfoxjumpsoverthelazydog";
        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), original_string);
    }
    {
        auto encoder = Encoder<std::string>("thequickbrownfoxjumpsoverthelazydog");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "thequickbrownfoxjumpsoverthelazydog";
        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), original_string);
    }
}

TEST(AlgorithmTests, text_preparation_with_vigenere) {
    {
        auto encoder = Encoder<std::string>("badas");
        Decoder<decltype(encoder)::type> decoder(encoder);

        const std::string original_string = "The quick brown fox jumps over the lazy dog.";
        const std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";

        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), expected_string);
    }
    {
        auto encoder = Encoder<std::string>("LION");
        Decoder<decltype(encoder)::type> decoder(encoder);

        const std::string original_string = "The quick brown fox jumps over the lazy dog.";
        const std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";

        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), expected_string);
    }
    {
        auto encoder = Encoder<std::string>("KEY");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "The quick brown fox jumps over the lazy dog.";
        const std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";

        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), expected_string);
    }
    {
        auto encoder = Encoder<std::string>("thequickbrownfoxjumpsoverthelazydog");
        Decoder<decltype(encoder)::type> decoder(encoder);

        const std::string original_string = "The quick brown fox jumps over the lazy dog.";
        const std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";

        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), expected_string);
    }
}