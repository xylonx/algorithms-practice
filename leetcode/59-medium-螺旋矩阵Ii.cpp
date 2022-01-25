#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n);
        for (auto& i : res) i.resize(n);

        int top = 0, left = 0, bottom = n - 1, right = n - 1, cnt = 0;
        while (cnt < n * n) {
            for (int k = left; k <= right && cnt < n * n; ++k) res[top][k] = ++cnt;
            top++;

            for (int k = top; k <= bottom && cnt < n * n; ++k) res[k][right] = ++cnt;
            right--;

            for (int k = right; k >= left && cnt < n * n; --k) res[bottom][k] = ++cnt;
            bottom--;

            for (int k = bottom; k >= top && cnt < n * n; --k) res[k][left] = ++cnt;
            left++;
        }

        return res;
    }
};
// @lc code=end
