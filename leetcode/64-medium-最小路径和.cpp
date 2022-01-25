#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[2][n];
        dp[0][0] = grid[0][0];

        for (int i = 0; i < m; ++i) {
            for (int j = (i == 0 ? 1 : 0); j < n; ++j) {
                dp[i & 1][j] =
                    min((i == 0 ? INT_MAX : dp[(i - 1) & 1][j]), (j == 0 ? INT_MAX : dp[i & 1][j - 1])) + grid[i][j];
            }
        }

        return dp[(m - 1) & 1][n - 1];
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    Solution s;
    cout << s.minPathSum(grid);
}