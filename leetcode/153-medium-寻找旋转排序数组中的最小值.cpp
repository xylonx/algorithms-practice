#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (nums[l] > nums[r]) {
            int mid = (l + r) / 2;
            if (r - l == 1) {
                return nums[r];
            }
            if (nums[mid] > nums[l] && nums[mid] > nums[r]) l = mid;
            if (nums[mid] < nums[l] && nums[mid] < nums[r]) r = mid;
        }
        return nums[0];
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<int> nums = {3, 4, 5, 1, 2};
    Solution s;
    cout << s.findMin(nums);
}
