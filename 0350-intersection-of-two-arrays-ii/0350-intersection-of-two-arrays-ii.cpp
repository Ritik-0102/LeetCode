class Solution {
public:
    vector<int> intersect(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> freq1;
        map<int,int> freq2;

        vector<int> ans;

        for(int i:arr1){
            freq1[i]++;
        }
        for(int i:arr2){
            freq2[i]++;
        }

        for(auto i:freq1){
            int n = min(freq1[i.first],freq2[i.first]);
            for(int j=0;j<n;j++){
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};