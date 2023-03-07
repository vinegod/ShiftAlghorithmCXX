#include <iostream>
#include <string>

#include "cli_parser.hpp"
#include "shifter.hpp"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        CLI::print_usage();
        return 0;
    }

    auto parser = CLI::Parser(argc, argv);
    switch (parser.get_flag()) {
    case CLI::arguments_e::None: {
        CLI::print_usage();
        return 1;
    }
    case CLI::arguments_e::Encrypt: {
        Encoder<std::string> encoder(parser.get_key());
        auto encoded = encoder(parser.get_word());
        std::cout << encoded << std::endl;
        return 0;
    }

    case CLI::arguments_e::Decrypt: {
        Decoder<std::string> decoder{parser.get_key()};
        auto decoded = decoder(parser.get_word());
        std::cout << decoded << std::endl;
        return 0;
    }
    }

    return 0;
}