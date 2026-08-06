class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        
        int n = path.size();
        int i = 0;

        while(i<n){
            // skip all the '/'
            while(i<n && path[i] == '/'){
                i++;
            }

            // now find the directory name
            string curr = "";
            while(i<n && path[i] != '/'){
                curr += path[i];
                i++;
            }

            // 1. Directory is empty OR current directory
            if(curr == "." || curr == ""){
                continue;
            }

            // 2. Directory points to parent dorectory
            else if(curr == ".."){
                if(!s.empty()) s.pop();
            }

            // 3. Directory is a valid directory
            else{
                s.push(curr);
            }
        }

        // if stack is empty we return root directory
        if(s.empty()){
            return "/";
        }

        string ans = "";
        while(s.size() > 0){
            // Manually add '/' before every directory name
            ans = "/" + s.top() + ans;
            s.pop();
        }

        return ans;
    }
};