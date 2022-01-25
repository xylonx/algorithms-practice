#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<int> dp[2];
        dp[0].resize(n, 0), dp[1].resize(n, 0);
        dp[0][0] = (obstacleGrid[0][0] == 1 ? 0 : 1);

        for (int i = 0; i < m; ++i) {
            for (int j = (i == 0 ? 1 : 0); j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i & 1][j] = 0;
                } else {
                    dp[i & 1][j] = (i == 0 ? 0 : dp[(i - 1) & 1][j]) + (j == 0 ? 0 : dp[i & 1][j - 1]);
                }
            }
        }

        return dp[(m - 1) & 1][n - 1];
    }
};
// @lc code=end

int main(int argc, char**) {
    vector<vector<int>> o = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    Solution s;
    cout << s.uniquePathsWithObstacles(o) << endl;
}