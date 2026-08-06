class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> s;
        queue<int> q;

        for(int i=sandwiches.size()-1;i>=0;i--){
            s.push(sandwiches[i]);
        }

        int wantsCircular = 0;
        int wantsSquare = 0;
        for(int i:students){
            if(i == 0){
                wantsCircular++;
            }
            else{
                wantsSquare++;
            }
            q.push(i);
        }

        while(!q.empty()){
            // If any time No one wants the top sandwich , we break out from the loop
            if(s.top() == 0 && wantsCircular == 0){
                break;
            }
            if(s.top() == 1 && wantsSquare == 0){
                break;
            }

            // if the student wants the top most sandwich , then pop from stack & queue
            if(s.top() == q.front()){
                if(q.front() == 0){
                    wantsCircular--;
                }
                else{
                    wantsSquare--;
                }
                s.pop();
                q.pop();
            }
            // if the student don't want the top sandwich ,remove from front and move it to the end
            else{
                q.push(q.front());
                q.pop();
            }
        }

        return q.size();
    }
};