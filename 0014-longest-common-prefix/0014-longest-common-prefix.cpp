class Solution {
public:
    class TrieNode{
        public:
        TrieNode* children[26];
        bool EndOfWord;
        int ChildCount;

        TrieNode(){
            EndOfWord = false;
            ChildCount = 0;
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
        }
    };

    TrieNode* Root;
    void insertNode(string word){
        TrieNode* node = Root;

        for(int i=0;i<word.length();i++){
            int idx = word[i] - 'a';
            if(node->children[idx] == nullptr){
                node->children[idx] = new TrieNode();
                node->ChildCount++;
            }

            node = node->children[idx];
        }
        node->EndOfWord = true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        // if the vector is empty OR there is only one string
        if(strs.empty()){
            return "";
        }
        if(strs.size() == 1){
            return strs[0];
        }

        Root = new TrieNode();

        for(string s:strs){
            // if there is any empty string
            if(s.length() == 0){
                return "";
            }
            insertNode(s);
        }

        string ans = "";

        TrieNode* temp = Root;
        while(temp != nullptr && temp->ChildCount == 1 && temp->EndOfWord != true){

            for(int i=0;i<26;i++){
                if(temp->children[i] != nullptr){
                    char ch = i + 'a';
                    ans += ch;
                    temp = temp->children[i];
                    break;
                }
            }
        }

        return ans;
    }
};