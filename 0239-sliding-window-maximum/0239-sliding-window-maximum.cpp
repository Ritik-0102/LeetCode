class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq; // to store curr window elements
        vector<int> ans; // to store the max of every windows

        // solve for 1st Window
        for(int i=0;i<k;i++){
            while(!dq.empty() && arr[i] >= arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // Now solve for other windows
        for(int i=k;i<n;i++){
            ans.push_back(arr[dq.front()]);

            // Remove the elements which does not belongs to the curr window
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            // Remove all the elements less than the curr element from the deque
            while(!dq.empty() && arr[i] >= arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        ans.push_back(arr[dq.front()]);

        return ans;
    }
};