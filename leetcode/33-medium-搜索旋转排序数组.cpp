#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;

        int left = 0, right = nums.size() - 1, k = 0;
        while (nums[left] > nums[right]) {
            int mid = left + (right - left) / 2;
            if (right - left == 1) {
                k = right;
                break;
            }
            if (nums[mid] > nums[left] && nums[mid] > nums[right]) left = mid;
            if (nums[mid] < nums[left] && nums[mid] < nums[right]) right = mid;
        }

        int l = k, r = k + nums.size() - 1;
        while (l < r) {
            int mid = (l + (r - l) / 2);
            if (nums[l % nums.size()] == target) return l % nums.size();
            if (nums[r % nums.size()] == target) return r % nums.size();
            if (nums[mid % nums.size()] == target) return mid % nums.size();

            if (target > nums[mid % nums.size()]) l = (mid + 1);
            if (target < nums[mid % nums.size()]) r = (mid - 1);
        }

        return -1;
    }
};
// @lc code=end

int main(int argc, char**) {
    vector<int> nums = {1};
    Solution s;
    cout << s.search(nums, 1);
}