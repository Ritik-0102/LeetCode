class WordDictionary {
public:
    class TrieNode{
        public:
        bool EndOfWord;
        TrieNode* children[26];

        TrieNode(){
            EndOfWord = false;
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for(int i=0;i<word.size();i++){
            char ch = word[i];
            int idx = ch - 'a';

            if(curr->children[idx] == nullptr){
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }
        curr->EndOfWord = true;
    }

    bool searchHelper(string word,int idx,TrieNode* curr){
        if(idx == word.size()){
            return curr->EndOfWord;
        }

        char ch = word[idx];

        // WildCard character 
        // we will search for all 26 characters
        if(ch == '.'){
            for(int i=0;i<26;i++){
                if(curr->children[i] != nullptr){
                    if(searchHelper(word,idx+1,curr->children[i])){
                        return true;
                    }
                }
            }
        }
        else{
            int i = ch - 'a';
            if(curr->children[i] == nullptr){
                return false;
            }
            return searchHelper(word,idx+1,curr->children[i]);
        }

        return false;
    }
    
    bool search(string word) {
        return searchHelper(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */