#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == val)
                nums[left] = nums[--right];
            else
                left++;
        }
        return left;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    Solution    s;
    vector<int> v = {0, 1, 2, 2, 3, 0, 4, 2};

    int num = s.removeElement(v, 2);
    for (int i = 0; i < num; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}