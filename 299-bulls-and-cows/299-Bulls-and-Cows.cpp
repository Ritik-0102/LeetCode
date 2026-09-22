class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0;

        for(int i=0;i<n;i++){
            if(secret[i] == guess[i]){
                bulls++;
            }
        }

        vector<int> freq(10,0);
        for(char ch:secret){
            freq[ch - '0']++;
        }

        int cows = 0;
        for(char ch:guess){
            if(freq[ch - '0'] > 0){
                cows++;
            }
            freq[ch - '0']--;
        }

        string ans = to_string(bulls) + "A" + to_string(cows - bulls) + "B";

        return ans;
    }
};