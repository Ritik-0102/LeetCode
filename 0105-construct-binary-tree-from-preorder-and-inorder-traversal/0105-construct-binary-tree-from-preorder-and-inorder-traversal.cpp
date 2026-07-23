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
    int search(vector<int>& inorder,int val){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i] == val){
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int& preIdx,int left,int right){
        if(left > right){
            return nullptr;
        }

        TreeNode* Root = new TreeNode(preorder[preIdx]);
        preIdx++;

        int inorderIdx = search(inorder,Root->val);

        Root->left = helper(preorder,inorder,preIdx,left,inorderIdx - 1);
        Root->right = helper(preorder,inorder,preIdx,inorderIdx + 1,right);

        return Root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder,inorder,preIdx,0,inorder.size() - 1);
    }
};