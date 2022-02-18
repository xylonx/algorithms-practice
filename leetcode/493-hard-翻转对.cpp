#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution {
private:
    int cnt = 0;

    void merge(vector<int>& nums, int left, int right, int mid) {
        int i = left, j = mid + 1, k = 0;
        // count reverse pair
        while (i <= mid && j <= right) {
            long long nj = nums[j];
            while (i <= mid && nums[i] <= nj * 2) ++i;
            cnt += (mid - i + 1);
            ++j;
        }

        // merge
        i = left, j = mid + 1, k = 0;
        vector<int> tmp(right - left + 1, 0);
        while (i <= mid && j <= right) {
            if (nums[i] > nums[j]) {
                tmp[k++] = nums[j++];
            } else {
                tmp[k++] = nums[i++];
            }
        }

        while (i <= mid) tmp[k++] = nums[i++];
        while (j <= right) tmp[k++] = nums[j++];

        for (int l = 0; l < tmp.size(); ++l) nums[l + left] = tmp[l];
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = left + ((right - left) >> 1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, right, mid);
    }

public:
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return cnt;
    }
};
// @lc code=end

int main(int argc, char* argv[]) {
    vector<int> nums = {1, 3, 2, 3, 1};
    Solution s;
    cout << s.reversePairs(nums);
}