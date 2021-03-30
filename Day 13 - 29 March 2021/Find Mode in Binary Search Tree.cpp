// Problem Link : https://leetcode.com/problems/find-mode-in-binary-search-tree/

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
    int prev = -1;
    int max = INT_MIN;
    int count = 1;
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        
        vector<int> modes;
        traverse(root,modes);
        return modes;        
    }
    
    void traverse(TreeNode* root, vector<int>& modes) {
        if(!root) return;
        
        traverse(root->left, modes);
        
        if(prev != -1) {
            if(prev == root->val) {
                ++count;
            } else {
                count = 1;
            }            
        }
        
        if(count > max) {
            max = count;
            modes.clear();
            modes.push_back(root->val);
        } else if (count == max) {
            modes.push_back(root->val);
        }
        
        prev = root->val;
        
        traverse(root->right, modes);        
    }
};