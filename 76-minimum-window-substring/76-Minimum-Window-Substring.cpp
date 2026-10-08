class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128,0);

        for(char ch:t){
            freq[ch]++;
        }

        int target_Size = t.size();
        int start = 0;
        int minLength = INT_MAX;

        int left = 0;
        int right = 0;

        // Expand the window
        while(right < s.size()){
            // it is needed character , so decrease target size of window
            if(freq[s[right]] > 0){
                target_Size--;
            }

            freq[s[right]]--;
            right++;

            // Shrink the Window
            while(target_Size == 0){
                // check for minimum Window
                if((right - left) < minLength){
                    minLength = right - left;
                    start = left;
                }

                // Remove the unnecessary characters
                freq[s[left]]++;

                // if we removed character which is needed actually , so we need to extend the window
                if(freq[s[left]] > 0){
                    target_Size++;
                }

                left++;
            }
        }

        return minLength == INT_MAX ? "" : s.substr(start,minLength);
    }
};