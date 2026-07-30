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
    class Info{
        public:
        int min;
        int max;
        int sum;

        Info(int min,int max,int sum){
            this->min = min;
            this->max = max;
            this->sum = sum;
        }
    };

    Info helper(TreeNode* Root,int& maxSum){
        // Base Case: An empty tree is a valid BST of sum 0.
        // We return max possible min, and min possible max so leaf nodes pass the check.
        if(Root == nullptr){
            return Info(INT_MAX,INT_MIN,0);
        }
        
        // 1. Post-order traversal (Left, Right, Node)
        Info left=helper(Root->left,maxSum);
        Info right=helper(Root->right,maxSum);
        
        // 2. Check if current subtree forms a valid BST
        if(Root->val > left.max && Root->val < right.min){
            int currMin = min(Root->val,left.min);
            int currMax = max(Root->val,right.max);
            int currSum = left.sum + right.sum + Root->val;

            maxSum = max(maxSum,currSum);

            return Info(currMin,currMax,currSum);
        }
        else{
            // 3. If it's NOT a valid BST, pass up the largest sum found so far.
            // We set min to INT_MIN and max to INT_MAX so ancestors will definitely fail the BST check.
            return Info(INT_MIN,INT_MAX,max(left.sum,right.sum));
        }
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        
        helper(root,maxSum);

        return maxSum;
    }
};