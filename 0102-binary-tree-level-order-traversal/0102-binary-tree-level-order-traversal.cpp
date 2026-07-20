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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);
        q.push(nullptr);

        vector<int> temp;

        while(q.size() > 0){
            TreeNode* curr = q.front();
            q.pop();

            if(curr == nullptr){
                if(!q.empty()){
                    ans.push_back(temp);
                    temp = {};
                    q.push(nullptr);
                    continue;
                }
                else{
                    ans.push_back(temp);
                    break;
                }
            }

            temp.push_back(curr->val);

            if(curr->left != nullptr){
                q.push(curr->left);
            }
            if(curr->right != nullptr){
                q.push(curr->right);
            }
        }

        return ans;
    }
};