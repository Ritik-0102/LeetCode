class Solution {
public:
    int calculate(string str) {
        stack<int> s;
        int result = 0;
        int sign = 1; // 1 for (+)  & -1 for (-)

        int n = str.size();

        for(int i=0;i<n;i++){
            char ch = str[i];

            // case 1 : if it is a number
            if(isdigit(ch)){
                long long num = 0;
                while(i<n && isdigit(str[i])){
                    num = num*10 + (str[i] - '0');
                    i++;
                }

                // we need to decreament i because of outer for loop updation
                i--;

                result += (sign * num);
            }

            // case 2 : if it is a opening parenthesis
            else if(ch == '('){
                // we will push the current result & sign into stack
                s.push(sign);
                s.push(result);

                sign = 1;
                result = 0;
            }

            // case 3 : if it is a (+) sign
            else if(ch == '+'){
                sign = 1;
            }

            // case 4 : if it is a (-) sign
            else if(ch == '-'){
                sign = -1;
            }

            // case 5 : if it is a closing parenthesis
            else if(ch == ')'){
                // now we pop out our old result & sign from the stack
                int OldValue = s.top();
                s.pop();
                int OldSign = s.top();
                s.pop();

                result = OldValue + (OldSign * result);
            }
        }

        return result;
    }
};