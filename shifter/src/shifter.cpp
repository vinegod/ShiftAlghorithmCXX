#include "shifter.hpp"

std::vector<std::uint8_t> prepare_text(std::vector<std::uint8_t> &&text) {
    std::vector<std::uint8_t> result;

    for (const auto &original_char : text) {
        if (original_char >= 'a' && original_char <= 'z') {
            result.push_back(original_char);
        } else if (original_char >= 'A' && original_char <= 'Z') {
            result.push_back(original_char + 'a' - 'A');
        }
    }

    return result;
}