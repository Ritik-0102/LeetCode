class Solution {
public:
    string makeGood(string str) {
        stack<char> s;

        for(int i=0;i < str.size();i++){
            s.push(str[i]);
            if(s.size() >= 2){
                char ch1 = s.top();
                s.pop();
                char ch2 = s.top();
                s.pop();

                if(ch1 != ch2 && tolower(ch1) == tolower(ch2)){
                    continue;
                }
                else{
                    s.push(ch2);
                    s.push(ch1);
                }
            }
        }

        string ans = "";

        while(!s.empty()){
            ans += s.top();
            s.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};