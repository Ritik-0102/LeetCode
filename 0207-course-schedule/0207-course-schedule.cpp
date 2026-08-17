class Solution {
public:
    bool isCycledfs(vector<vector<int>>& courses,int src,vector<bool>& vis,vector<bool>& Rec_stack){
        vis[src] = true;
        Rec_stack[src] = true;

        for(int v:courses[src]){
            if(vis[v] == false){
                if(isCycledfs(courses,v,vis,Rec_stack)){
                    return true;
                }
            }
            // if it is already visited & exists in our curr recursive path ,then cycle exists
            else if(vis[v] == true && Rec_stack[v] == true){
                return true;
            }
        }

        // BackTracking
        Rec_stack[src] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses);

        vector<bool> vis(numCourses,false);
        vector<bool> Rec_stack(numCourses,false);

        for(auto& pre:prerequisites){
            courses[pre[1]].push_back(pre[0]);
        }

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycledfs(courses,i,vis,Rec_stack)){
                    return false;
                }
            }
        }

        return true;
    }
};