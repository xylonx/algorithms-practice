#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row0 = false, col0 = false;

        for (int i = 0; i < m; ++i) {
            if (!matrix[i][0]) {
                col0 = true;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!matrix[0][i]) {
                row0 = true;
                break;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!matrix[i][j]) matrix[0][j] = matrix[i][0] = 0;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
            }
        }

        if (row0) {
            for (int j = 0; j < n; ++j) matrix[0][j] = 0;
        }
        if (col0) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }

        return;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    Solution s;
    s.setZeroes(matrix);
    for (auto i : matrix) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}