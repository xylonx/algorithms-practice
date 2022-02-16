/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

bool isBadVersion(int version);

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (mid == 0) return isBadVersion(0);
            if (isBadVersion(mid) && !isBadVersion(mid - 1)) return mid;
            if (isBadVersion(mid)) right = mid - 1;
            if (!isBadVersion(mid)) left = mid + 1;
        }
        return left;
    }
};
// @lc code=end
