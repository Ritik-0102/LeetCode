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
    void minimum(TreeNode* root,int& min1,int& min2,bool& present){
        if(root == nullptr){
            return;
        }

        if(root->val < min1){
            min1 = root->val;
        }

        if(root->val <= min2 && root->val > min1){
            min2 = root->val;
            present = true;
        }

        minimum(root->left,min1,min2,present);
        minimum(root->right,min1,min2,present);

    }

    int findSecondMinimumValue(TreeNode* root) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        bool present = false;

        minimum(root,min1,min2,present);

        if(!present){
            return -1;
        }

        return min2;
    }
};