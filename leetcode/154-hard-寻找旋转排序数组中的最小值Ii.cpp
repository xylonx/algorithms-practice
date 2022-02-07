#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int minval = nums[0];
        for (auto& i : nums) {
            if (i < minval) minval = i;
        }
        return minval;
    }
};
// @lc code=end
