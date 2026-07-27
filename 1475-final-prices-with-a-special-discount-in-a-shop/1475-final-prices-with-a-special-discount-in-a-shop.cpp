class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // we will solve this by using a monotonic stack
        // we will find the next smaller element for prices

        int n = prices.size();

        vector<int> ans(n,0);
        stack<int> s;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && prices[i] < s.top()){
                s.pop();
            }
            if(!s.empty()){
                ans[i] = s.top();
            }
            s.push(prices[i]);
        }

        for(int i=0;i<n;i++){
            ans[i] = prices[i] - ans[i];
        }

        return ans;
    }
};