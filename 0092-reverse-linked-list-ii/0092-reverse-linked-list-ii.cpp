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
    ListNode* helper(ListNode* head ,ListNode* rightNode){
        ListNode* prev = rightNode;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != rightNode){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || left == right == 1){
            return head;
        }

        ListNode* leftNode = head;
        for(int i=2;i<left;i++){
            leftNode = leftNode->next;
        }

        ListNode* rightNode = head;
        for(int i=1;i<=right;i++){
            rightNode = rightNode->next;
        }

        if(left == 1){
            head = helper(head , rightNode);
        }
        else{
            leftNode->next = helper(leftNode->next , rightNode);
        }

        return head;
    }
};