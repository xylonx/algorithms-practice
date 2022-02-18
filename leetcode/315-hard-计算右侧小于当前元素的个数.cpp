#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution {
private:
    class BinaryIndexTree {
    private:
        vector<int> bitree;
        int lowbit(int x) { return x & -x; }

    public:
        BinaryIndexTree(int n) { bitree.resize(n + 1, 0); }
        void add(int x, int k) {
            while (x < bitree.size()) {
                bitree[x] += k;
                x += lowbit(x);
            }
        }
        int getsum(int x) {
            int ans = 0;
            while (x > 0) {
                ans += bitree[x];
                x -= lowbit(x);
            }
            return ans;
        }
    };

public:
    vector<int> countSmaller(vector<int>& nums) {
        int idx = 1;
        unordered_map<int, int> m;
        set<int> s(nums.begin(), nums.end());
        for (auto& i : s) m[i] = idx++;
        BinaryIndexTree t(s.size());

        vector<int> ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans[i] = t.getsum(m[nums[i]] - 1);
            t.add(m[nums[i]], 1);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char**) {
    vector<int> nums = {5, 2, 6, 1};
    Solution s;
    auto res = s.countSmaller(nums);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}