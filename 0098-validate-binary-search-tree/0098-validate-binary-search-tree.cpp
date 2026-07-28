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
    bool helper(TreeNode* root,TreeNode* minLimit,TreeNode* maxLimit){
        if(root == nullptr){
            return true;
        }

        if(minLimit != nullptr && root->val <= minLimit->val){
            return false;
        }
        if(maxLimit != nullptr && root->val >= maxLimit->val){
            return false;
        }

        return helper(root->left,minLimit,root) && helper(root->right,root,maxLimit);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root,nullptr,nullptr);
    }
};