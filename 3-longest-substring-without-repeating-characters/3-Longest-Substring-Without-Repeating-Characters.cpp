class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;

        int ans = 0;
        int left = 0;

        for(int i=0 ; i < s.size() ; i++){
            // if the character is seen before , then update our left
            if(m.find(s[i]) != m.end()){
                left = max(left,m[s[i]] + 1);
            }

            m[s[i]] = i;
            
            // calculate the max length for the current valid window
            ans = max(ans,i - left + 1);
        }

        return ans;
    }
};