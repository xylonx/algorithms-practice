#include <iostream>
#include <map>
#include <string>

using namespace std;

/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        short dig[] = {
            1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000,
        };
        string rom[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

        string res = "";
        char   mod = 0;
        for (int i = 12; i >= 0; --i) {
            if ((mod = num / dig[i]) != 0) {
                while (mod--) res += rom[i];
                num %= dig[i];
            }
        }

        return res;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    Solution s;
    int      x;
    while (cin >> x) cout << s.intToRoman(x) << endl;
    return 0;
}
