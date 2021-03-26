// Problem Link : https://leetcode.com/problems/cousins-in-binary-tree/

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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        if(root->val == x || root->val == y) return false;
        
        queue<TreeNode*> ele;
        ele.push(root);
        unordered_map<TreeNode*,TreeNode*> p;
        
        while(!ele.empty()) {
            int prevParent = 0;
            int prevSize = ele.size();
            for(int i = 0; i < prevSize; ++i) {
                TreeNode* c = ele.front();
                ele.pop();
                if(c->val == x || c->val == y) {
                    if(prevParent == 0) {
                        prevParent = p[c]->val;
                    } else {
                        if(prevParent == p[c]->val) {
                            return false;
                        } else {
                            return true;
                        }
                    }
                    
                }
                if(c->left) {
                    p[c->left] = c;
                    ele.push(c->left);
                }
                if(c->right) {
                    p[c->right] = c;
                    ele.push(c->right);
                }
            }
        }
        return false;
    }
};