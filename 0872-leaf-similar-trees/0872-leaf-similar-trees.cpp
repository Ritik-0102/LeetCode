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
    void leafSequence(TreeNode* root,vector<int>& ans){
        if(root == nullptr){
            return;
        }

        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(root->val);
        }

        leafSequence(root->left,ans);
        leafSequence(root->right,ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafSeq1 ;
        vector<int> leafSeq2 ;
        
        leafSequence(root1,leafSeq1);
        leafSequence(root2,leafSeq2);

        int n = leafSeq1.size();
        int m = leafSeq2.size();

        if(n != m){
            return false;
        }

        for(int i=0;i<n;i++){
            if(leafSeq1[i] != leafSeq2[i]){
                return false;
            }
        }

        return true;
    }
};