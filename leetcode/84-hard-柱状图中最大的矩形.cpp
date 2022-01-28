#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        vector<int> left(heights.size(), 0), right(heights.size());

        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[i] <= heights[s.top()]) {
                s.pop();
            }
            left[i] = (s.empty() ? -1 : s.top());

            s.push(i);
        }

        s = stack<int>();
        for (int i = heights.size() - 1; i >= 0; --i) {
            while (!s.empty() && heights[i] <= heights[s.top()]) {
                s.pop();
            }
            right[i] = (s.empty() ? heights.size() : s.top());
            s.push(i);
        }

        int maxarea = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (((right[i] - left[i] - 1) * heights[i]) > maxarea) {
                maxarea = (right[i] - left[i] - 1) * heights[i];
            }
        }
        return maxarea;
    }
};
// @lc code=end
int main(int argc, char** argv) {
    vector<int> nums = {4, 2, 0, 3, 2, 4, 3, 4};
    Solution s;
    cout << s.largestRectangleArea(nums);
}