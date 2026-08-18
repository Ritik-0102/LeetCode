class Solution {
public:
    int minSteps(string s, string t) {
        int freq[26] = {0};

        for(char ch:s){
            freq[ch -'a']++;
        }
        for(char ch:t){
            freq[ch -'a']--;
        }

        int ans = 0;
        for(int i:freq){
            ans += abs(i);
        }

        return ans/2;
    }
};