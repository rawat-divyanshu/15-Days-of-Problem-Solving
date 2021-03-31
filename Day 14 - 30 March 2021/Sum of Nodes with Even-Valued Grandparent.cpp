// Problem Link : https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
    int res = 0;
    unordered_map<TreeNode*,TreeNode*> pMap;
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        
        findSum(root);
        return res;        
    }
    
    void findSum(TreeNode* root) {
        if(!root) return;
        
        if(pMap.find(root) != pMap.end()) {
            if(pMap.find(pMap[root]) != pMap.end()) {
                if((pMap[pMap[root]]->val) % 2 == 0) {
                    res += root->val;
                }
            }
        }
        
        if(root->left) {
            pMap[root->left] = root;
        }
        
        if(root->right) {
            pMap[root->right] = root;
        }
        
        findSum(root->left);
        findSum(root->right);        
    }
};