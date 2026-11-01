class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size()){
            return s;
        }

        vector<string> rows(numRows);

        bool direction = false;
        int curr = 0;

        for(char& c:s){
            rows[curr] += c;

            // Reverse the direction
            if(curr == 0 || curr == numRows - 1){
                direction = !direction;
            }

            curr += direction ? 1 : -1;
        }

        string ans = "";

        for(string &row:rows){
            ans += row;
        }

        return ans;
    }
};