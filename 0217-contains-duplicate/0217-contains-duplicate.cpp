class Solution {
public:
    bool containsDuplicate(vector<int>& arr) {
        unordered_map<int,int> m;

        int n = arr.size();

        for(int i=0;i<n;i++){
            m[arr[i]]++;
        } 

        for(int i=0;i<n;i++){
            if(m[arr[i]] > 1){
                return true;
            }
        }

        return false;
    }
};