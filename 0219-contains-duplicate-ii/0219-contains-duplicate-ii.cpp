class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> m;

        for(int i=0;i<n;i++){

            // if we have the element already present in map
            if(m.find(arr[i]) != m.end()){

                // then we check its diff between idx
                if(abs(i - m[arr[i]]) <= k){
                    return true;
                }
            }
            
            // insert element with its idx
            m[arr[i]] = i;
        }

        return false;
    }
};