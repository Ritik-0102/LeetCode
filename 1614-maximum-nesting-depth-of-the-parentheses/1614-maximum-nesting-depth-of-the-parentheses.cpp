class Solution {
public:
    int maxDepth(string str) {
        int depth = 0;
        stack<char> s;

        for(char ch:str){
            if(ch == '('){
                s.push(ch);
                int currDepth = s.size();
                depth = max(depth,currDepth);
            }
            if(!s.empty() && ch == ')'){
                s.pop();
            }
        }

        return depth;
    }
};