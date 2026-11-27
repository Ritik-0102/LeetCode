class Solution {
    public String frequencySort(String s) {
        Character[] chars = new Character[s.length()];
        int freq[] = new int[256];

        for(int i=0;i < s.length() ; i++){
            char ch = s.charAt(i);
            freq[ch]++;
            chars[i] = ch;
        }

        Arrays.sort(chars,(a,b) -> {
            if (freq[b] != freq[a]) {
                return freq[b] - freq[a]; // Higher frequency first
            }
            return a - b; // Group identical characters when frequencies tie
        });

        StringBuilder sb = new StringBuilder();
        for(char c:chars){
            sb.append(c);
        }

        return sb.toString();
    }
}