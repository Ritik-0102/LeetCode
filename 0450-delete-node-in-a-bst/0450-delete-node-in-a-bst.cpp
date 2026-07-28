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
    TreeNode* FindIS(TreeNode* root){
        while(root->left != nullptr){
            root = root->left;
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return nullptr;
        }

        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        else{
            // root->val == key

            // Case 1 & 2 : when there is 0 OR 1 childs exist for node to be deleted
            if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else{
                // Case 3 : when there is 2 childs exist for node to be deleted

                // 1. Find Inorder Successor
                TreeNode* IS = FindIS(root->right);

                // 2. Now copy value IS into root node 
                root->val = IS->val;

                // 3. now delete the IS
                root->right = deleteNode(root->right,IS->val);
            }
        }

        return root;
    }
};