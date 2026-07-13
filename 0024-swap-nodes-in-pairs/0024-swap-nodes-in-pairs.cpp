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
    ListNode* swapPairs(ListNode* head) {
        // Iterative Approach
        
        if(head==nullptr || head->next == nullptr){
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* first = head;
        ListNode* second = first->next;

        while(first!=nullptr && second!=nullptr){
            ListNode* third = second->next;

            second->next = first;
            first->next = third;

            if(prev!=nullptr){
                prev->next = second;
            }
            else{
                head = second;
            }

            prev = first;
            first = third;
            if(third!=nullptr){
                second = third->next;
            }
            else{
                second = nullptr;
            }
        }

        return head;
    }
};