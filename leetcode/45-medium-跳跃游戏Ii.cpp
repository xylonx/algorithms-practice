#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    // f[x] start for x, min steps
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        vector<int> f(nums.size(), 0);
        f[nums.size() - 1] = 0;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums.size() - 1 - i <= nums[i]) {
                f[i] = 1;
            } else {
                int min = INT_MAX - 1;
                for (int j = 1; j < nums.size() && j <= nums[i]; ++j) {
                    if (f[i + j] < min) min = f[i + j];
                }
                f[i] = min + 1;
            }
        }
        return f[0];
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<int> nums = {2, 3, 0, 1, 4};
    Solution s;
    cout << s.jump(nums) << endl;
    return 0;
}