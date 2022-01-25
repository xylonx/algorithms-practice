#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cnt = 1;
        for (int i = digits.size() - 1; i >= 0 && cnt > 0; --i) {
            digits[i] += cnt;
            cnt = digits[i] / 10;
            digits[i] -= cnt * 10;
        }
        if (cnt) digits.insert(digits.begin(), cnt);
        return digits;
    }
};
// @lc code=end

