
#include <cstdint>
#include <vector>

#include "shifter.hpp"
#include "gtest/gtest.h"

std::vector<std::uint8_t> string_to_vec(std::string str) { return {str.begin(), str.end()}; }

TEST(TextPreparation, tolower_simple) {
    {
        std::string original_str{"AAA"};
        auto prepared_string = prepare_text(string_to_vec(original_str));
        auto expected_string = string_to_vec("aaa");
        EXPECT_EQ(prepared_string, expected_string);
    }
    {
        std::string original_str{"ABCDEFG"};
        auto prepared_string = prepare_text(string_to_vec(original_str));
        auto expected_string = string_to_vec("abcdefg");
        EXPECT_EQ(prepared_string, expected_string);
    }
    {
        std::string original_str{};
        auto prepared_string = prepare_text(string_to_vec(original_str));
        auto expected_string = string_to_vec({""});
        EXPECT_EQ(prepared_string, expected_string);
    }
}

TEST(TextPreparation, remove_symbols) {
    {
        std::string original_str{"!/'$"};
        auto prepared_string = prepare_text(string_to_vec(original_str));
        auto expected_string{string_to_vec("")};
        EXPECT_EQ(prepared_string, expected_string);
    }
    {
        std::string original_str{"!/'$----!abcdefg"};
        auto prepared_string = prepare_text(string_to_vec(original_str));
        auto expected_string = string_to_vec("abcdefg");
        EXPECT_EQ(prepared_string, expected_string);
    }
    {
        std::string original_str{"a!b$c_d-e+f="};
        auto prepared_string = prepare_text(string_to_vec(original_str));
        auto expected_string = string_to_vec("abcdef");
        EXPECT_EQ(prepared_string, expected_string);
    }
}

TEST(TextPreparation, tolower_with_symbols) {
    {
        std::string original_str{"A!B/C'D$E=F"};
        auto prepared_string = prepare_text(string_to_vec(original_str));
        auto expected_string{string_to_vec("abcdef")};
        EXPECT_EQ(prepared_string, expected_string);
    }
    {
        std::string original_str{"ABCD!/'$----!EFG"};
        auto prepared_string = prepare_text(string_to_vec(original_str));
        auto expected_string = string_to_vec("abcdefg");
        EXPECT_EQ(prepared_string, expected_string);
    }
}