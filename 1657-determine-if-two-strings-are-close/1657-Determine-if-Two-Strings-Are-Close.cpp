class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        unordered_map<int,bool> m1;
        unordered_map<int,bool> m2;

        for(char ch:word1){
            freq1[ch - 'a']++;
            m1[ch - 'a'] = true;
        }

        for(char ch:word2){
            freq2[ch - 'a']++;
            m2[ch - 'a'] = true;
        }

        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(freq1[i] == freq2[j] && m1[j] && m2[i]){
                    freq2[j] = 0;
                    freq1[i] = 0;
                }
            }
        }

        for(int i=0;i<26;i++){
            if(freq1[i] > 0 || freq2[i] > 0){
                return false;
            }
        }

        return true;
    }
};