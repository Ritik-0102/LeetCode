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

    // we will do Inorder Traversal
    // then we will calculate min difference with every previous node val

    TreeNode* prev = nullptr;

    int minDiffInBST(TreeNode* root) {
        if(root == nullptr){
            return INT_MAX;
        }

        int ans = INT_MAX;

        // find the left minimum difference
        if(root->left != nullptr){
            int leftMin = minDiffInBST(root->left);
            ans = min(ans,leftMin);
        }

        // find the curr minimum difference & update prev with root
        if(prev != nullptr){
            ans = min(ans,root->val - prev->val);
        }
        prev = root;

        // find the right minimum difference
        if(root->right != nullptr){
            int rightMin = minDiffInBST(root->right);
            ans = min(ans,rightMin);
        }

        return ans;
    }
};