class Solution {
public:
    int strStr(string haystack, string needle) {
        // This is inbuilt function from STL
        // Approach 1:
        // return haystack.find(needle);

        // Approach 2: Sliding Window
        int n = haystack.size();
        int m = needle.size();

        for(int i=0;i<=n-m;i++){
            if(haystack.substr(i,m)==needle){
                return i;
            }
        }

        return -1;
    }
};