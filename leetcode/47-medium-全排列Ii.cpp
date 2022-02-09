#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<bool> vis;
    vector<int> path;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vis.resize(nums.size(), false);
        backtracing(nums);
        return res;
    }

    void backtracing(vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) continue;

            vis[i] = true;
            path.emplace_back(nums[i]);
            backtracing(nums);
            path.pop_back();
            vis[i] = false;
        }
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<int> nums = {1, 1, 1, 2};
    Solution s;
    auto res = s.permuteUnique(nums);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
