#pragma once

#include "Random.hpp"
#include "Colors.hpp"

#include <sstream>
#include <iomanip>
#include <regex>
#include <algorithm>
#include <cctype>

namespace engine {
    struct endl_t {
        friend std::ostream& operator<<(std::ostream& os, const endl_t&) {
            return os << color::none << '\n' << std::flush;
        }
    };
    inline constexpr endl_t endl{};

    std::string to_lower(std::string str);
    std::string to_hex(const std::string &str);
    std::string to_byte(const std::vector<std::string> &hex);

    /**
     * Splits the input string into tokens using whitespace and quotation marks as delimiters.
     * @return Vector of individual segments extracted from the original string.
     */
    std::vector<std::string> split(const std::string &str);

    /**
     * Applies XOR encryption to the input string and returns the result in hexadecimal form.
     * @return A pair containing {hex-encoded ciphertext, encryption key}.
     */
    std::pair<std::string, std::string> encrypt(const std::string &str);

    /**
     * Decrypts a hexadecimal-encoded message using the provided key.
     * @param args Pair containing the {encrypted text, decryption key}.
     */
    std::string decrypt(const std::pair<std::string, std::string> &args);
}