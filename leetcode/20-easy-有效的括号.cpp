#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;

        stack<char> cs;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{': cs.push(s[i]); break;

                case ')':
                    if (cs.empty() || cs.top() != '(') return false;
                    cs.pop();
                    break;

                case ']':
                    if (cs.empty() || cs.top() != '[') return false;
                    cs.pop();
                    break;

                case '}':
                    if (cs.empty() || cs.top() != '{') return false;
                    cs.pop();
                    break;
            }
        }

        return cs.empty();
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    string   str;
    while (cin >> str) {
        cout << s.isValid(str) << endl;
    }
}