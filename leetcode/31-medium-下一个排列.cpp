#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;

        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<int> t = {1, 1};
    Solution s;
    s.nextPermutation(t);
    for (auto i : t) {
        cout << i << " ";
    }
    cout << endl;
}
