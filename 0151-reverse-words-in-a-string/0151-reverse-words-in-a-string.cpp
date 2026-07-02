class Solution {
public:
    string reverseWords(string s) {
        // First we will reverse the whole string
        reverse(s.begin(),s.end());

        // And now we will reverse all the words individually & add them in our ans string
        string ans = "";

        for(int i=0;i<s.size();i++){
            string word="";
            while(i<s.size() && s[i]!=' '){
                word+=s[i];
                i++;
            }

            reverse(word.begin(),word.end());

            if(word.size() > 0){
                ans += " " + word;
            }
        }

        // we have an extra space at the first index , so we will remove it from our ans
        return ans.substr(1);
    }
};