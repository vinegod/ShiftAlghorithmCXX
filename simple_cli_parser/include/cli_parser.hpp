#pragma once

#include <string>
#include <vector>

namespace CLI {

enum class arguments_e { None, Encrypt, Decrypt };

class Parser {
  public:
    using arg_vector = std::vector<std::string>;
    explicit Parser(int argc, char *argv[]);

    arguments_e get_flag() const;

    const std::string &get_word() const;
    const std::string &get_key() const;

  private:
    void parse_flags();

    arg_vector arguments;
    std::string word;
    std::string key;
    bool decrypt_flag = 0;
    bool encrypt_flag = 0;
};

void print_usage();
}; // namespace CLI