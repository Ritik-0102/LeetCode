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
    void helper(vector<string>& ans,TreeNode* root,string path){
        if(root->left == nullptr && root->right == nullptr){
            path += to_string(root->val);
            ans.push_back(path);
            return;
        }
        
        if(root->left != nullptr){
            helper(ans,root->left,path + to_string(root->val) + "->" );
        }
        if(root->right != nullptr){
            helper(ans,root->right,path + to_string(root->val) + "->" );
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        helper(ans,root,"");

        return ans;
    }
};