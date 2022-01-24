#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, currentSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            if (currentSum > maxSum) maxSum = currentSum;

            if (currentSum < 0) currentSum = 0;
        }
        return maxSum;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    Solution s;

    vector<vector<int> > cases = {
        {-2, 1,  -3, 4, -1, 2, 1, -5, 4},
        {1},
        {5,  4, -1,  7,   8    },
    };

    for (auto v : cases) {
        cout << s.maxSubArray(v) << endl;
    }
}