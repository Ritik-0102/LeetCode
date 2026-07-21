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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // if there are lees than 3 nodes then there is no critical point
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
            return {-1,-1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        int idx = 1;
        int first_critical_idx = -1;
        int prev_critical_idx = -1;

        int minDistance = INT_MAX;

        while(curr->next != nullptr){
            ListNode* next = curr->next;

            // check if the curr node is critical point or not
            // Local Minima OR Local Maxima
            if(prev->val < curr->val && curr->val > next->val || prev->val > curr->val && curr->val < next->val){

                // if it is first critical point
                if(first_critical_idx == -1){
                    first_critical_idx = idx;
                }
                // if we already have previous critical point
                else{
                    minDistance = min(minDistance,idx - prev_critical_idx);
                }
                
                prev_critical_idx = idx;
            }

            
            // Move the nodes
            prev = curr;
            curr = next;
            idx++;
        }

        if(minDistance == INT_MAX){
            return {-1,-1};
        }

        int maxDistance = prev_critical_idx - first_critical_idx;

        return {minDistance,maxDistance};
    }
};