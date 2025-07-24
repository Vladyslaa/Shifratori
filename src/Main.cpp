#include "..\include\Engine.hpp"

#include <vector>
#include <functional>
#include <unordered_map>
#include <iostream>
#include <cstdlib>

void Commands(const std::vector<std::string>&) noexcept {
    using namespace color;

    std::cout << yellow << fat << "Available commands:" << engine::endl;
    
    std::cout << blue << "- " << green << "commands" 
              << none << " - " << gray << "show available commands" << engine::endl;
    
    std::cout << blue << "- " << green << "encrypt " 
              << purple << "<text_to_encrypt>" 
              << none << " - " << gray << "encrypt text using XOR method" << engine::endl;
    
    std::cout << blue << "- " << green << "decrypt " 
              << purple << "<encrypted_text> " << purple << "<key>" 
              << none << " - " << gray << "decrypt text with encryption key" << engine::endl;
    
    std::cout << blue << "- " << green << "hex " 
              << purple << "<text>" 
              << none << " - " << gray << "convert text to hexadecimal" << engine::endl;
    
    std::cout << blue << "- " << green << "str " 
              << purple << "<hexadecimal_bytes>" 
              << none << " - " << gray << "convert hexadecimal to text (e.g. str \"48 65 6C 6C 6F\")" << engine::endl;
    
    std::cout << blue << "- " << red << "exit" 
              << none << " - " << gray << "close application" << engine::endl;
}

void Exit(const std::vector<std::string>&) noexcept {
    std::exit(0);
}

void Encrypt(const std::vector<std::string>& args) {
    if  (args.size() != 1) throw std::invalid_argument("Usage: encrypt <text_to_encrypt>");

    auto res = engine::encrypt(args[0]);

    std::cout << color::blue << "Coded text: <" << color::curse << engine::to_hex(res.first) << color::ncurse << ">" << engine::endl;
    std::cout << color::yellow << "Key: <" << color::fat << engine::to_hex(res.second) << ">" << engine::endl;
}

void Decrypt(const std::vector<std::string>& args) {
    if  (args.size() != 2) throw std::invalid_argument("Usage: decrypt <encrypted_text> <key>");

    std::string res = engine::decrypt({args[0],args[1]});

    std::cout << color::green << "Decoded text: " << color::purple << "<" << color::curse << res << color::ncurse << ">" << engine::endl;
}

void Hex(const std::vector<std::string>& args) {
    if  (args.size() != 1) throw std::invalid_argument("Usage: hex <text>");

    std::cout << color::fat << color::purple << engine::to_hex(std::string(args[0])) << engine::endl;
}

void Str (const std::vector<std::string>& args) {
    if  (args.size() != 1) throw std::invalid_argument("Usage: str <hexadecimal_bytes>");

    std::cout << color::fat << color::green << engine::to_byte(engine::split(args[0])) << engine::endl;
}

static std::unordered_map<std::string, std::function<void(const std::vector<std::string>&)>> commands = {
    {"commands", Commands},
    {"encrypt", Encrypt},
    {"decrypt", Decrypt},
    {"hex", Hex},
    {"str", Str},
    {"exit", Exit}
};

int main() {
    try {
        std::cout << color::curse << color::green << "Shifratori v1.0"
          << color::ncurse << color::gray  << " | "
          << color::blue  << "HEX format: " << color::yellow << "bytes separated by spaces\n"
          << color::gray  << "Enter " << color::green << "commands" << color::gray  << " to view available commands\n"
          << color::weak  << std::string(40, '-') << engine::endl;

        while (true) {
            std::cout << color::flash << "> " << color::none;
            std::string input;
            if (!std::getline(std::cin, input)) break;

            if (std::all_of(
                input.begin(), input.end(), 
                [](char c){ return std::isspace(static_cast<unsigned char>(c)); }
            )) {
                continue;
            }

            std::vector<std::string> args = engine::split(input);
            std::string command = engine::to_lower(args[0]); 
            args.erase(args.begin());

            auto it = commands.find(command);
            if (it != commands.end()) {
                try {
                    it->second(args);
                }
                catch (const std::invalid_argument& e) {
                    std::cout << color::red << e.what() << "\n" << color::none;
                    continue;
                }
            } else {
                std::cerr << color::red << "Unknown command, write <Commands> for a awaible commands list.\n" << color::none;
                continue;
            }
        }
    } catch (const std::exception &e) {
        std::cout << color::red << e.what() << color::none;
        std::cin.get();
    }
    return 0;
}