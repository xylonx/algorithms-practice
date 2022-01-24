#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) return dividend == INT_MIN ? INT_MAX : -dividend;

        bool neg = (dividend ^ divisor) < 0;
        int  tdd = (dividend > 0 ? -dividend : dividend);
        int  tds = (divisor > 0 ? -divisor : divisor);

        int res = 0, threshold = INT_MIN >> 1;
        while (tdd <= tds) {
            int tmp = tds, times = 1;
            while (tmp >= threshold && tdd <= (tmp + tmp)) {
                tmp += tmp;
                times += times;
            }

            while (tdd <= tmp) {
                tdd -= tmp;
                res += times;
            }
        }

        return neg ? -res : res;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;

    int x, y;
    while (cin >> x >> y) {
        cout << s.divide(x, y) << endl;
    }

    return 0;
}