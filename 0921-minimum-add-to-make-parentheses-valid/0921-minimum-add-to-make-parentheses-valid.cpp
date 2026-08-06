class Solution {
public:
    int minAddToMakeValid(string str){
        stack<char> s;
        int ans = 0;

        for(char ch:str){
            if(ch == '('){
                s.push('(');
            }
            if(ch == ')'){
                if(s.empty() || s.top() != '('){
                    ans++;
                }
                else{
                    s.pop();
                }
            }
        }

        return ans + s.size();
    }
};