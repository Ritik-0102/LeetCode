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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: we need check whether k nodes present OR not
        ListNode* temp = head;
        int count = 0;
        while(count < k){
            if(temp == nullptr){
                return head;
            }
            temp = temp->next;
            count++;
        }

        // Step 2 : Reverse next k nodes Recursively 
        ListNode* Rev_Head = reverseKGroup(temp,k);

        // Step 3: Reverse the current K Nodes
        count = 0;
        ListNode* curr = head;
        while(count < k){
            ListNode* NextNode = curr->next;
            curr->next = Rev_Head;
            Rev_Head = curr;
            curr = NextNode;
            count++;
        }

        return Rev_Head;
    }
};