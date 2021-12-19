#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    string         dam[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }

        reverse(digits.begin(), digits.end());
        return dfs(digits);
    }

    vector<string> dfs(string digits) {
        vector<string> strs;
        if (digits.size() == 1) {
            for (int i = 0; i < dam[digits[0] - '2'].size(); ++i) {
                string tmp = {dam[digits[0] - '2'][i]};
                strs.push_back(tmp);
            }
            return strs;
        };

        vector<string> prefixes = dfs(digits.substr(1));
        for (int i = 0; i < prefixes.size(); ++i) {
            for (int j = 0; j < dam[digits[0] - '2'].size(); ++j) {
                strs.push_back(prefixes[i] + dam[digits[0] - '2'][j]);
            }
        }

        return strs;
    }
};
// @lc code=end
int main(int argc, char** argv) {
    Solution s;
    string   str;
    while (cin >> str) {
        vector<string> res = s.letterCombinations(str);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}
