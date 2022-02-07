#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> tmp(nums.begin(), nums.begin() + k);
        for (int i = nums.size() - 1; i >= k; --i) {
            nums[(i + k) % nums.size()] = nums[i];
        }
        for (int i = 0; i < k; ++i) {
            nums[(i + k) % nums.size()] = tmp[i];
        }
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Solution s;
    s.rotate(nums, 3);
}
