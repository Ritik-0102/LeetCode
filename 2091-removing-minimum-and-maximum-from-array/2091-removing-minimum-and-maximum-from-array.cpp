class Solution {
public:
    int minimumDeletions(vector<int>& arr) {
        int n=arr.size();
        // if there are only 1 Or 2 elements 
        if(n <= 2){
            return n;
        }

        int Ans = INT_MAX; // Final ans

        int minIdx = 0;
        int maxIdx = 0;
        for(int i=0 ; i<n ; i++){
            if(arr[i] < arr[minIdx]){
                minIdx = i;
            }
            if(arr[i] > arr[maxIdx]){
                maxIdx = i;
            }
        }

        // Case 1 : when we are removing elements from left
        if(minIdx < maxIdx){
            Ans = min(Ans, maxIdx + 1);
        }
        else{
            Ans = min(Ans, minIdx + 1);
        }


        // Case 2 : when we are removing elements from right
        if(minIdx < maxIdx){
            Ans = min(Ans, n - minIdx);
        }
        else{
            Ans = min(Ans, n - maxIdx);
        }

        // Case 3 : when we removing elements from both side
        if(minIdx < maxIdx){
            Ans = min(Ans, (minIdx + 1) + (n - maxIdx));
        }
        else{
            Ans = min(Ans, (maxIdx + 1) + (n - minIdx));
        }
        
        return Ans;
    }
};