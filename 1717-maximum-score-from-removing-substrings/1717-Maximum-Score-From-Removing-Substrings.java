class Solution {
    int totalPoints = 0;

    String helper(String s,char first,char second,int point){
        StringBuilder stack = new StringBuilder();

        for(char ch : s.toCharArray()){
            int len = stack.length();
            if(len > 0 && stack.charAt(len - 1) == first && ch == second){
                stack.deleteCharAt(len - 1);
                totalPoints += point;
            }
            else{
                stack.append(ch);
            }
        }

        return stack.toString();
    }

    public int maximumGain(String s, int x, int y) {
        if(x >= y){
            s = helper(s,'a','b',x);
            helper(s,'b','a',y);
        }
        else{
            s = helper(s,'b','a',y);
            helper(s,'a','b',x);
        }

        return totalPoints;
    }
}