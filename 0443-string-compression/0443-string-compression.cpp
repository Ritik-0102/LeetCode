class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        for(int i=0;i<chars.size();i++){
            char ch = chars[i];
            int count = 0;
            while(i<chars.size() && ch == chars[i]){
                count++;
                i++;
            }

            if(count == 1){
                chars[idx] = ch;
                idx++;
            }
            else{
                chars[idx++] = ch;

                // convert our count to character array
                string count_arr = to_string(count);
                for(char elem:count_arr){
                    chars[idx++]=elem;
                }
            }

            i--;
        }
        
        return idx;
    }
};