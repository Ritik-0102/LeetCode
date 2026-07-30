class Solution {
    public List<Integer> majorityElement(int[] arr) {
        int n = arr.length;

        List<Integer> ans = new ArrayList<>();
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            if (map.containsKey(arr[i])) {
                map.put(arr[i], map.get(arr[i]) + 1);
            } else {
                map.put(arr[i], 1);
            }
        }
        
        for(int key : map.keySet()){
            if(map.get(key) > n/3){
                ans.add(key);
            }
        }

        return ans;
    }
}