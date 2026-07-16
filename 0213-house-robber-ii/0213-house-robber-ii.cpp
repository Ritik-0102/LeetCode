class Solution {
public:
    // house robber 1 : logic
    int helper(vector<int>& arr , int start , int end){
        int prev1 = arr[start];
        int prev2 = max(arr[start],arr[start+1]);
        int result = prev2;

        for(int i=start+2;i<end;i++){
            result = max(prev2 , prev1 + arr[i]);
            prev1 = prev2;
            prev2 = result;
        }

        return result;
    }

    // we have two choice in this question :-
    // if we choose the 1st house to rob then we need to leave the last house 
    // otherwise we can leave the 1st house & do rob other houses as per the previous approach
    int rob(vector<int>& arr) {
        int n = arr.size();

        if(n==1){
            return arr[0];
        }
        if(n==2){
            return max(arr[0],arr[1]);
        }

        int choice1 = helper(arr,0,n-1);
        int choice2 = helper(arr,1,n);

        return max(choice1 , choice2);
    }
};