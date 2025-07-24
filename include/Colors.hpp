#pragma once

#include <string>

namespace color {
    constexpr std::string_view  none = "\033[0m";

    constexpr std::string_view black = "\033[30m";
    constexpr std::string_view red = "\033[31m";
    constexpr std::string_view green = "\033[32m";
    constexpr std::string_view yellow = "\033[33m";
    constexpr std::string_view blue = "\033[34m";
    constexpr std::string_view purple = "\033[35m";
    constexpr std::string_view gray = "\033[38;5;245m";

    constexpr std::string_view fat = "\033[1m";
    constexpr std::string_view nfat = "\033[22m";
    constexpr std::string_view weak = "\033[2m";
    constexpr std::string_view nweak = "\033[22m";
    constexpr std::string_view curse = "\033[3m";
    constexpr std::string_view ncurse = "\033[23m";
    constexpr std::string_view underlined = "\033[4m";
    constexpr std::string_view nunterlined = "\033[24m";
    constexpr std::string_view flash = "\033[5m";
    constexpr std::string_view nflash = "\033[25m";
}