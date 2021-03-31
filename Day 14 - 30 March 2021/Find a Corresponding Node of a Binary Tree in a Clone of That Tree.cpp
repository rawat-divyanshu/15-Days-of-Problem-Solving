// Problem Link : https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original->val == target->val) {
            return cloned;            
        }
        
        TreeNode* foundRef = nullptr;
        
        if(original->left && !foundRef) {
            foundRef = getTargetCopy(original->left,cloned->left,target);
        }
        
        if(original->right && !foundRef) {
            foundRef = getTargetCopy(original->right,cloned->right,target);
        }
        
        return foundRef;        
    }
};