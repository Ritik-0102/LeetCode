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
    void helper(TreeNode* root,vector<double>& ans){
        queue<TreeNode*> q;

        q.push(root);

        int levelSize;

        while(q.size() > 0){
            levelSize = q.size();

            vector<int> temp;

            for(int i=0;i<levelSize;i++){
                TreeNode* curr = q.front();
                q.pop();

                temp.push_back(curr->val);

                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
            }

            double avg = 0;
            for(int i:temp){
                avg += i;
            }
            ans.push_back(avg/levelSize);
        }
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;

        helper(root,ans);

        return ans;
    }
};