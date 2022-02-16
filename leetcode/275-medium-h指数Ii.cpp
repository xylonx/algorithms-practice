#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (citations[mid] == citations.size() - mid) return citations[mid];
            if (citations[mid] > citations.size() - mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return citations.size() - left;
    }
};
// @lc code=end
