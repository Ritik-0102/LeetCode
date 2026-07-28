class Solution {
public:
    string reversePrefix(string s, char ch) {
        int n = s.size();
        int idx = -1;

        for(int i=0;i<n;i++){
            if(s[i] == ch){
                idx = i;
                break;
            }
        }

        if(idx == -1){
            return s;
        }

        string ans = "";

        for(int i=idx;i>=0;i--){
            ans += s[i];
        }
        for(int i=idx+1;i<n;i++){
            ans += s[i];
        }

        return ans;
    }
};