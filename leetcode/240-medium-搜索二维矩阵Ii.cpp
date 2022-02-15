#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, right = n - 1;
        while (top < m && right >= 0) {
            if (matrix[top][right] == target) {
                return true;
            } else if (matrix[top][right] < target) {
                ++top;
            } else {
                --right;
            }
        }
        return false;
    }
};
// @lc code=end
