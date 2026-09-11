class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> ans;

        for(int i=0;i<n;i++){
            // Leading Zeroes
            if(digits[i] == 0){
                continue;
            }
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    // check distinct indices & even number condition
                    if( i != j && j != k && k != i && digits[k] % 2 == 0){
                        int a = digits[i];
                        int b = digits[j];
                        int c = digits[k];
                        
                        ans.insert(a*100 + b*10 + c);
                    }
                }
            }
        }

        return ans.size();
    }
};