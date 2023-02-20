#pragma once

#include <cstddef>
#include <cstdint>
#include <iterator>
#include <type_traits>

#include <string>
#include <vector>

#include <algorithm>
#include <iostream>
namespace {
template <typename T, typename _ = void> struct is_container : std::false_type {};

template <typename... Ts> struct is_container_helper {};

template <typename T>
struct is_container<
    T, std::conditional_t<false,
                          is_container_helper<typename T::value_type, typename T::size_type, typename T::iterator,
                                              typename T::const_iterator, decltype(std::declval<T>().size()),
                                              decltype(std::declval<T>().begin()), decltype(std::declval<T>().end()),
                                              decltype(std::declval<T>().cbegin()), decltype(std::declval<T>().cend())>,
                          void>> : public std::true_type {};

inline std::string shift_elemets(std::vector<std::uint8_t> original_string, std::vector<std::uint8_t> key,
                                 std::int32_t shift_mode) {
    for (size_t i = 0; i < original_string.size(); i++) {
        auto &c = original_string[i];
        int32_t new_c = c - 'a' + shift_mode * (key[i % key.size()] - 'a');
        c = 97 + new_c % 'a';
        if (c < 97) {
            c += 26;
        }
    }
    return {original_string.begin(), original_string.end()};
}

inline std::vector<std::uint8_t> prepare_text(std::vector<std::uint8_t> &&text) {
    std::vector<std::uint8_t> result;

    for (const auto &c : text) {
        if (c >= 'a' && c <= 'z') {
            result.push_back(c);
        } else if (c >= 'A' && c <= 'Z') {
            result.push_back(c + 32);
        }
    }

    return result;
}

} // namespace
template <typename Key, std::enable_if_t<is_container<Key>::value, bool> = true,
          std::enable_if_t<std::is_integral<typename Key::value_type>::value, bool> = true>
struct Decoder;

template <typename Key, std::enable_if_t<is_container<Key>::value, bool> = true,
          std::enable_if_t<std::is_integral<typename Key::value_type>::value, bool> = true>
struct Encoder {
    using type = Key;

    explicit Encoder(Key key)
        : m_key{prepare_text({key.begin(), key.end()})} {
              // Key preparation
          };
    explicit Encoder(Decoder<Key> &&encoder) : m_key{encoder.m_key} {};
    /**
     * @brief Operator that encodes original text with given key
     *
     * @tparam Text template parameter that accepts vector<integral_type> and string.
     * @param original_string string that should be encoded.
     * @return std::string encoded string.
     */
    template <typename Text, std::enable_if_t<is_container<Key>::value, bool> = true,
              std::enable_if_t<std::is_integral<typename Key::value_type>::value, bool> = true>
    std::string operator()(Text original_string) const {
        const std::int16_t shift_mode = 1;
        if constexpr (std::is_same<Text, std::vector<uint8_t>>::value) {
            return shift_elemets(prepare_text(std::forward(original_string)), m_key, shift_mode);
        } else {
            return shift_elemets(prepare_text({original_string.begin(), original_string.end()}), m_key, shift_mode);
        }
    }

    friend struct Decoder<Key>;

  private:
    const std::vector<std::uint8_t> m_key;
};

template <typename Key, std::enable_if_t<is_container<Key>::value, bool>,
          std::enable_if_t<std::is_integral<typename Key::value_type>::value, bool>>
struct Decoder {
    explicit Decoder(Key key)
        : m_key{prepare_text({key.begin(), key.end()})} {
              // Key preparation
          };
    explicit Decoder(const Encoder<Key> &encoder) : m_key{encoder.m_key} {};

    /**
     * @brief Operator that decodes original text with given key
     *
     * @tparam Text template parameter that accepts vector<integral_type> and string.
     * @param original_string string that should be decoded.
     * @return std::string encoded string.
     */
    template <typename Text, std::enable_if_t<is_container<Key>::value, bool> = true,
              std::enable_if_t<std::is_integral<typename Key::value_type>::value, bool> = true>
    std::string operator()(Text original_string) const {
        const std::int16_t shift_mode = -1;
        if constexpr (std::is_same<Text, std::vector<uint8_t>>::value) {
            return shift_elemets(std::forward(original_string), m_key, shift_mode);
        } else {
            return shift_elemets({original_string.begin(), original_string.end()}, m_key, shift_mode);
        }
    }

    friend struct Encoder<Key>;

  private:
    const std::vector<std::uint8_t> m_key;
};
