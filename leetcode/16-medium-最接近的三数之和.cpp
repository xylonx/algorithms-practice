#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;

        sort(nums.begin(), nums.end());
        int current = 0, res = 0, minDelta = INT_MAX, delta = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }

                if (k < nums.size() - 1 && nums[k] == nums[k + 1]) {
                    k--;
                    continue;
                }

                current = nums[i] + nums[j] + nums[k];
                delta   = abs(current - target);

                if (current > target) {
                    --k;
                } else if (current < target) {
                    ++j;
                } else {
                    return current;
                }

                if (delta < minDelta) {
                    minDelta = delta;
                    res      = current;
                }
            }
        }

        return res;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<int> v = {-1, 0, 1, 1, 55};
    Solution    s;
    cout << s.threeSumClosest(v, 3) << endl;
}