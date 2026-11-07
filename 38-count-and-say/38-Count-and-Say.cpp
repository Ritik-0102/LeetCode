class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }

        string s = countAndSay(n-1);
        string ans = "";
        int count = 0;

        for(int i=0;i<s.size();i++){
            int j=i;
            while(j < s.size() && s[i] == s[j]){
                count++;
                j++;
            }
            ans += to_string(count) + s[i];
            count = 0;
            i = j-1;
        }

        return ans;
    }
};