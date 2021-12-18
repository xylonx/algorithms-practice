#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // less than 3 number
        vector<vector<int>> res;
        if (nums.size() < 3) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i, k = nums.size() - 1;
            while (++j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                while (nums[k] > -nums[i] - nums[j] && j < k) --k;

                if (j == k) break;

                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }

        return res;
    }
};

// @lc code=end

int main(int argc, char** argv) {
    Solution    s;
    vector<int> x  = {1, 2, -2, -1};
    auto        vv = s.threeSum(x);
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}