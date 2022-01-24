#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums, target, true), binarySearch(nums, target, false)};
    }

    int binarySearch(vector<int>& nums, int target, bool lower) {
        int l = 0, r = nums.size() - 1, res = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) res = mid;

            if (lower ? target <= nums[mid] : target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};
// @lc code=end

int main(int argc, char** argv) {}