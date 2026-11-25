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
    void findSortedArray(vector<int>& arr,TreeNode* Root){
        if(Root == nullptr){
            return;
        }

        findSortedArray(arr,Root->left);
        arr.push_back(Root->val);
        findSortedArray(arr,Root->right);
    }

    TreeNode* helper(vector<int>& arr,int start,int end){
        if(start > end){
            return nullptr;
        }

        int mid = start + (end - start)/2;

        TreeNode* Root = new TreeNode(arr[mid]);

        Root->left = helper(arr,start,mid-1);
        Root->right = helper(arr,mid + 1,end);

        return Root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;

        findSortedArray(arr,root);

        return helper(arr,0,arr.size() - 1);
    }
};