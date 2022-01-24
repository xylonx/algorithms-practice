#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1]) break;

                int realIdx   = nums[i] - 1;
                nums[i]       = nums[realIdx];
                nums[realIdx] = realIdx + 1;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};
// @lc code=end

int main(int argc, char**) {
    vector<int> nums = {INT_MAX};
    Solution s;
    cout << s.firstMissingPositive(nums) << endl;
}
