class Solution {
    // Core Logic :-

    // s = "abadc"
    // Longest palindromic prefix: "aba"
    // Leftover suffix: "dc"
    // Reverse the leftover suffix (Culprit) ("dc") & put it in front: "cd" + "abadc" = "cdabadc"

    public String shortestPalindrome(String s) {
        int n = s.length();
        String rev = new StringBuilder(s).reverse().toString();

        for(int i=0;i<n;i++){
            // find Longest Palindromic Prefix
            if((s.substring(0,n - i)).equals(rev.substring(i))){
                return rev.substring(0,i) + s;
            }
        }

        return rev + s;
    }
}