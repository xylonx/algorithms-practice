#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> vis(nums.size(), false);
        backtracing(res, path, vis, nums);
        return res;
    }

    void backtracing(vector<vector<int>>& res, vector<int>& path, vector<bool>& vis, vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!vis[i]) {
                vis[i] = true;
                path.push_back(nums[i]);
                backtracing(res, path, vis, nums);
                path.pop_back();
                vis[i] = false;
            }
        }
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3};
    Solution s;
    auto res = s.permute(nums);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}