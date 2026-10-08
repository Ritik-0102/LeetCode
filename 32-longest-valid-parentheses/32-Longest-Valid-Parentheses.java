class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();
        int ans = 0;

        int open = 0;
        int close = 0;

        // Traverse Left to Right
        for(int i=0;i<n;i++){
            if(s.charAt(i) == '('){
                open++;
            }
            else{
                close++;
            }

            if(open == close){
                ans = Integer.max(ans,open + close);
            }

            if(close > open){
                open = 0;
                close = 0;
            }
        }

        open = 0;
        close = 0;

        // Traverse Right to Left
        for(int i=n-1 ; i >= 0 ; i--){
            if(s.charAt(i) == '('){
                open++;
            }
            else{
                close++;
            }

            if(open == close){
                ans = Integer.max(ans,open + close);
            }

            if(open > close){
                open = 0;
                close = 0;
            }
        }

        return ans;
    }
}