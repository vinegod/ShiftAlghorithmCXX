#pragma once

#include <algorithm>
#include <cstdint>
#include <string>
#include <type_traits>
#include <vector>

namespace {
template <typename T, typename _ = void> struct is_container : std::false_type {};
template <typename... Ts> struct is_container_helper {};

/**
 * @brief Container that has value true if type T is container from std, otherwise false
 *
 * @tparam T type parameter that will be checked
 */
template <typename T>
struct is_container<
    T, std::conditional_t<false,
                          is_container_helper<typename T::value_type, typename T::size_type, typename T::iterator,
                                              typename T::const_iterator, decltype(std::declval<T>().size()),
                                              decltype(std::declval<T>().begin()), decltype(std::declval<T>().end()),
                                              decltype(std::declval<T>().cbegin()), decltype(std::declval<T>().cend())>,
                          void>> : public std::true_type {};

/**
 * @brief Shifts elemets on different amount of positions due to provided key.
 *
 * @param original_string string that should be shifted.
 * @param key secret key
 * @param shift_mode 1 for encoding, -1 for decoding
 * @return std::string
 */
inline std::string shift_elemets(std::vector<std::uint8_t> original_string, const std::vector<std::uint8_t>& key,
                                 std::int16_t shift_mode) {

    const static std::uint8_t english_alphabet_length = 26;

    for (size_t i = 0; i < original_string.size(); i++) {
        // Reference to char in vector for easy access
        auto &char_to_shift = original_string[i];

        // Vigenere algorithm
        int32_t new_char = char_to_shift - 'a' + shift_mode * (key[i % key.size()] - 'a');
        char_to_shift = 'a' + new_char % english_alphabet_length;

        if (char_to_shift < 'a') {
            char_to_shift += english_alphabet_length;
        }
    }
    return {original_string.begin(), original_string.end()};
}

/**
 * @brief Removes from text special symbols and makes it lower case.
 *
 * @param text string for transformation
 * @return std::vector<std::uint8_t>
 */
inline std::vector<std::uint8_t> prepare_text(std::vector<std::uint8_t> &&text) {
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

} // namespace

// Forward declaration of Decoder struct to use as friend in Encoder struct
template <typename Key, std::enable_if_t<is_container<Key>::value, bool> = true,
          std::enable_if_t<std::is_integral<typename Key::value_type>::value, bool> = true>
struct Decoder;

/**
 * @brief Encoder struct for encoding text with Vigenere or Shift algorithm.
 * Uses templates to be able get every std container as input.
 *
 * @tparam Key type of std container
 */
template <typename Key, std::enable_if_t<is_container<Key>::value, bool> = true,
          std::enable_if_t<std::is_integral<typename Key::value_type>::value, bool> = true>
struct Encoder {
    using type = Key;

    explicit Encoder(Key key) : m_key{prepare_text({key.begin(), key.end()})} {};
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

/**
 * @brief Decoder struct for decoding text with Vigenere or Shift algorithm.
 * Uses templates to be able get every std container as input.
 *
 * @tparam Key type of std container
 */
template <typename Key, std::enable_if_t<is_container<Key>::value, bool>,
          std::enable_if_t<std::is_integral<typename Key::value_type>::value, bool>>
struct Decoder {
    explicit Decoder(Key key) : m_key{prepare_text({key.begin(), key.end()})} {};
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
