#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0, current = 0, minIdx = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            height[i] > height[j] ? minIdx = j-- : minIdx = i++;
            current = (j - i + 1) * height[minIdx];
            if (current > result) {
                result = current;
            }
        }
        return result;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    Solution    s;
    vector<int> vec = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s.maxArea(vec) << endl;
    return 0;
}