#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, sum = 0, res = INT_MAX;
        while (r < nums.size()) {
            sum += nums[r];
            while (l <= r && sum >= target) {
                if (r - l + 1 < res) res = r - l + 1;
                sum -= nums[l++];
            }
            ++r;
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<int> nums = {1, 4, 4};
    Solution s;
    s.minSubArrayLen(4, nums);
}