class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        vector<int> ans;
        
        // 1. Count frequencies of the first array only
        for (int num : nums1) {
            freq[num]++;
        }
        
        // 2. Iterate through the second array
        for (int num : nums2) {
            // If the number exists in our map and count is > 0
            if (freq[num] > 0) {
                ans.push_back(num);
                freq[num]--; // Decrement the count so we don't reuse it
            }
        }
        
        return ans;
    }
};