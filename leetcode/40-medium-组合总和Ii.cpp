#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int> path, int target, int start) {
        if (target < 0) return;
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < nums.size() && nums[i] <= target; i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            dfs(nums, ans, path, target - nums[i], i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(candidates, res, path, target, 0);
        return res;
    }
};
// @lc code=end

int main(int argc, char**) {
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    Solution s;
    auto res = s.combinationSum2(nums, 8);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}