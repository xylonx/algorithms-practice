#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int res = nums[0], vot = 1;
        for (int i = 1; i < nums.size(); ++i) {
            res == nums[i] ? ++vot : --vot;
            if (vot == 0) res = nums[i], vot = 1;
        }

        return res;
    }
};
// @lc code=end
