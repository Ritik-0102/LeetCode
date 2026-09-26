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
    ListNode* Merge(ListNode* head1,ListNode* head2){
        if(head1 == nullptr){
            return head2;
        }
        if(head2 == nullptr){
            return head1;
        }

        if(head1->val < head2->val){
            head1->next = Merge(head1->next,head2);
            return head1;
        }
        else{
            head2->next = Merge(head1,head2->next);
            return head2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n == 0){
            return nullptr;
        }

        ListNode* ans = lists[0];

        for(int i=1;i<n;i++){
            ans = Merge(ans,lists[i]);
        }

        return ans;
    }
};