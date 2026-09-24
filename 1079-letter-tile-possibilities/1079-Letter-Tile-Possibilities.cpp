class Solution {
public:
    int helper(vector<int>& freq){
        int ans = 0;

        for(int i=0;i<26;i++){
            if(freq[i] > 0){
                ans++;

                freq[i]--; // Remove this character , so that it will not be included again
                ans += helper(freq);
                freq[i]++; // BackTrack
            }
        }

        return ans;
    }

    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);

        for(char ch:tiles){
            freq[ch - 'A']++;
        }

        return helper(freq);
    }
};