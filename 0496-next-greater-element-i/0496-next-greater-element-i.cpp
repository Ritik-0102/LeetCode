class Solution {
public:
    // first we will find the next greater element of all the elements in nums2 
    // Then map these elements with their next greater element
    // so that we can find the next greater element directly from there

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        
        unordered_map<int,int> m;
        stack<int> s;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums2[i] >= s.top()){
                s.pop();
            }

            if(s.empty()){
                m[nums2[i]] = -1;
            }
            else{
                m[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }

        vector<int> ans;
        for(int i:nums1){
            ans.push_back(m[i]);
        }

        return ans;
    }
};