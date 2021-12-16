#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int    idx = 0, over = 0;
        string str;
        while (1) {
            if (idx >= strs[0].size()) {
                return str;
            }
            char c = strs[0][idx];

            for (int i = 0; i < strs.size(); ++i) {
                if (idx >= strs[i].size()) return str;

                if (strs[i][idx] != c) return str;
            }
            idx++;
            str += c;
        }
    }
};
// @lc code=end

int main(int argc, char* argv[]) {
    Solution       s;
    vector<string> vec = {"flower", "flow", "flight"};
    cout << s.longestCommonPrefix(vec) << endl;
    return 0;
}