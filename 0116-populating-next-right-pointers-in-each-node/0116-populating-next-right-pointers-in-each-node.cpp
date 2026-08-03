/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr){
            return root;
        }
        
        queue<Node*> q;

        q.push(root);

        int levelSize;
        while(q.size() > 0){
            levelSize = q.size();

            for(int i=0;i<levelSize;i++){
                Node* curr = q.front();
                q.pop();

                // if it is not the last element of this level
                // we will point its next pointer to next element of this level
                if(i < levelSize - 1){
                    curr->next = q.front();
                }

                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
            }
        }

        return root;
    }
};