class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> t1;

        for(char ch:s){
            if(ch != '#'){
                s1.push(ch);
            }
            else if(!s1.empty()){
                s1.pop();
            }
        }
        for(char ch:t){
            if(ch != '#'){
                t1.push(ch);
            }
            else if(!t1.empty()){
                t1.pop();
            }
        }

        while(s1.size() > 0 && t1.size() > 0){
            if(s1.top() == t1.top()){
                s1.pop();
                t1.pop();
            }
            else{
                break;
            }
        }

        return s1.size() == 0 && t1.size() == 0;
    }
};