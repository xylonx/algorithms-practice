#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            dp[i & 1][0] = dp[(i - 1) & 1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                dp[i & 1][j] = min(dp[(i - 1) & 1][j], dp[(i - 1) & 1][j - 1]) + triangle[i][j];
            }
            dp[i & 1][i] = dp[(i - 1) & 1][i - 1] + triangle[i][i];
        }

        int res = INT_MAX;
        for (int j = 0; j < n; ++j) {
            res = min(res, dp[(n - 1) & 1][j]);
        }

        return res;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<vector<int>> t = {
        {2 },
        {    3,  4},
        {    6, 5,  7},
        { 4,  1,    8, 3}
    };
    Solution s;
    cout << s.minimumTotal(t);
}