class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int c = 1;

        for(int i=0;i<s.size() - 1;i++){
            if(s[i] == s[i+1]){
                c++;
                ans = max(ans,c);
            }
            else{
                c = 1;
            }
        }

        return ans;
    }
};