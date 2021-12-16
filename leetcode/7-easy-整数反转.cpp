#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
  int reverse(int x) {
    const int min = 0x80000000, max = 0x7fffffff;
    int result = 0;
    while (x != 0) {
      if (result < min / 10 || result > max / 10) {
        return 0;
      }
      result = result * 10 + x % 10;
      x /= 10;
    }
    return result;
  }
};
// @lc code=end

int main(int argc, char *argv[]) {
  int input;
  Solution s;
  while (cin >> input) {
    cout << s.reverse(input) << endl;
  }
  return 0;
}

// 1534236469
// -2147483648