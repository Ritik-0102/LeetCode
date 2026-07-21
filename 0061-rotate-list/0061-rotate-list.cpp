/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // 1. Edge cases: empty list, single node, or no rotations needed
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        int size = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            temp = temp->next;
            size++;
        }

        // Handle the cases when k > size of our linked list
        k = k % size;

        if (k == 0) {
            return head;
        }


        ListNode* curr = head;
        for(int i=1;i<(size-k);i++){
            curr = curr->next;
        }

        ListNode* newHead = curr->next;
        curr->next = nullptr;

        ListNode* new_curr = newHead;
        while(new_curr->next != nullptr){
            new_curr = new_curr->next;
        }
        new_curr->next = head;
        
        return newHead;
    }
};