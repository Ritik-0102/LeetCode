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

    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* Root = new TrieNode();

        // Build Trie
        for(string s:dictionary){
            TrieNode* curr = Root;
            for(char ch:s){
                if(curr->children[ch - 'a'] == nullptr){
                    curr->children[ch - 'a'] = new TrieNode();
                }
                curr = curr->children[ch - 'a'];
            }
            curr->EOW = true;
        }

        string ans = "";

        for(int i=0;i<sentence.size();i++){
            TrieNode* curr = Root;

            // Find The Root
            while(i < sentence.size() && sentence[i] != ' ' && curr->children[sentence[i] - 'a'] != nullptr){
                ans += sentence[i];
                curr = curr->children[sentence[i] - 'a'];
                i++;

                if(curr->EOW == true){
                    break;
                }
            }

            // if Root is found , then move to next word
            if(curr->EOW == true){
                while(i < sentence.size() && sentence[i] != ' '){
                    i++;
                }
            }
            // Otherwise append whole word
            else{
                while(i < sentence.size() && sentence[i] != ' '){
                    ans += sentence[i];
                    i++;
                }
            }
            ans += ' ';
        }

        return ans.substr(0,ans.size()-1);
    }
};