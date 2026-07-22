class Solution {
public:
    bool containsDuplicate(vector<int>& arr) {
        unordered_set<int> s;

        int n = arr.size();

        for(int i=0;i<n;i++){
            if(s.find(arr[i]) != s.end()){
                return true;
            }
            s.insert(arr[i]);
        }

        return false;
    }
};