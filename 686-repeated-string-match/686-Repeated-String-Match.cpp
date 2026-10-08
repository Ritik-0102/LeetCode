class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if(b.size() == 0){
            return 0;
        }

        if(a == b || a.find(b) != string :: npos){
            return 1;
        }

        string s = a;
        int repeat = 1;

        while(s.size() < b.size()){
            s += a;
            repeat++;
        }

        // Check if 'b' is a substring of the repeated string
        if(s.find(b) != string :: npos){
            return repeat;
        }

        s += a;

        // Check if 'b' is a substring of the repeated string
        if(s.find(b) != string :: npos){
            return repeat+1;
        }

        return -1;
    }
};