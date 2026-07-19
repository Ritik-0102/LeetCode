class Solution {
public:

    // we will solve this question like 
    // we will iterate over the all the heights & we will find area for each height individually
    // By taking the height constant & we need to figure out our width
    // height[i] * width
    // width -> next smaller element idx - previous smaller element idx - 1;

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> prev_Smaller(n,0);
        vector<int> next_Smaller(n,0);

        stack<int> s;

        // Find all prev Smaller element idx
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[i] <= heights[s.top()]){
                s.pop();
            }

            if(s.empty()){
                prev_Smaller[i] = -1;
            }
            else{
                prev_Smaller[i] = s.top();
            }
            s.push(i);
        }

        // clear the stack
        while(!s.empty()){
            s.pop();
        }

        // Find all next Smaller element idx
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[i] <= heights[s.top()]){
                s.pop();
            }

            if(s.empty()){
                next_Smaller[i] = n;
            }
            else{
                next_Smaller[i] = s.top();
            }
            s.push(i);
        }

        // now calculate area
        int maxArea = 0;

        for(int i=0;i<n;i++){
            int area = heights[i] * (next_Smaller[i] - prev_Smaller[i] - 1);
            maxArea = max(area,maxArea);
        }

        return maxArea;
    }
};