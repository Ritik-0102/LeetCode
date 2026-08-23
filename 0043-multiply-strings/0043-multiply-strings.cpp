class Solution {
public:
    string multiply(string arr1, string arr2) {
        if(arr1 == "0" || arr2 == "0"){
            return "0";
        }

        int n = arr1.size();
        int m = arr2.size();

        vector<int> res(m+n,0);

        for(int i=n-1 ; i>=0 ; i--){
            for(int j=m-1 ; j>=0 ; j--){
                int temp = (arr1[i] - '0') * (arr2[j] - '0');

                // Add previous carries
                temp += res[i+j+1];

                res[i+j+1] = temp % 10;

                // add carry at i+j position
                res[i+j] += temp / 10;
            }
        }

        string ans = "";
        for(int i:res){
            // Remove leading zeroes
            if(!(ans.empty() && i == 0)){
                ans += (i + '0');
            }
        }

        return ans;
    }
};