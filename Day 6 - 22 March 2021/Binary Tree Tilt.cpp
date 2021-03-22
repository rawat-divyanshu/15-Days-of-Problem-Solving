// Problem Link : https://leetcode.com/problems/binary-tree-tilt/

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
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        
        int currentNodeAns = abs(findSum(root->right) - findSum(root->left));
        
        return currentNodeAns + findTilt(root->left) + findTilt(root->right);        
    }
    
    int findSum(TreeNode* root) {
        if(!root) return 0;
        
        return root->val + findSum(root->right) + findSum(root->left);
    }
};