#include <iostream>

#include "cli_parser.hpp"

namespace CLI {

Parser::Parser(int argc, char *argv[]) {
    arguments = arg_vector(argv, argv + argc);
    parse_flags();
}

arguments_e Parser::get_flag() const {
    if (encrypt_flag) {
        return arguments_e::Encrypt;
    } else if (decrypt_flag) {
        return arguments_e::Decrypt;
    } else {
        return arguments_e::None;
    }
}

const std::string &Parser::get_word() const { return word; }
const std::string &Parser::get_key() const { return key; }

void Parser::parse_flags() {
    bool save_next = false;
    bool save_key = false;

    for (auto it = arguments.begin(); it != arguments.end(); it++) {
        if (it->find("--encrypt") != std::string::npos) {
            encrypt_flag = true;
            word = *(it + 1);
        } else if (it->find("--decrypt") != std::string::npos) {
            decrypt_flag = true;
            word = *(it + 1);
        } else if (it->find("--key") != std::string::npos) {
            key = *(it + 1);
        }
    }
}

void print_usage() { std::cout << "Usage: shifter [options] <word> [--key] <key>\n"; }

} // namespace CLI