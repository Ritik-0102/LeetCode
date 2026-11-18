class Solution {
public:
    void helper(int& n,vector<string>& ans,string& temp,int openParentheses,int closeParentheses){
        if(temp.size() == 2*n){
            ans.push_back(temp);
            return;
        }

        if(openParentheses < n){
            temp.push_back('(');
            helper(n,ans,temp, openParentheses + 1 , closeParentheses);
            temp.pop_back();
        }

        if(closeParentheses < openParentheses){
            temp.push_back(')');
            helper(n,ans,temp, openParentheses , closeParentheses + 1);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";

        int openParentheses = 0;
        int closeParentheses = 0;

        helper(n,ans,temp,openParentheses,closeParentheses);

        return ans;
    }
};