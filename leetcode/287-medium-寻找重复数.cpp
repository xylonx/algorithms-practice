#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int next = nums[next], prev = nums[nums[prev]];
        while (next != prev) {
            next = nums[next];
            prev = nums[nums[prev]];
        }
        prev = 0;
        while (prev != next) {
            prev = nums[prev];
            next = nums[next];
        }
        return prev;
    }
};
// @lc code=end
