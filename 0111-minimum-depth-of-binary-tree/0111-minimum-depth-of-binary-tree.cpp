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
    void helper(TreeNode* root,int depth,int& ans){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            ans = min(depth,ans);
            return;
        }

        helper(root->left,depth+1,ans);
        helper(root->right,depth+1,ans);
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        int ans = INT_MAX;
        int depth = 1;

        helper(root,depth,ans);

        return ans;
    }
};