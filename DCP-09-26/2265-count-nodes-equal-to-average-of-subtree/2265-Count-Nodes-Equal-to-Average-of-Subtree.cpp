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
    // return {sum , count of nodes} 
    pair<int,int> helper(TreeNode* root,int& ans){
        if(root == nullptr){
            return {0,0};
        }

        pair<int,int> leftPair = helper(root->left,ans);
        pair<int,int> rightPair = helper(root->right,ans);

        int currSum = root->val + leftPair.first + rightPair.first;
        int countNodes = 1 + leftPair.second + rightPair.second;

        if(root->val == (currSum / countNodes)){
            ans++;
        }

        return {currSum,countNodes};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;

        helper(root,ans);

        return ans;
    }
};