class Solution {
public:
    bool canEatBananas(vector<int>& piles , int h , int maxAllowedBananas){
        long long hours = 0;

        for(int i=0 ; i<piles.size() ; i++){
            hours += ceil( (double) piles[i] / maxAllowedBananas);
        }

        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1; // koko can eat 1 banana per hour (minimum possible speed)
        int max = 0; // This will store max of array (maximum possible speed)
        for(int i:piles){
            if(i > max){
                max = i;
            }
        }

        // Now we will apply Binary search on this range
        int ans = -1;
        while(min <= max){
            int mid = min + (max - min)/2;

            if(canEatBananas(piles,h,mid)){
                ans = mid;
                max = mid - 1;
            }
            else{
                min = mid + 1;
            }
        }

        return ans;
    }
};