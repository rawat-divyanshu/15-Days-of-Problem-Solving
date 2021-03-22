// Problem Link : https://leetcode.com/problems/sum-of-left-leaves/

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        findLeftLeafSum(root,false,sum);
        return sum;
    }
    
    void findLeftLeafSum(TreeNode* root, bool isLeftNode, int& sum) {
        if(!root) return;
        
        if(isLeftNode && !(root->left) && !(root->right)) {
            sum += root->val;
        }
        
        findLeftLeafSum(root->left,true,sum);
        findLeftLeafSum(root->right,false,sum);
    }
};