// Problem Link : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/


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
    int preIndex = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder);
        sort(inorder.begin(),inorder.end());
        
        return constructBST(preorder,inorder,0,inorder.size()-1);        
    }
    
    TreeNode* constructBST(vector<int>& preorder, vector<int> inorder, int is, int ie) {
        if(is > ie) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        
        int atIdx;
        for(int i = is; i <= ie; ++i) {
            if(inorder[i] == root->val) {
                atIdx = i;
                break;
            }
        }
        
        root->left = constructBST(preorder,inorder,is,atIdx-1);
        root->right = constructBST(preorder,inorder,atIdx+1,ie);
        return root;
    }
};