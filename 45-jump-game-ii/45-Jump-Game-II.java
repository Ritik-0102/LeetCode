class Solution {
    public int jump(int[] nums) {
        int jumps = 0;
        int currentJump = 0;
        int maxReach = 0;

        for(int i=0; i < nums.length - 1; i++){
            maxReach = Math.max(maxReach,i + nums[i]);

            if(i == currentJump){
                jumps++;

                currentJump = maxReach;
            }
        }

        return jumps;
    }
}