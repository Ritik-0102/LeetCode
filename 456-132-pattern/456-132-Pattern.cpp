class Solution {
public:
    // we are looking for Small - Large - Medium Pattern

    bool find132pattern(vector<int>& nums) {
        int n = nums.size();

        if(n < 3){
            return false;
        }

        // To store possible nums[j] - Largest (3)
        stack<int> s;

        // To store possible nums[k] - Medium (2)
        int Medium = INT_MIN;

        for(int i = n-1 ; i >= 0 ; i--){
            // if we found any number less than our Medium element , then we found our pattern
            if(nums[i] < Medium){
                return true;
            }

            // Remove all the elements from stack , which are less than our current element
            // And while removing store smallest among them as our Medium for future
            while(!s.empty() && s.top() < nums[i]){
                Medium = s.top();
                s.pop();
            }

            s.push(nums[i]);
        }

        return false;
    }
};