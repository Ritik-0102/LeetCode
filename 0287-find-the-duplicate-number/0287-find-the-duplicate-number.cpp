class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        // we will solve this question by Slow & Fast Pointer Approach
        // By imagining this array as linked list
        // like the index is the address of any element & the value stored int it is the address of next element

        int slow = arr[0]; 
        int fast = arr[0]; 

        // Currently slow & fast are pointing at same position , so we will use do-while loop
        do{
            slow = arr[slow];
            fast = arr[arr[fast]];
        }while(slow != fast);

        slow = arr[0];
        while(slow != fast){
            slow = arr[slow];
            fast = arr[fast];
        }

        return slow;
    }
};