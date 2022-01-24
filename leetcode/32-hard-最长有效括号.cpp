#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    /*
        dp[i]: 以i结尾的最长子串长度
     */
    int longestValidParentheses(string s) {
        int         res = 0;
        vector<int> dp(s.size(), 0);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i > 2 ? dp[i - 2] : 0) + 2;
                } else if (s[i - 1] == ')') {
                    if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 > 0 ? dp[i - dp[i - 1] - 2] : 0);
                    }
                }
            }

            if (dp[i] > res) res = dp[i];
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string   str;
    while (cin >> str) {
        cout << s.longestValidParentheses(str) << endl;
    }

    return 0;
}