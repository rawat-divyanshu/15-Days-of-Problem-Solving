// Problem Link : https://leetcode.com/problems/deepest-leaves-sum/

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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        
        int res = 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            res = 0;
            for(int i = 0; i < n; ++i) {
                TreeNode* c = q.front();
                q.pop();
                if(c->left) {
                    q.push(c->left);
                }
                if(c->right) {
                    q.push(c->right);
                }
                res += c->val;
            }
        }
        return res;        
    }
};