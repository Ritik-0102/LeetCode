class Solution {
public:
    class TrieNode{
        public:
        TrieNode* children[26];
        // Cache up to 3 suggestions directly in the node
        vector<string> suggestions;

        TrieNode(){
            for(int i=0; i<26; i++){
                children[i] = nullptr;
            }
        }
    };

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // 1. Sort first to guarantee lexicographical order
        sort(products.begin(), products.end());
        
        TrieNode* Root = new TrieNode();

        // 2. Build Trie and cache suggestions on the way down
        for(string s : products){
            TrieNode* curr = Root;
            for(char ch : s){
                if(curr->children[ch - 'a'] == nullptr){
                    curr->children[ch - 'a'] = new TrieNode();
                }
                curr = curr->children[ch - 'a'];
                
                // Cache the first 3 words that pass through this prefix
                if(curr->suggestions.size() < 3) {
                    curr->suggestions.push_back(s);
                }
            }
        }

        vector<vector<string>> ans(searchWord.size());

        // 3. Search is now instant O(1) retrieval per character
        TrieNode* curr = Root;
        for(int i = 0; i < searchWord.size(); i++){
            char ch = searchWord[i];
            if(curr->children[ch - 'a'] != nullptr){
                curr = curr->children[ch - 'a'];
                ans[i] = curr->suggestions; // Just grab the cached list!
            }
            else{
                break; // Prefix not found, remaining vectors stay empty
            }
        }

        return ans;
    }
};