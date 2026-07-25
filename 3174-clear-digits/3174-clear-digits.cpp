class Solution {
public:
    string clearDigits(string s) {
        vector<char> ans;

        for(char ch:s){
            if(isdigit(ch)){
                ans.pop_back();
            }
            else{
                ans.push_back(ch);
            }
        }

        string temp = "";
        for(char ch:ans){
            temp += ch;
        }

        return temp;
    }
};