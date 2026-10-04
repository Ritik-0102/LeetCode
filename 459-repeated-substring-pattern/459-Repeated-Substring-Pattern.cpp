class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // s is made of a repeating pattern (e.g., s = P + P), 
        // doubling the string gives you s + s = P + P + P + P.
        // If you remove the very first and very last characters of s + s
        // middle P + P pattern is always intact
        // Then if we still have s in that doubled string then it is of Repeated Pattern

        string doubled = s + s;

        doubled = doubled.substr(1,doubled.size() - 2);

        return doubled.find(s) != string :: npos;
    }
};