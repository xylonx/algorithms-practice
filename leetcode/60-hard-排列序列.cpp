#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
public:
    string res = "", tmp = "";
    vector<bool> vis;
    int cnt = 0;

    string getPermutation(int n, int k) {
        vis.resize(n, false);
        backtracking(n, k);
        return res;
    }

    void backtracking(int n, int k) {
        if (cnt >= k) return;

        if (tmp.size() == n) {
            ++cnt;
            res = tmp;
            return;
        }

        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                vis[i] = true;
                tmp.push_back('0' + i);
                backtracking(n, k);
                tmp.pop_back();
                vis[i] = false;
            }
        }
    }
};
// @lc code=end

int main(int argc, char** argv) {
    Solution s;
    cout << s.getPermutation(3, 3);
}