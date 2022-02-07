#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid      = (l + r) / 2;
            int leftval  = (mid == 0 ? INT_MIN : nums[mid - 1]);
            int rightval = (mid == nums.size() - 1 ? INT_MIN : nums[mid + 1]);

            // because each values in nums are different. can use below trick
            if (nums[mid] >= leftval && nums[mid] >= rightval) return mid;

            if (rightval >= leftval) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return 0;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<int> nums = {1, 2};
    Solution s;
    cout << s.findPeakElement(nums);
}