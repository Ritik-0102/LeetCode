class Solution {
public:
    // Custom Comaprator for string number comparision
    class customCompare{
        public:
        // overLoaded function
        bool operator()(const string& a,const string& b){
            // If lengths are the same, compare lexicographically
            if(a.size() == b.size()){
                return a > b;
            }

            // Otherwise, the longer string is numerically larger
            return a.size() > b.size();
        }
    };

    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string , vector<string> , customCompare > pq;

        for(string& s:nums){
            pq.push(s);

            if(pq.size() > k){
                pq.pop();
            }
        }

        return pq.top();
    }
};