// Problem Link : https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

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
    map<int,int>maps;
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        
        find2ndMax(root);
        int i=0;
        for(auto a:maps){
            if(i==1){
                return a.first;
            }
            i++;
        }        
        return -1;
    }
    
    void find2ndMax(TreeNode* root) {
        if(!root)return;
        maps[root->val]++;
        find2ndMax(root->left);
        find2ndMax(root->right);
        return;
    }
};