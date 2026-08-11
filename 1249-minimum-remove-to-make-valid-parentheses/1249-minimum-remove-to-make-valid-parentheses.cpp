class Solution {
public:
    string minRemoveToMakeValid(string str) {
        int n = str.size();

        stack<int> s;

        for(int i=0;i<n;i++){
            if(str[i] == '('){
                s.push(i);
            }
            else if(str[i] == ')'){
                if(s.size() > 0){
                    s.pop();
                }
                else{
                    str[i] = '*';
                }
            }
        }

        while(!s.empty()){
            str[s.top()] = '*';
            s.pop();
        }


        string ans = "";
        for(int i=0;i<n;i++){
            if(str[i] != '*'){
                ans += str[i];
            }
        }

        return ans;
    }
};