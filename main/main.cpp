#include "shifter.hpp"
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

int main() {
    auto key_text = std::string("aabaa");
    Encoder<std::string> encoder(key_text);

    auto encoded = encoder(std::string("I'm a Panda Bear"));
    std::cout << encoded << std::endl;
    Decoder<decltype(encoder)::type> decoder(encoder);

    std::cout << decoder(encoded) << std::endl;

}