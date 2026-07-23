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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans;
        queue<TreeNode*> q;

        q.push(root);

        int levelSize;
        long long sum;

        while(q.size() > 0){
            levelSize = q.size();
            sum = 0;

            for(int i=0;i<levelSize;i++){
                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val;

                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
            }
            ans.push_back(sum);
        }

        if(ans.size() < k){
            return -1;
        }

        sort(ans.begin(),ans.end());

        return ans[ans.size() - k];
    }
};