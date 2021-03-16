// Problem Link : https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTreeHelper(nums,0,nums.size()-1);        
    }
    
    TreeNode* constructMaximumBinaryTreeHelper(vector<int> nums, int l, int r) {
        if(l > r) {
            return nullptr;
        }
        int maxValIdx = l;
        for(int i = l; i <= r; ++i) {
            if(nums[i] > nums[maxValIdx]) {
                maxValIdx = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxValIdx]);
        root->left = constructMaximumBinaryTreeHelper(nums,l,maxValIdx-1);
        root->right = constructMaximumBinaryTreeHelper(nums,maxValIdx+1,r);
        return root;
    }
};