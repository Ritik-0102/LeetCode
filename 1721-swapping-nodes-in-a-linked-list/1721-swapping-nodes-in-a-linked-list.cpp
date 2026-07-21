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
    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0;

        ListNode* temp = head;
        ListNode* kth_node;

        while(temp != nullptr){
            if(size == k-1){
                kth_node = temp;
            }
            temp = temp -> next;
            size++;
        }

        temp = head;

        for(int i=0;i<(size - k);i++){
            temp = temp->next;
        }

        int val = kth_node->val;
        kth_node->val = temp->val;
        temp->val = val ;

        return head;
    }
};