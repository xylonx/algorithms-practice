#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < matrix.size() / 2; ++i) {
            for (int j = i; j < matrix.size() - i - 1; ++j) {
                int tmp = matrix[i][j];

                matrix[i][j]                 = matrix[n - j - 1][i];
                matrix[n - j - 1][i]         = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1]         = tmp;
            }
        }
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<vector<int>> matrix = {
        {5,  1,  9,  11},
        {2,  4,  8,  10},
        {13, 3,  6,  7 },
        {15, 14, 12, 16}
    };
    Solution s;
    s.rotate(matrix);

    for (auto i : matrix) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}