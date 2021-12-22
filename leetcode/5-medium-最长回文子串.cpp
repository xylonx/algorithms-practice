#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 0) {
            return "";
        }

        const char  delimiter = '$';
        vector<int> rs(s.size() * 2 + 1, 0);

        string str = "";
        for (int i = 0; i < s.size(); ++i) {
            str.push_back(delimiter);
            str.push_back(s[i]);
        }
        str.push_back(delimiter);

        int maxRadiusIdx = 0, maxRightCenter = 0;

        for (int i = 0; i < str.size(); ++i) {
            int right  = maxRightCenter + rs[maxRightCenter];
            int radius = 0;
            if (right > i) {
                radius = rs[2 * maxRightCenter - i];
                if (i + radius > right) {
                    radius = right - i;
                }
            }

            for (; i - radius >= 0 && i + radius < str.size(); ++radius) {
                if (str[i - radius] != str[i + radius]) {
                    break;
                }

                rs[i] = radius;
                if (radius > rs[maxRadiusIdx]) {
                    maxRadiusIdx = i;
                }

                if (i + radius > maxRightCenter + rs[maxRightCenter]) {
                    maxRightCenter = i;
                }
            }
        }

        int left  = (maxRadiusIdx - rs[maxRadiusIdx] + 1) / 2;
        int right = (maxRadiusIdx + rs[maxRadiusIdx] - 1) / 2;
        return s.substr(left, right - left + 1);
    }
};
// @lc code=end

int main(int argc, char** argv) {
    Solution s;
    string   str;

    while (cin >> str) {
        cout << s.longestPalindrome(str) << endl;
    }

    return 0;
}