class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        int radius = 0;

        Arrays.sort(houses);
        Arrays.sort(heaters);

        int n = houses.length;
        int m = heaters.length;

        int j = 0;

        for(int i = 0 ; i < n ; i++){
            // Move to the next heater if it's closer or equally close
            while(j + 1 < m && Math.abs(heaters[j + 1] - houses[i]) <= Math.abs(heaters[j] - houses[i])){
                j++;
            }

            radius = Integer.max(radius,Math.abs(heaters[j] - houses[i]));
        }

        return radius;
    }
}