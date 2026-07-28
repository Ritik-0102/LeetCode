class Solution {
public:
    // we will solve this by Greedy Approach
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j=0;

        for(int i:pushed){
            // push the curr element
            s.push(i);

            // pop the elements
            while(!s.empty() && j<popped.size() && s.top() == popped[j]){
                s.pop();
                j++;
            }
        }

        return s.empty();
    }
};