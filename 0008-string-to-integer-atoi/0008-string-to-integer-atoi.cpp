class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        char sign = '+';

        int i = 0;
        int n = s.size();

        // remove whitespaces
        while(i<n && s[i] == ' '){
            i++;
        }

        // now check for sign
        if(i<n && s[i] == '-' ){
            sign = '-';
            i++;
        }
        else if(i<n && s[i] == '+'){
            i++;
        }

        while(i < n){
            // if it is a digit 
            if(isdigit(s[i])){

                if(ans > INT_MAX/10){
                    if(sign == '-'){
                        return INT_MIN;
                    }
                    return INT_MAX;
                }

                if(ans == INT_MAX/10 && (s[i] - '0') > 7){
                    if(sign == '-'){
                        return INT_MIN;
                    }
                    return INT_MAX;
                }

                ans = (ans * 10) + (s[i] - '0');
                i++;

            }
            
            else{
                break;
            }
        }

        if(sign == '-'){
            return -ans;
        }

        return ans;
    }
};