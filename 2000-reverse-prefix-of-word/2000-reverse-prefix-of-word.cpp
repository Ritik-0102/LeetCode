class Solution {
public:
    string reversePrefix(string s, char ch) {
        int idx = -1;

        for(int i=0;i<s.size();i++){
            if(s[i] == ch){
                idx = i;
                break;
            }
        }

        if(idx == -1){
            return s;
        }

        // Reverse with Two Pointer
        int left = 0, right = idx;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
};