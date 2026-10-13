class Solution {
public:
    class TrieNode{
        public:
        TrieNode* children[26];
        bool EOW;

        TrieNode(){
            EOW = false;
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
        }
    };

    void insert(TrieNode* Root,string s){
        TrieNode* curr = Root;

        for(char ch:s){
            if(curr->children[ch - 'a'] == nullptr){
                curr->children[ch - 'a'] = new TrieNode();
            }
            curr = curr->children[ch - 'a'];
        }
        curr->EOW = true;
    }

    bool canForm(TrieNode* Root,string s,int idx,vector<int>& dp){
        if(idx == s.size()){
            return true;
        }

        TrieNode* curr = Root;

        for(int i = idx ; i < s.size() ; i++){
            if(curr->children[s[i] - 'a'] == nullptr){
                return dp[idx] = 0;
            }

            curr = curr->children[s[i] - 'a'];

            if(curr->EOW){
                if(canForm(Root,s,i+1,dp)){
                    return dp[idx] = 1;
                }
            }
        }

        // Return false , if no combination works
        return dp[idx] = 0;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        TrieNode* Root = new TrieNode();

        // A valid concatenated word can only be constructed from words shorter than itself.
        // so we process words from shorter to Longer words
        sort(words.begin(),words.end(),[](const string& a , const string& b){
            return a.length() < b.length();
        });

        for(string& s:words){
            if(s.empty()){
                continue;
            }

            vector<int> dp(s.size(),-1);

            // if it can be formed with already existing words , then it is concatenated word
            if(canForm(Root,s,0,dp)){
                ans.push_back(s);
            }
            // Otherwise insert that word into Trie
            else{
                insert(Root,s);
            }
        }

        return ans;
    }
};