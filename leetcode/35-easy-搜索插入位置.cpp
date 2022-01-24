#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() <= 0) return -1;

        if (target < *nums.begin()) return 0;
        if (target > nums[nums.size() - 1]) return nums.size();

        auto pos = binarySearch(nums.begin(), nums.end(), target);
        return pos - nums.begin();
    }

private:
    vector<int>::iterator binarySearch(vector<int>::iterator start, vector<int>::iterator end, int target) {
        if (end - start == 1) {
            if (*start == target) return start;
            if (*end == target) return end;
            return start + 1;
        }

        vector<int>::iterator mid = start + (end - start) / 2;
        if (*mid == target) {
            return mid;
        } else if (*mid < target) {
            return binarySearch(mid, end, target);
        } else {
            return binarySearch(start, mid, target);
        }
    }
};
// @lc code=end

int main(int argc, char** argv) {
    Solution s;

    map<int, vector<int>> cases = {
        {5, {1, 3, 5, 6}},
        {2, {1, 3, 5, 6}},
        {7, {1, 3, 5, 6}},
        {0, {1, 3, 5, 6}},
        {0, {1}         }
    };

    for (auto v : cases) {
        cout << s.searchInsert(v.second, v.first) << endl;
    }

    return 0;
}