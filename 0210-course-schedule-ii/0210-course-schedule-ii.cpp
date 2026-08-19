class Solution {
public:
    void TopoSort(vector<vector<int>>& adj,int src,vector<int>& vis,stack<int>& s){
        vis[src] = 1;

        for(int v:adj[src]){
            if(!vis[v]){
                TopoSort(adj,v,vis,s);
            }
        }

        s.push(src);
    }

    bool isCycleDFS(vector<vector<int>>& adj,int src,vector<int>& vis,vector<int>& Rec_Stack){
        vis[src] = 1;
        Rec_Stack[src] = 1;

        for(int v:adj[src]){
            if(!vis[v]){
                if(isCycleDFS(adj,v,vis,Rec_Stack)){
                    return true;
                }
            }
            // If it is already visited & also exists in our Recursive path , then cycle exists
            else if(Rec_Stack[v]){
                return true;
            }
        }

        Rec_Stack[src] = 0;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> vis(numCourses,0);
        vector<int> Rec_Stack(numCourses,0);

        vector<int> ans;

        // check whether it is DAG or Not
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycleDFS(adj,i,vis,Rec_Stack)){
                    return ans;
                }
            }
        }

        vis.assign(numCourses,0);
        stack<int> s;

        // Now find the TopoLogical Sorted Order
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                TopoSort(adj,i,vis,s);
            }
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};