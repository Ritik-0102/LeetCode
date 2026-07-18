class Solution {
public:
    int scoreOfParentheses(string str) {
        stack<int> s;

        for(char ch:str){
            // Mark all the opening bracket score as 0
            if(ch == '('){
                s.push(0);
            }
            else{
                int innerScore = 0;

                // Sum up all calculated scores inside this current pair like '()()()'
                while(s.top() != 0){
                    innerScore += s.top();
                    s.pop();
                }

                s.pop();

                // if '()'
                if(innerScore == 0){
                    s.push(1);
                }
                // if '((()))'
                else{
                    s.push(innerScore * 2);
                }
            }
        }

        int finalScore = 0;
        // if the pair is like this '()()()'
        while(!s.empty()){
            finalScore += s.top();
            s.pop();
        }

        return finalScore;
    }
};