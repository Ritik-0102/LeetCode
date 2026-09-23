class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s(nums.begin(),nums.end());

        for(int i:s){
            // check whether it is a starting point of the sequence
            // previous element is not present in set , then it is starting point
            if(s.find(i-1) == s.end()){
                int length = 1;
                while(s.find(i + length) != s.end()){
                    length++;
                }
                ans = max(ans,length);
            }
        }

        return ans;
    }
};