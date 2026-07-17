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
    ListNode* FindMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next ){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* Merge(ListNode* left,ListNode* right){
        if(left == nullptr){
            return right;
        }
        if(right == nullptr){
            return left;
        }

        if(left->val < right->val){
            left->next = Merge(left->next,right);
            return left;
        }
        else{
            right->next = Merge(left,right->next);
            return right;
        }
    }

    ListNode* sortList(ListNode* head) {
        // Base Case
        if(head == nullptr || head->next == nullptr ){
            return head;
        }

        // Step 1: find middle element & break the list into two halfs
        ListNode* left = head;
        ListNode* middle = FindMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;

        // Step 2: now sort these two halfs separately
        left = sortList(left);
        right = sortList(right);

        // Step 3: Now these two sorted lists 
        return Merge(left,right);
    }
};