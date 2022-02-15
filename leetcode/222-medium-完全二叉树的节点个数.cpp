#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int cnt(TreeNode *root) {
        if (root == nullptr) return 0;
        int lh = 0, rh = 0;
        TreeNode *cur = root;
        while (cur != nullptr) ++lh, cur = cur->left;
        cur = root;
        while (cur != nullptr) ++rh, cur = cur->right;
        if (lh == rh) return (1 << lh) - 1;
        return cnt(root->left) + cnt(root->right) + 1;
    }

public:
    int countNodes(TreeNode *root) { return cnt(root); }
};
// @lc code=end
