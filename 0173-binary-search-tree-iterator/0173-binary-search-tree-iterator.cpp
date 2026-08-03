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
class BSTIterator {
public:
    // we will do inorder traversal with the help of stack
    // 1. we store leftmost nodes for root
    // 2. then while moving towards next node we store the right nodes also

    stack<TreeNode*> s;

    void storeLeftNodes(TreeNode* root){
        while(root != nullptr){
            s.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        storeLeftNodes(root);
    }
    
    int next() {
        TreeNode* curr = s.top();
        s.pop();

        storeLeftNodes(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
        return s.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */