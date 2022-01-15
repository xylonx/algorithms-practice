#include <iostream>
#include <vector>

class KMPSubStringMatcher {
private:
    std::vector<int> calculate_pi(const std::string &pattern) {
        std::vector<int> pi(pattern.size());
        for (int i = 1; i < pi.size(); ++i) {
            int j = pi[i - 1];
            while (j > 0 && pattern[i] != pattern[j]) j = pi[j - 1];
            if (pattern[i] == pattern[j]) j++;
            pi[i] = j;
        }

        return pi;
    }

public:
    std::vector<int> match(const std::string &str, const std::string &pattern) {
        std::vector<int> pos;
        if (pattern.size() < 1) return pos;

        auto pi = calculate_pi(pattern);
        for (int i = 0, j = 0; i < str.size(); ++i) {
            if (j > 0 && str[i] != pattern[j]) j = pi[j - 1];
            if (str[i] == pattern[j]) j++;

            if (j == pattern.size()) {
                pos.push_back(i - j + 1);
                j = pi[j];
            }
        }

        return pos;
    }
};

int main(int argc, char **argv) {
    KMPSubStringMatcher matcher;
    std::string str("abababa"), pattern("");
    auto pos = matcher.match(str, pattern);
    for (auto p : pos) {
        std::cout << str.substr(p, pattern.size()) << std::endl;
    }
}