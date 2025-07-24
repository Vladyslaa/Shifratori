#include "..\include\Engine.hpp"

namespace engine {
    std::string to_lower(std::string str) {
        std::transform(
            str.begin(), str.end(), str.begin(), 
            [](unsigned char c){ return std::tolower(c); }
        );
        return str;
    }

    std::string to_hex(const std::string& str) {
        std::stringstream ss;
        ss << std::hex << std::uppercase;

        for (const unsigned char c : str) {
            ss << std::setw(2) << std::setfill('0') << static_cast<int>(c);
            ss << ' ';
        }

        std::string res = ss.str();
        res.pop_back();

        return res;
    }

    std::string to_byte(const std::vector<std::string>& hex) {
        std::string res;
        res.reserve(hex.size()); 

        for (const auto& h : hex) {
            if (h.length() != 2) throw std::invalid_argument("Each hex pair must be exactly two characters long.");       

            unsigned int byte;
            std::stringstream ss;
            ss << std::hex << h;
            ss >> byte;
            res.push_back(static_cast<unsigned char>(byte));
        }

        return res;
    }

    std::vector<std::string> split(const std::string &str){
        std::vector<std::string> res;

        std::regex re(R"(\"([^\"]*)\"|'([^']*)'|([^ \t]+))");
        std::sregex_iterator it(str.begin(), str.end(), re);
        std::sregex_iterator end;

        for (; it != end; ++it){
            std::smatch match = *it;

            if (match[1].matched) {
                res.push_back(match[1].str());
            }
            else if (match[2].matched) {
                res.push_back(match[2].str());
            }
            else if (match[3].matched) {
                res.push_back(match[3].str());
            }
        }

        return res;
    }

    std::pair<std::string, std::string> encrypt(const std::string& str) {
        std::string key = random::gen_key(str.size());
        std::string coded;
        coded.reserve(str.size());

        auto it = str.begin();
        auto keyIt = key.begin();

        while (it != str.end()){
            char c = *it ^ *keyIt;
            coded.push_back(c);
            ++it, ++keyIt;
        }

        return {coded, key};
    }

    std::string decrypt(const std::pair<std::string, std::string> &args) {
        std::string s = to_byte(split(args.first));
        std::string key = to_byte(split(args.second));
        std::string res;
        res.reserve(s.size());

        auto it = s.begin();
        auto keyIt = key.begin();

        while (it != s.end()){
            char c = *it ^ *keyIt;
            res.push_back(c);
            ++it, ++keyIt;
        }

        return res;
    }
}