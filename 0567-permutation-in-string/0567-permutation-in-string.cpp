class Solution {
public:
    bool isEqual(vector<int>& v1,vector<int>& v2){
        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
    }
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

            if(isEqual(currfreq,freq)){
                return true;
            }
            i++;
            j++;
        }

        return false;
    }
};