class Solution {
public:
    bool isPalindrome(const string& s , int i , int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
                
        string longest = s.substr(0, 1); // At least the first character is a palindrome

        for(int i=0;i<n;i++){
            for(int j = n-1 ; j >= i ; j--){
                if(isPalindrome(s,i,j)){
                    if(j - i + 1 > longest.size()) {
                        longest = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return longest;
    }
};