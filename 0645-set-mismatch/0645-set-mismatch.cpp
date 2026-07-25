class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int repeated;
        set<int> s;

        int n = arr.size();

        for(int i:arr){
            if(s.find(i) != s.end()){
                repeated = i;
                break;
            }
            s.insert(i);
        }

        long long sum = 0;
        for(int i:arr){
            sum += i;
        }

        long long actualSum = (n * (n + 1))/2;

        int missing =  actualSum - sum + repeated;

        return {repeated,missing};
    }
};