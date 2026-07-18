class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;

        for(int i:gas){
            totalGas += i;
        }
        for(int i:cost){
            totalCost += i;
        }

        // if we don't have feasable gas to do journey
        if(totalCost > totalGas){
            return -1;
        }
        
        int n=gas.size();
        int startIdx = 0;
        int currGas = 0;
        for(int i=0;i<n;i++){
            currGas += gas[i] - cost[i];

            // If we run out of gas, this start index fails
            if(currGas < 0){
                currGas = 0; // Reset the curr gas to 0 
                startIdx = i+1; // Try the next station
            }
        }

        return startIdx;
    }
};