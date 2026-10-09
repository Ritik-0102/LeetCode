class Solution {
public:
    class TrieNode{
        public:
        TrieNode* children[26];
        // Store The Whole Word at the Leaf Node
        string word;

        TrieNode(){
            word = "";
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
        }
    };

    void helper(TrieNode* curr,vector<vector<string>>& ans,int idx){
        if(ans[idx].size() == 3){
            return;
        }
        
        if(curr->word != ""){
            ans[idx].push_back(curr->word);
        }

        for(int i=0;i<26;i++){
            if(curr->children[i] != nullptr){
                helper(curr->children[i],ans,idx);
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* Root = new TrieNode();

        // Build Trie
        for(string s:products){
            TrieNode* curr = Root;
            for(char ch:s){
                if(curr->children[ch - 'a'] == nullptr){
                    curr->children[ch - 'a'] = new TrieNode();
                }
                curr = curr->children[ch - 'a'];
            }
            // Store The Whole Word at the Leaf Node
            curr->word = s;
        }

        vector<vector<string>> ans(searchWord.size());

        // Search our Word & Find the Suggested Word with this Prefix
        TrieNode* curr = Root;
        for(int i=0;i<searchWord.size();i++){
            char ch = searchWord[i];
            if(curr->children[ch - 'a'] != nullptr){
                curr = curr->children[ch - 'a'];
                helper(curr,ans,i);
            }
            else{
                break;
            }
        }

        return ans;
    }
};