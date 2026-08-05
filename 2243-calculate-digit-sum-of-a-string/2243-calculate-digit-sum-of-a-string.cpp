class Solution {
public:
    string calc(string s,int k){
        string ans = "";

        int n = s.size();
        int i = 0;

        while(i<n){
            int j = 0;
            int sum = 0;
            while(j<k && i<n){
                sum += (s[i] - '0');
                i++;
                j++;
            }
            ans += to_string(sum);
        }

        return ans;
    }
    
    string digitSum(string s, int k) {
        
        while(s.size() > k){
            s = calc(s,k);
        }

        return s;
    }
};