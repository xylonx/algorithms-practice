#include <iostream>
#include <map>
#include <string>

using namespace std;

/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
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

class Solution {
public:
    int strStr(string haystack, string needle) {
        SundaySearch s;
        return s.sundaySearch(haystack, needle);
    }
};

// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string   haystack, needle;
    while (cin >> haystack >> needle) {
        int i = s.strStr(haystack, needle);
        cout << i << endl;
        if (i > 0) cout << haystack.substr(i, needle.size()) << endl;
    }
}