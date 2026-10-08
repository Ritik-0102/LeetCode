class Solution {
public:
    // Core Logic :-

    // s = "abadc"
    // Longest palindromic prefix: "aba"
    // Leftover suffix: "dc"
    // Reverse the leftover suffix (Culprit) ("dc") & put it in front: "cd" + "abadc" = "cdabadc"

    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());

        for(int i=0;i<s.size();i++){
            // find Longest Palindromic Prefix
            if(! memcmp(s.c_str() , rev.c_str() + i , s.size() - i)){
                return rev.substr(0,i) + s;
            }
        }

        return rev + s;
    }
};