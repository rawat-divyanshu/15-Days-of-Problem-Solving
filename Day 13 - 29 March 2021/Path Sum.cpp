// Problem Link : https://leetcode.com/problems/path-sum/

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return hasPathSumHelper(root,targetSum,0);
    }
    
    bool hasPathSumHelper(TreeNode* root, int targetSum, int currentSum) {
        if(!root) return false;
        
        currentSum += root->val;
        
        if(!(root->left) && !(root->right)) {
            if(targetSum == currentSum) {
                return true;
            }
        }
        
        bool foundTargetSumPath = false;
        
        if(root->left && !foundTargetSumPath) {
            foundTargetSumPath = hasPathSumHelper(root->left,targetSum,currentSum);            
        }
        
        if(root->right && !foundTargetSumPath) {
            foundTargetSumPath = hasPathSumHelper(root->right,targetSum,currentSum);            
        }
        
        return foundTargetSumPath;        
    }
};