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
    bool isCousins(TreeNode* root, int x, int y) {
        // Base Case
        if(root == nullptr){
            return false;
        }

        // we store current & parent of each node 
        queue<pair<TreeNode*,TreeNode*>> q;
        TreeNode* parentX = nullptr;
        TreeNode* parentY = nullptr;

        q.push({root,nullptr});

        while(q.size() > 0){
            int levelSize = q.size();

            for(int i=0;i<levelSize;i++){
                auto curr = q.front();
                q.pop();

                if(curr.first->val == x){
                    parentX = curr.second;
                }
                if(curr.first->val == y){
                    parentY = curr.second;
                }

                if(curr.first->left != nullptr){
                    q.push({curr.first->left,curr.first});
                }
                if(curr.first->right != nullptr){
                    q.push({curr.first->right,curr.first});
                }
            }

            // If we found both x & y on this level
            if(parentX != nullptr && parentY != nullptr){
                return parentX != parentY;
            }

            // If we found one of x OR y on this level 
            if(parentX != nullptr || parentY != nullptr){
                return false;
            }
        }

        return false;;
    }
};