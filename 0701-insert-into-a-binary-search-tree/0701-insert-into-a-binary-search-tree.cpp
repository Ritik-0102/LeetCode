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
    TreeNode* insertIntoBST(TreeNode* Root, int val) {
        if(Root==NULL){
            return new TreeNode(val);
        }
        if(val<Root->val){
            Root->left = insertIntoBST(Root->left,val);
        }
        else{
            Root->right = insertIntoBST(Root->right,val);
        }

        return Root;
    }
};