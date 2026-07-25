class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int ans = 0;

        int frontIdx = 0;

        while(tickets[k] != 0){
            if(tickets[frontIdx] > 0){
                tickets[frontIdx] -= 1;
                ans++;
            }
            frontIdx++;
            frontIdx %= n;
        }

        return ans;
    }
};