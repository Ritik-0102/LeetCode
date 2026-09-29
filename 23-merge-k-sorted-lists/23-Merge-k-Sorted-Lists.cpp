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
    ListNode* Merge(ListNode* l1,ListNode* l2){
        ListNode* Dummy = new ListNode(0);
        ListNode* temp = Dummy;

        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                temp->next = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        // If something is left on any of the list
        if(l1 != nullptr){
            temp->next = l1;
        }
        else{
            temp->next = l2;
        }

        return Dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        if(lists.size() == 1){
            return lists[0];
        }

        queue<ListNode*> q;

        for(ListNode* l:lists){
            q.push(l);
        }

        while(q.size() > 1){
            ListNode* l1 = q.front();
            q.pop();
            ListNode* l2 = q.front();
            q.pop();

            ListNode* ans = Merge(l1,l2);
            q.push(ans);
        }

        return q.front();
    }
};