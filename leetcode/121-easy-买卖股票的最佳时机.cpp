#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxval[prices.size()];
        maxval[prices.size() - 1] = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; --i) {
            maxval[i] = max(prices[i], maxval[i + 1]);
        }
        int res = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (maxval[i + 1] - prices[i] > res) {
                res = maxval[i + 1] - prices[i];
            }
        }
        return res;
    }
};
// @lc code=end
