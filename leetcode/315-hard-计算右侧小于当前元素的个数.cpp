#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {}
};
// @lc code=end

int main(int argc, char**) {
    vector<int> nums = {0, 2, 1};
    Solution s;
    auto res = s.countSmaller(nums);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}