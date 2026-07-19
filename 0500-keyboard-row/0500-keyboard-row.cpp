class Solution {
public:
    bool helper(vector<int>& freq,string s){
        for(char ch:s){
            if(freq[tolower(ch) - 'a'] == 0){
                return false;
            }
        }

        return true;
    }
    vector<string> findWords(vector<string>& words) {
        string seq1 = "qwertyuiop";
        string seq2 = "asdfghjkl";
        string seq3 = "zxcvbnm";

        vector<int> freq1(256,0);
        for(char ch:seq1){
            freq1[ch - 'a']++;
        }

        vector<int> freq2(256,0);
        for(char ch:seq2){
            freq2[ch - 'a']++;
        }

        vector<int> freq3(256,0);
        for(char ch:seq3){
            freq3[ch - 'a']++;
        }

        vector<string> ans;

        for(string s:words){
            if(helper(freq1,s) || helper(freq2,s) || helper(freq3,s)){
                ans.push_back(s);
            }
        }

        return ans;
    }
};