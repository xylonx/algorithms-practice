#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> vkm;
        for (int i = 0; i < nums.size(); i++) {
            auto idx = vkm.find(target - nums[i]);
            if (idx != vkm.end()) return {idx->second, i};
            vkm.insert({nums[i], i});
        }
        return {};
    }
};
// @lc code=end

int main(int argc, char** argv) {
    Solution    s;
    vector<int> v      = {2, 7, 11, 15};
    auto        result = s.twoSum(v, 9);
    for (auto i = result.begin(); i != result.end(); ++i) {
        cout << *i << " ";
    }
}