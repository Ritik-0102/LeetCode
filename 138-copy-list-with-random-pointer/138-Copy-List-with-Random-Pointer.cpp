/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }

        unordered_map<Node*,Node*> m;

        Node* CopyHead = new Node(head->val);
        m[head] = CopyHead;

        Node* oldTemp = head->next;
        Node* newTemp = CopyHead;

        while(oldTemp != nullptr){
            newTemp->next = new Node(oldTemp->val);
            newTemp = newTemp->next;
            m[oldTemp] = newTemp;
            oldTemp = oldTemp->next;
        }

        oldTemp = head;

        while(oldTemp != nullptr){
            if(oldTemp->random != nullptr){
                Node* temp = m[oldTemp->random];
                m[oldTemp]->random = temp;
            }
            oldTemp = oldTemp->next;
        }

        return CopyHead;
    }
};