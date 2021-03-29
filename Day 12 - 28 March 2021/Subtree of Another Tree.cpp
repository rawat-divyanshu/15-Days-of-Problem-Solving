// Problem Link : https://leetcode.com/problems/subtree-of-another-tree/

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s || !t) return s == t;
        
        if(s->val == t ->val) {
            if(checkSame(s,t)) {
                return true;
            }
        }
        bool ans = isSubtree(s->left,t) || isSubtree(s->right,t);
        return ans;
    }
    
    bool checkSame(TreeNode* s, TreeNode* t) {
        if(!s || !t) return s == t;
        
        if(s->val != t->val) return false;
        
        return checkSame(s->left, t->left) && checkSame(s->right, t->right);
    }
};