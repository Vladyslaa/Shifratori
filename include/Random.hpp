#pragma once

#include <random>
#include <exception>
#include <string>

namespace random {
    inline unsigned char gen_char() noexcept {
        static thread_local std::mt19937 engine(std::random_device{}());
        static std::uniform_int_distribution<unsigned char> dist(0, 255);
        return dist(engine);
    }

    inline std::string gen_key(size_t size) {
        std::string key;
        key.reserve(size);

        for (size_t i = 0; i < size; ++i) {
            key.push_back(gen_char());
        }

        return key;
    }
}