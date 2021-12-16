#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x %10 == 0 && x!= 0)){
            return false;
        }

        int rev = 0;
        while(x > rev) {
            rev = rev*10 + x % 10;
            x /= 10;
        }

        return x== rev || x == rev/10;
    }
};
// @lc code=end

int main(int argc, char *argv[]) {
    Solution s;
    int      x;
    while (cin >> x) {
        cout << s.isPalindrome(x) << endl;
    }
    return 0;
}