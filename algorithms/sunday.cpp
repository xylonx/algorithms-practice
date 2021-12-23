#include <iostream>
#include <map>
#include <string>

class SundaySearch {
public:
    int sundaySearch(const std::string &str, const std::string &pattern) {
        this->shift.clear();

        if (pattern.empty()) return 0;
        if (pattern.size() > str.size()) return -1;

        for (int i = 0; i < str.size();) {
            int j = 0;
            while (j < pattern.size() && i + j < str.size() && str[i + j] == pattern[j]) ++j;

            if (j == pattern.size()) return i;

            if (i + pattern.size() >= str.size()) return -1;

            i += this->getShift(pattern, str[i + pattern.size()]);
        }

        return -1;
    }

private:
    std::map<char, int> shift;

    int getShift(const std::string &pattern, const char &ch) {
        auto res = shift.find(ch);
        if (res != shift.end()) {
            return res->second;
        }

        for (int i = pattern.size() - 1; i >= 0; --i) {
            if (pattern[i] == ch) {
                shift.insert({ch, pattern.size() - i});
                return pattern.size() - i;
            }
        }

        shift.insert({ch, pattern.size() + 1});
        return pattern.size() + 1;
    }
};

int main(int argc, char *argv[]) {
    std::string  str, pattern;
    SundaySearch search;

    while (std::cin >> str >> pattern) {
        int pos = search.sundaySearch(str, pattern);
        std::cout << str.substr(pos) << std::endl;
    }

    return 0;
}
