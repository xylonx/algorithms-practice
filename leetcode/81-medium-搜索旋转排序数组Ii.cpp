#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (auto& i : nums) {
            if (i == target) return true;
        }
        return false;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<int> nums = {1, 0, 1, 1, 1};
    Solution s;
}