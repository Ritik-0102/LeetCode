class Solution {
public:
    string removeOccurrences(string s, string part) {
        // we will find if there is any part present in our string & erase it 
        // we will do this till we find the part in our string
        while(s.find(part) < s.size()){
            s.erase(s.find(part),part.size());
        }

        return s;
    }
};