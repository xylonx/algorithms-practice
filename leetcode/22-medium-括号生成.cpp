#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    // (())(())

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string         tmp = "";
        dfs(res, tmp, n, 0, 0);
        return res;
    }

private:
    void dfs(vector<string> &res, string &tmp, int n, int left, int right) {
        if (tmp.size() == 2 * n) {
            res.push_back(tmp);
            return;
        }

        if (left < n) {
            tmp.push_back('(');
            dfs(res, tmp, n, left + 1, right);
            tmp.pop_back();
        }

        if (right < left) {
            tmp.push_back(')');
            dfs(res, tmp, n, left, right + 1);
            tmp.pop_back();
        }
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    int      n;
    while (cin >> n) {
        auto res = s.generateParenthesis(n);
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << res.size() << endl;
    }
}