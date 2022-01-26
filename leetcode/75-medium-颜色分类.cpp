#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int bucket[3] = {0};
        for (int i = 0; i < nums.size(); ++i) {
            ++bucket[nums[i]];
        }

        int cur = 0;
        while (bucket[0]--) nums[cur++] = 0;
        while (bucket[1]--) nums[cur++] = 1;
        while (bucket[2]--) nums[cur++] = 2;
    }
};
// @lc code=end
