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
    // Step 1. Store all the values of nums array in set
    // Step 2. now delete elements from linked list which are present in the set
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }

        unordered_set<int> s;

        for(int val:nums){
            s.insert(val);
        }
        
        ListNode* DummyNode = new ListNode(0,head);
        ListNode* temp = DummyNode;

        while(temp != nullptr && temp->next != nullptr){
            if(s.find(temp->next->val) != s.end()){
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next;
            }
        }

        return DummyNode->next;
    }
};