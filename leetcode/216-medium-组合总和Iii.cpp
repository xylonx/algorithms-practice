#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, 1, 9, k, n);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& path, int cur, int n, int k, int target) {
        if (path.size() > k || path.size() + (n - cur + 1) < k) return;

        if (path.size() == k) {
            int sum = 0;
            for (auto& i : path) sum += i;
            if (sum == target) res.push_back(path);
            return;
        }

        dfs(res, path, cur + 1, n, k, target);
        path.push_back(cur);
        dfs(res, path, cur + 1, n, k, target);
        path.pop_back();
    }
};
// @lc code=end
