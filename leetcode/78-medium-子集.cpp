#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(nums, res, path, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int> path, int start) {
        res.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, res, path, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end
