class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> m;
        unordered_set<string> s;

        for(string i:banned){
            s.insert(i);
        }

        int i = 0;
        int n = paragraph.size();

        while(i<n){
            char ch = paragraph[i];

            if(!isalpha(ch)){
                i++;
            }
            else{
                string word = "";
                while(i<n && isalpha(paragraph[i])){
                    word += tolower(paragraph[i]);
                    i++;
                }

                m[word]++;
            }
        }

        int maxFreq = 0;
        string ans;

        for(auto elem:m){
            if(s.find(elem.first) == s.end()  &&  elem.second > maxFreq){
                ans = elem.first;
                maxFreq = elem.second;
            }
        }

        return ans;
    }
};