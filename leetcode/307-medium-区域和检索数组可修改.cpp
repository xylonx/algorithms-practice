#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
class NumArray {
private:
    vector<int> bitree;
    vector<int> nums;

    inline int lowbit(int x) { return x & -x; }
    int getsum(int x) {
        int ans = 0;
        while (x > 0) {
            ans += bitree[x];
            x -= lowbit(x);
        }
        return ans;
    }
    void add(int x, int k) {
        while (x < bitree.size()) bitree[x] += k, x += lowbit(x);
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        bitree.resize(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i) add(i, nums[i - 1]);
    }

    void update(int index, int val) {
        add(index + 1, val - nums[index]);
        nums[index] = val;
    }

    int sumRange(int left, int right) { return getsum(right + 1) - getsum(left); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
