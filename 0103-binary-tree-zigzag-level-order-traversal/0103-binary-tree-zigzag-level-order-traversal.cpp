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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);

        int levelSize;
        int levelIdx = 1;

        while(!q.empty()){
            levelSize = q.size();

            vector<int> level;

            for(int i=0;i<levelSize;i++){
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
            }

            if(levelIdx % 2 == 0){
                reverse(level.begin(),level.end());
            }

            ans.push_back(level);

            levelIdx++;
        }

        return ans;
    }
};