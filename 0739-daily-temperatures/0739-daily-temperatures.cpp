class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // we will do this problem with the help of finding next greater element by Stack
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s; // to store next greater element idx

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && temperatures[i] >= temperatures[s.top()]){
                s.pop();
            }

            if(s.empty()){
                ans[i] = 0;
            }
            else{
                ans[i] = s.top() - i;
            }

            s.push(i);
        }

        return ans;
    }
};