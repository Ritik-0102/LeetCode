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
    void helper(TreeNode* root,int temp,vector<int>& paths){
        if(root == nullptr){
            return;
        }

        temp = temp * 10 + root->val;

        // Check if it's a leaf node
        if(root->left == nullptr && root->right == nullptr){
            paths.push_back(temp);
            return;
        }

        helper(root->left,temp,paths);
        helper(root->right,temp,paths);
    }

    int sumNumbers(TreeNode* root) {
        vector<int> paths;

        helper(root,0,paths);

        int ans = 0;
        for(int p:paths){
            ans += p;
        }

        return ans;
    }
};