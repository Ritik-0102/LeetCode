class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10){
            return {};
        }
        
        unordered_set<string> seen;
        unordered_set<string> ans;

        for(int i=0 ; i <= s.size() - 10 ; i++){
            string DNA = s.substr(i,10);

            // if we already seen this DNA , then add to our ans
            if(seen.find(DNA) != seen.end()){
                ans.insert(DNA);
            }
            else{
                seen.insert(DNA);
            }
        }

        // Convert set to Vector
        return vector<string>(ans.begin(),ans.end());
    }
};