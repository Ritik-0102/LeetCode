class Solution {
public:
    void calc(stack<int>& s,string str){
        int n2 = s.top();
        s.pop();
        int n1 = s.top();
        s.pop();

        if(str == "+"){
            s.push(n1 + n2);
        }
        else if(str == "-"){
            s.push(n1 - n2);
        }
        else if(str == "*"){
            s.push(n1 * n2);
        }
        else if(str == "/"){
            s.push(n1 / n2);
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(string str:tokens){
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                calc(s,str);
            }
            else{
                s.push(stoi(str));
            }
        }

        return s.top();
    }
};