class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int n = s.size();
        int m = words.size();
        int wordLen = words[0].size();
        int TotalLength = m * wordLen;

        if(n < TotalLength){
            return ans;
        }

        unordered_map<string,int> freq;

        for(const string& word:words){
            freq[word]++;
        }

        // This track all possible alignments
        for(int i=0 ; i < wordLen ; i++){
            // it is used to trace the words in current sequence
            unordered_map<string,int> seen;

            // it tells the starting & ending of our sequence
            int left = i;
            int right = i;
            int count = 0;

            while(right + wordLen <= n){
                string word = s.substr(right , wordLen);
                seen[word]++;
                count++;
                right += wordLen;

                // if the word is not in words , then it is invalid idx
                if(freq.find(word) == freq.end()){
                    count = 0;
                    seen.clear();
                    left = right;
                }

                // if the word found freq is more than what we require , then shrink window from left 
                while(seen[word] > freq[word]){
                    string leftWord = s.substr(left,wordLen);
                    seen[leftWord]--;
                    count--;
                    left += wordLen;
                }

                // we found all the words
                if(count == m){
                    ans.push_back(left);
                }
            }
        }

        return ans;
    }
};