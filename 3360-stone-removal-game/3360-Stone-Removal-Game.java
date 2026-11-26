class Solution {
    public boolean canAliceWin(int n) {
        boolean ans = true;
        int stones = 10;
        int chance = 0;

        while(n >= stones){
            n -= stones;
            stones -= 1;
            chance = chance == 0 ? 1 : 0;
        }

        return chance == 1 ? true : false;
    }
}