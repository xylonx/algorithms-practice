#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m.insert({nums[i], 1});
        }
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int step = nums[i];
            while (m.find(step) != m.end()) {
                step += m[step];
            }
            m[nums[i]] = step - nums[i];
            if (step - nums[i] > res) {
                res = step - nums[i];
            }
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char**) {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution s;
    cout << s.longestConsecutive(nums);
}