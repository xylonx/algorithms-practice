#include <iostream>
#include <string>

using namespace std;

/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
  int myAtoi(string s) {
    const int min = 0x80000000, max = 0x7fffffff;
    bool pos = true;
    int result = 0, delta = 0;
    auto head = s.begin();
    // trim leading whitespace
    while (head != s.end() && isspace(*head++)) {
    }
    head--;

    // get symbal
    if (head != s.end()) {
      switch (*head) {
      case '-':
        pos = false;
        head++;
        break;
      case '+':
        head++;
        break;
      }
    }

    for (auto i = head; i != s.end() && isdigit(*i); ++i) {
      delta = pos ? (*i - '0') : -(*i - '0');

      if (!pos && result < (min - delta) / 10) {
        return min;
      }
      if (pos && result > (max - delta) / 10) {
        return max;
      }

      result = result * 10 + delta;
    }

    return result;
  }
};
// @lc code=end

int main(int argc, char *argv[]) {
  Solution s;
  string str;
  while (cin >> str) {
    cout << s.myAtoi(str) << endl;
  }
  return 0;
}