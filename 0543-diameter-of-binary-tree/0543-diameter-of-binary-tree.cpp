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
    int Height(TreeNode* root, int& maxDiameter){
        if(root == nullptr){
            return 0;
        }

        // Recursively find the height of left and right subtrees
        int leftHeight = Height(root->left,maxDiameter);
        int rightHeight = Height(root->right,maxDiameter);

        // The diameter passing through the current node is the sum of left and right heights
        maxDiameter = max(maxDiameter , leftHeight + rightHeight );

        // Return the height of the tree rooted at the current node
        return max(leftHeight , rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;

        Height(root,maxDiameter);

        return maxDiameter;
    }
};