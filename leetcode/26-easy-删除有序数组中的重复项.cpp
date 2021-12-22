#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();

        int tail = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[tail]) {
                tail++;
                if (tail != i) nums[tail] = nums[i];
            }
        }
        return tail + 1;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    Solution    s;
    vector<int> nums{1};
    cout << s.removeDuplicates(nums) << endl;

    return 0;
}