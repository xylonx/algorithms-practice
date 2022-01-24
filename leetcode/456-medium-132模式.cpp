#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int second = INT_MIN;
        stack<int> s;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] >= second) {
                while (!s.empty() && nums[i] > nums[s.top()]) {
                    second = nums[s.top()];
                    s.pop();
                }
                s.push(i);
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
