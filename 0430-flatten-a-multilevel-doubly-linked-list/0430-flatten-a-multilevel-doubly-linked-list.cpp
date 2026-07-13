/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr){
            return head;
        }

        Node* temp = head;

        while(temp!=nullptr){
            // If child Exists
            if(temp->child != nullptr){
                // Step 1: Flatten the child nodes
                Node* Next = temp->next;
                temp->next = flatten(temp->child);
                temp->next->prev = temp;

                // Step 2: Make the child list point to null
                temp->child = nullptr;

                // Step 3: Find the tail of child list
                while(temp->next != nullptr){
                    temp = temp->next;
                }

                // Step 4: Attach the tail to the next node of our list
                if(Next != nullptr){
                    temp->next = Next;
                    Next->prev = temp;
                }                
            }
            temp = temp->next;
        }

        return head;
    }
};