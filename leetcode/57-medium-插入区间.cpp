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
        if (newInterval.size() == 0) return intervals;

        vector<vector<int>> res;
        int i = 0, left = newInterval[0], right = newInterval[1];
        while (i < intervals.size() && intervals[i][1] < left) res.push_back(intervals[i++]);

        while (i < intervals.size() && intervals[i][0] <= right) {
            left  = min(left, intervals[i][0]);
            right = max(right, intervals[i][1]);
            i++;
        }

        res.push_back({left, right});

        while (i < intervals.size()) res.push_back(intervals[i++]);

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