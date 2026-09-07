class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;
        // we store the distinct subsequences ends with character in ends_with[i]
        vector<int> ends_with(26,0);

        for(char ch:s){
            long long total_so_far = 0;

            for(int i=0;i<26;i++){
                total_so_far = (total_so_far + ends_with[i]) % MOD;
            }

            // Overwrite the distinct subsequences to remove duplicate subsequences
            ends_with[ch - 'a'] = (total_so_far + 1) % MOD;
        }

        long long ans = 0;
        for(int i=0;i<26;i++){
            ans = (ans + ends_with[i]) % MOD;
        }

        return ans;
    }
};