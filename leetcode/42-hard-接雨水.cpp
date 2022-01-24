#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> s;
        for (int i = 0; i < height.size(); ++i) {
            while (!s.empty() && height[s.top()] < height[i]) {
                int bottom = s.top();
                s.pop();
                if (s.empty()) continue;

                ans += (i - s.top() - 1) * (min(height[s.top()], height[i]) - height[bottom]);
            }
            s.push(i);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char**) {
    vector<int> nums = {4, 2, 0, 3, 2, 5};
    Solution s;
    cout << s.trap(nums) << endl;
}
