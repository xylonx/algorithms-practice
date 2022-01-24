#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) return {newInterval};
        vector<vector<int>> res;
        int i;
        for (i = 0; i < intervals.size() && intervals[i][1] < newInterval[0]; ++i) {
            res.push_back(intervals[i]);
        }

        int left = intervals[i][0], right = max(intervals[i][1], newInterval[1]);

        while (i < intervals.size() && intervals[i][0] <= right) ++i;

        res.push_back({left, max(right, intervals[i - 1][1])});

        res.insert(res.end(), intervals.begin() + i, intervals.end());

        return res;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<vector<int>> intervals = {
  // {1,  2 },
  // {3,  5 },
  // {6,  7 },
  // {8,  10},
  // {12, 16}
        {1, 5}
    };
    vector<int> n = {6, 8};
    Solution s;
    auto res = s.insert(intervals, n);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}