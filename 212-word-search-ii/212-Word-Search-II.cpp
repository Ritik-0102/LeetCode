class Solution {
public:
    class TrieNode{
        public:
        TrieNode* children[26];
        string word; // used to store full word at the leaf node

        TrieNode(){
            word = "";
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
        }
    };

    void dfs(vector<vector<char>>& board,TrieNode* Curr,int i,int j,vector<string>& ans){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()){
            return;
        }

        char ch = board[i][j];

        if(ch == '#' || Curr->children[ch - 'a'] == nullptr){
            return;
        }

        Curr = Curr->children[ch - 'a'];

        // Mark as Visited
        board[i][j] = '#';

        // If we Found A Word
        if(Curr->word != ""){
            ans.push_back(Curr->word);
            Curr->word = ""; // Preventing Duplicates
        }


        dfs(board,Curr,i+1,j,ans);
        dfs(board,Curr,i-1,j,ans);
        dfs(board,Curr,i,j+1,ans);
        dfs(board,Curr,i,j-1,ans);

        // BackTrack : Restore the value
        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        TrieNode* Root = new TrieNode();
        vector<string> ans;
        
        // Build Trie
        for(string s:words){
            TrieNode* curr = Root;
            for(char ch:s){
                if(curr->children[ch - 'a'] == nullptr){
                    curr->children[ch - 'a'] = new TrieNode();
                }
                curr = curr->children[ch - 'a'];
            }
            // Store The Full word at the Leaf Node
            curr->word = s;
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(board,Root,i,j,ans);
            }
        }

        return ans;
    }
};