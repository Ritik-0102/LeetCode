class Solution {
public:
    // Sliding Window Technique
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()){
            return {};
        }
        vector<int> ans;
        vector<int> freq(26,0);

        for(char ch : p){
            freq[ch-'a']++;
        }

        vector<int> freq2(26,0);

        // First window
        for(int i=0;i<p.size();i++){
            freq2[s[i] - 'a']++;
        }

        if(freq2 == freq){
            ans.push_back(0);
        }

        // Other Windows
        for(int i = 1; i <= (s.size() - p.size()) ; i++){
            freq2[s[i + p.size() - 1] - 'a']++;
            freq2[s[i - 1] - 'a']--;

            if(freq2 == freq){
                ans.push_back(i);
            }
        }

        return ans;
    }
};