// Problem Link : https://leetcode.com/problems/binary-tree-paths/

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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        generateTreePaths(root,"");
        return res;        
    }
    
    void generateTreePaths(TreeNode* root, string path) {
        if(!root) return;
        
        if(!(root->left) && !(root->right)) {
            if(path == "") {
                path = to_string(root->val);
            } else {
                path += "->" + to_string(root->val);
            }
            res.push_back(path);
        }
        
        if(path == "") {
            path = to_string(root->val);
        } else {
            path += "->" + to_string(root->val);
        }
        
        generateTreePaths(root->left,path);
        generateTreePaths(root->right,path);       
    }
};