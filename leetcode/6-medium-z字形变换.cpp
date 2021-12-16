#include <iostream>
#include <string>

using namespace std;

/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;

    string result = "";
    for (int row = 0; row < numRows; row++) {
      for (int i = row; i < s.size(); i += 2 * (numRows - 1)) {
        result += s.at(i);
        int gap = 2 * (numRows - row - 1);
        if (0 < gap && gap < 2 * (numRows - 1) && (i + gap) < s.size()) {
          result += s.at(i + gap);
        }
      }
    }
    return result;
  }
};
// @lc code=end

int main(int argc, char *argv[]) {
  Solution s;

  string res = s.convert(string("PAYPALISHIRING"), 4);
  cout << res << endl;
  cout << "PINALSIGYAHRPI" << endl;
  return 0;
}