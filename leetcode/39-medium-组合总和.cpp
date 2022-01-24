#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int> path, int target, int start) {
        if (target < 0) return;
        if (target == 0) {
            ans.push_back(path);
            return;
        };

        for (int i = start; i < nums.size() && nums[i] <= target; i++) {
            path.push_back(nums[i]);
            dfs(nums, ans, path, target - nums[i], i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        dfs(candidates, ans, path, target, 0);
        return ans;
    }
};
// @lc code=end

int main(int argc, char**) {
    vector<int> nums = {2, 3, 6, 7};
    Solution s;
    auto res = s.combinationSum(nums, 7);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}