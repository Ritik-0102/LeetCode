class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a; // It appears Twice

        int sum = 0;
        unordered_set<int> s;
        int n = grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                }
                else{
                    sum += grid[i][j];
                    s.insert(grid[i][j]);
                }                
            }
        }

        int expectedSum = ((n*n) * ((n*n) + 1 ))/2;

        int b = expectedSum - sum; // It is missing value

        return {a,b};
    }
};