class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        // An ant moving left from position x takes exactly x seconds to fall off the 0 edge
        int maxIdx = 0;
        for(int i:left){
            maxIdx = max(i,maxIdx);
        }

        // An ant moving right from position x takes exactly (n - x) seconds to fall off the n edge
        int minIdx = n;
        for(int i:right){
            minIdx = min(i,minIdx);
        }

        // we have two Cases :-
        // left ant falls off last OR the Right ant falls off last
        int leftAns = maxIdx;
        int rightAns = n - minIdx;

        return max(leftAns,rightAns);
    }
};