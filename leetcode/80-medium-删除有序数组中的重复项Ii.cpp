#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();

        int pos = 0, dup = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                dup++;
                if (dup == 1) pos++;
            } else {
                dup = 0, pos++;
            }

            if (i != pos) {
                nums[pos] = nums[i];
            }
        }
        return pos + 1;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    Solution s;
    auto res = s.removeDuplicates(nums);
    for (int i = 0; i < res; ++i) {
        cout << nums[i] << " ";
    }
}