#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        long long lln = n;
        return n >= 0 ? quickPow(x, lln) : 1.0 / quickPow(x, -lln);
    }

    double quickPow(double x, long long n) {
        if (n == 0) return 1;
        if (n == 1) return x;

        double tmp = myPow(x, n / 2);
        return n & 1 ? tmp * tmp * x : tmp * tmp;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    double x;
    int n;
    Solution s;
    while (cin >> x >> n) {
        cout << s.myPow(x, n) << endl;
    }
}