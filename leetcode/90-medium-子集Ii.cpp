#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        backtrace(nums, res, path, 0);
        return res;
    }

    void backtrace(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int pos) {
        res.push_back(path);
        for (int i = pos; i < nums.size(); ++i) {
            if (i > pos && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            backtrace(nums, res, path, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 2};
    Solution s;
    auto res = s.subsetsWithDup(nums);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}