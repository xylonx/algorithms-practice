#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        res.clear();
        path.clear();
        backtracking(n, k, 0);
        return res;
    }

    void backtracking(int n, int k, int cur) {
        if (path.size() == k) {
            res.emplace_back(path);
            return;
        }

        if (path.size() + n - cur < k) return;

        backtracking(n, k, cur + 1);
        path.emplace_back(cur + 1);
        backtracking(n, k, cur + 1);
        path.pop_back();
    }
};
// @lc code=end

int main(int argc, char** argv) {
    int n, k;
    Solution s;
    while (cin >> n >> k) {
        auto res = s.combine(n, k);
        for (auto i : res) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
}