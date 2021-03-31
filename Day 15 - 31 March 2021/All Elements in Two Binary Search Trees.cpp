// Problem Link : https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> s1;
        fillStack(root1,s1);
        stack<TreeNode*> s2;
        fillStack(root2,s2);
        
        while(!s1.empty() && !s2.empty()) {
            TreeNode* c = nullptr;
            if(s1.top()->val < s2.top()->val) {
                c = s1.top();
                s1.pop();
                fillStack(c->right,s1);
            } else {
                c = s2.top();
                s2.pop();
                fillStack(c->right,s2);
            }
            res.push_back(c->val);
        }
        
        while(!s1.empty()) {
            TreeNode* c1 = s1.top();
            s1.pop();
            fillStack(c1->right,s1);
            res.push_back(c1->val);
        }
        
        while(!s2.empty()) {
            TreeNode* c2 = s2.top();
            s2.pop();
            fillStack(c2->right,s2);
            res.push_back(c2->val);
        }
        return res;        
    }
    
    void fillStack(TreeNode* root, stack<TreeNode*>& s) {
        while(root) {
            s.push(root);
            root = root->left;
        }
    }
};