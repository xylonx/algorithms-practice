#include <iostream>
#include <vector>

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
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0 || preorder.size() == 0) {
            return nullptr;
        }

        TreeNode *root = dfs(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);

        return root;
    }

    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int ir) {
        if (pr < pl || ir < il) return nullptr;
        if (pr == pl) return new TreeNode(preorder[pr]);

        int rootval    = preorder[pl];
        TreeNode *root = new TreeNode(rootval);

        int inpos = -1;
        for (int i = il; i <= ir; ++i) {
            if (inorder[i] == rootval) {
                inpos = i;
                break;
            }
        }

        int leftLen = inpos - il, rightLen = (ir - il + 1) - leftLen - 1;

        // pr -x +1 = rightLen
        // x - (pl+1) +1 = leftLen
        root->left  = dfs(preorder, inorder, pl + 1, pl + leftLen, il, inpos - 1);
        root->right = dfs(preorder, inorder, pr + 1 - rightLen, pr, inpos + 1, ir);

        return root;
    }
};
// @lc code=end
