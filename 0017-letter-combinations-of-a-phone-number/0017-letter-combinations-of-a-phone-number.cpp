class Solution {
public:
    void helper(vector<string>& keypad,vector<string>& ans,string& digits,int idx,string& temp){
        if(idx == digits.size()){
            ans.push_back(temp);
            return;
        }

        int digit = digits[idx] - '0';

        for(int i=0;i<keypad[digit].size();i++){
            temp.push_back(keypad[digit][i]);
            helper(keypad,ans,digits,idx+1,temp);
            // Backtrack
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }

        vector<string> keypad = {" ","00","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string temp = "";

        helper(keypad,ans,digits,0,temp);

        return ans;
    }
};