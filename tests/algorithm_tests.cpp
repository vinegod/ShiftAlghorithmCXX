#include "shifter.hpp"
#include "gtest/gtest.h"
#include <string>

TEST(AlgorithmTests, simple_shift) {
    {
        Encoder<std::string> encoder("b");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "thequickbrownfoxjumpsoverthelazydog";
        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), original_string);
    }
    {
        Encoder<std::string> encoder("b");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "thequickbrownfoxjumpsoverthelazydog";
        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), original_string);
    }
    {
        Encoder<std::string> encoder("d");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "thequickbrownfoxjumpsoverthelazydog";
        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), original_string);
    }
    {
        Encoder<std::string> encoder("b");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "thequickbrownfoxjumpsoverthelazydog";
        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), original_string);
    }
}

TEST(AlgorithmTests, text_preparation_with_shift) {
    {
        Encoder<std::string> encoder("b");
        Decoder<decltype(encoder)::type> decoder(encoder);

        const std::string original_string = "The quick brown fox jumps over the lazy dog.";
        const std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";

        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), expected_string);
    }
    {
        Encoder<std::string> encoder("b");
        Decoder<decltype(encoder)::type> decoder(encoder);

        const std::string original_string = "The quick brown fox jumps over the lazy dog.";
        const std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";

        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), expected_string);
    }
    {
        Encoder<std::string> encoder("d");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "The quick brown fox jumps over the lazy dog.";
        const std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";

        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), expected_string);
    }
    {
        Encoder<std::string> encoder("b");
        Decoder<decltype(encoder)::type> decoder(encoder);

        const std::string original_string = "The quick brown fox jumps over the lazy dog.";
        const std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";

        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), expected_string);
    }
}

TEST(AlgorithmTests, Vigenere) {
    {
        Encoder<std::string> encoder("badas");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "thequickbrownfoxjumpsoverthelazydog";
        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), original_string);
    }
    {
        Encoder<std::string> encoder("key");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "thequickbrownfoxjumpsoverthelazydog";
        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), original_string);
    }
    {
        Encoder<std::string> encoder("LION");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "thequickbrownfoxjumpsoverthelazydog";
        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), original_string);
    }
    {
        Encoder<std::string> encoder("thequickbrownfoxjumpsoverthelazydog");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "thequickbrownfoxjumpsoverthelazydog";
        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), original_string);
    }
}

TEST(AlgorithmTests, text_preparation_with_vigenere) {
    {
        Encoder<std::string> encoder("badas");
        Decoder<decltype(encoder)::type> decoder(encoder);

        const std::string original_string = "The quick brown fox jumps over the lazy dog.";
        const std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";

        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), expected_string);
    }
    {
        Encoder<std::string> encoder("LION");
        Decoder<decltype(encoder)::type> decoder(encoder);

        const std::string original_string = "The quick brown fox jumps over the lazy dog.";
        const std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";

        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), expected_string);
    }
    {
        Encoder<std::string> encoder("KEY");
        Decoder<decltype(encoder)::type> decoder(encoder);
        const std::string original_string = "The quick brown fox jumps over the lazy dog.";
        const std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";

        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), expected_string);
    }
    {
        Encoder<std::string> encoder("thequickbrownfoxjumpsoverthelazydog");
        Decoder<decltype(encoder)::type> decoder(encoder);

        const std::string original_string = "The quick brown fox jumps over the lazy dog.";
        const std::string expected_string = "thequickbrownfoxjumpsoverthelazydog";

        auto encoded = encoder(original_string);
        EXPECT_EQ(decoder(encoded), expected_string);
    }
}