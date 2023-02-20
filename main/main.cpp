#include "shifter.hpp"
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

void print(std::string str) {
    std::cout << str << std::endl;
    for (const auto &c : std::vector<uint8_t>(str.begin(), str.end())) {
        std::cout << (uint32_t)c << ' ';
    }
    std::cout << std::endl;
}

int main() {
    auto key_text = std::string("zzzzzz");
    Encoder<std::string> encoder(key_text);

    auto encoded = encoder(std::string("The quick brown fox jumps over the lazy dog"));
    print(encoded);
    Decoder<decltype(encoder)::type> decoder(encoder);
    print(decoder(encoded));
}