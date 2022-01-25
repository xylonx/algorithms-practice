#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    // result is C_{m+n}^{n}
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    cout << s.uniquePaths(3, 7);
}