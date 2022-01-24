#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> res(row * col);
        int pos = 0, left = 0, right = col - 1, top = 0, bottom = row - 1;
        while (pos < res.size()) {
            for (int i = left; i <= right && pos < res.size(); ++i) res[pos++] = matrix[top][i];
            top++;
            for (int i = top; i <= bottom && pos < res.size(); ++i) res[pos++] = matrix[i][right];
            right--;
            for (int i = right; i >= left && pos < res.size(); --i) res[pos++] = matrix[bottom][i];
            bottom--;
            for (int i = bottom; i >= top && pos < res.size(); --i) res[pos++] = matrix[i][left];
            left++;
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<vector<int>> matrix = {
        {1, 2,  3,  4 },
        {5, 6,  7,  8 },
        {9, 10, 11, 12}
  // {1, 2, 3},
  // {4, 5, 6},
  // {7, 8, 9}
    };
    Solution s;
    auto res = s.spiralOrder(matrix);
    for (auto i : res) {
        cout << i << " ";
    }
}