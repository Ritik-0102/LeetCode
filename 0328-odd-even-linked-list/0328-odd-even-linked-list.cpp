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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;

        int idx = 1;
        ListNode* temp = even->next;
        ListNode* odd_temp = odd;
        ListNode* even_temp = even;

        while(temp != nullptr){
            if(idx % 2 == 0){
                even_temp -> next = temp;
                even_temp = even_temp -> next;
            }
            else{
                odd_temp -> next = temp;
                odd_temp = odd_temp -> next;
            }
            
            temp = temp->next;
            idx++;
        }

        // Terminate the even list to prevent a cycle
        even_temp -> next = nullptr;

        // Connect the end of the odd list to the start of the even list
        odd_temp -> next = even;

        return odd;
    }
};