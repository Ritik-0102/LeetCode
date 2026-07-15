class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMaxHeight(n,0);
        vector<int> RightMaxHeight(n,0);

        leftMaxHeight[0] = height[0];
        for(int i=1;i<n;i++){
            leftMaxHeight[i] = max(leftMaxHeight[i-1],height[i]);
        }

        RightMaxHeight[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            RightMaxHeight[i] = max(RightMaxHeight[i+1],height[i]);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            ans += min(leftMaxHeight[i],RightMaxHeight[i]) - height[i];
        }

        return ans;
    }
};