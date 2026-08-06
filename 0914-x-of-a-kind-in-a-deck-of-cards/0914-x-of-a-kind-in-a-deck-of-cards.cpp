class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> m;

        // calculate the frequency of elements
        for(int i:deck){
            m[i]++;
        }

        // now calculate the group size
        int x = 0;
        for(auto p:m){
            x = gcd(x,p.second);
        }

        // now validate the groups
        for(auto p:m){
            if(x < 2 || p.second % x != 0){
                return false;
            }
        }

        return true;
    }
};