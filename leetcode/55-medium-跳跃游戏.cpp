#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > far) return false;
            if (i + nums[i] > far) far = i + nums[i];

            if (far >= nums.size() - 1) return true;
        }
        return true;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<int> nums = {3, 2, 1, 0, 4};
    Solution s;
    cout << s.canJump(nums) << endl;
}