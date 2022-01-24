#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals;

        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end(), compare);
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= right) {
                right = max(intervals[i][1], right);
            } else {
                res.push_back({left, right});
                left = intervals[i][0], right = intervals[i][1];
            }
        }
        res.push_back({left, right});

        return res;
    }

    static bool compare(const vector<int>& l, const vector<int>& r) { return l[0] < r[0]; };
};
// @lc code=end

int main(int argc, char** argv) {
    vector<vector<int>> intervals = {
        {1, 4},
        {2, 3}
    };
    Solution s;

    auto res = s.merge(intervals);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}