class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);

        for(char ch:s1){
            freq[ch - 'a']++;
        }

        int i=0;
        int j=s1.size()-1;

        while(j<s2.size()){
            vector<int> currfreq(26,0);
            for(int x=i;x<=j;x++){
                currfreq[s2[x] - 'a']++;
            }

            if(currfreq == freq){
                return true;
            }
            i++;
            j++;
        }

        return false;
    }
};