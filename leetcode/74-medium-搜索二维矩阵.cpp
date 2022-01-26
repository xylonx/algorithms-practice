#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            int col = mid % n, row = (mid - col) / n;
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<vector<int>> matrix = {// {1,  3,  5,  7 },
                                  // {10, 11, 16, 20},
                                  // {23, 30, 34, 60}
                                  // {1,  3,  5,  7 },
                                  // {10, 11, 16, 20},
                                  // {23, 30, 34, 60}
                                  {1},
                                  {3}};
    Solution s;
    cout << s.searchMatrix(matrix, 3) << endl;
}