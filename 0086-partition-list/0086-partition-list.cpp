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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller_dummy = new ListNode(0);
        ListNode* greater_dummy = new ListNode(0);

        ListNode* smaller_temp = smaller_dummy;
        ListNode* greater_temp = greater_dummy;

        ListNode* curr = head;

        while(curr != nullptr){
            if(curr->val < x){
                smaller_temp->next = curr;
                smaller_temp = smaller_temp->next ;
            }
            else{
                greater_temp->next = curr;
                greater_temp = greater_temp->next;
            }

            curr = curr->next;
        }

        greater_temp -> next = nullptr;

        smaller_temp->next = greater_dummy->next;

        return smaller_dummy->next;
    }
};