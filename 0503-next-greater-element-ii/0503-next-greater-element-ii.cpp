class Solution {
public:
    // so to find the next greater element in a circular array 
    // we need to traverse our array two times from back
    
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();

        vector<int> ans(n);
        stack<int> s;

        for(int i = 2*n-1 ; i >= 0 ; i--){
            while(!s.empty() && arr[i % n] >= s.top()){
                s.pop();
            }

            if(s.empty()){
                ans[i % n] = -1;
            }
            else{
                ans[i % n] = s.top();
            }
            s.push(arr[i % n]);
        }

        return ans;
    }
};