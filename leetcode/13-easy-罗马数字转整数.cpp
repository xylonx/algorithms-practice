#include <iostream>
#include <string>

using namespace std;

/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int   val       = 0;
        short value[26] = {}, max = 1;

        value['I' - 'A'] = 1;
        value['V' - 'A'] = 5;
        value['X' - 'A'] = 10;
        value['L' - 'A'] = 50;
        value['C' - 'A'] = 100;
        value['D' - 'A'] = 500;
        value['M' - 'A'] = 1000;

        for (int i = s.size() - 1; i >= 0; --i) {
            if (value[s[i] - 'A'] >= max) {
                val += value[s[i] - 'A'];
                max = value[s[i] - 'A'];
            } else {
                val -= value[s[i] - 'A'];
            }
        }
        return val;
    }
};
// @lc code=end
int main(int argc, char **argv) {
    string   rom;
    Solution s;
    while (cin >> rom) {
        cout << s.romanToInt(rom) << endl;
    }
    return 0;
}