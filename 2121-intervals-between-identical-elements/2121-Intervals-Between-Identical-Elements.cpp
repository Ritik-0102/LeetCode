class Solution {
public:
    using ll = long long;
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<ll> ans(n, 0);

        // idxCount maps a number to how many times we've seen it so far
        unordered_map<int, ll> idxCount;
        
        // idxSum maps a number to the sum of the indices where we've seen it so far
        unordered_map<int, ll> idxSum;

        // ==========================================
        // PASS 1: Left to Right
        // Calculate distances from the current element to all identical elements on its LEFT.
        // ==========================================
        for (int i = 0; i < n; i++) {
            ll sum = idxSum[arr[i]];
            ll count = idxCount[arr[i]];

            // The absolute difference formula |i - j| resolves to (i - j) 
            // because the current index 'i' is always strictly greater than 
            // all previously seen indices 'j'.
            // Distances = (i - j1) + (i - j2) ... = (count * i) - (sum of all left j's)
            ans[i] += (count * i) - sum;

            // Include current index in the running totals for future iterations
            idxSum[arr[i]] += i;
            idxCount[arr[i]] += 1;
        }

        // Clear the maps so we can reuse them for tracking elements to the right
        idxSum.clear();
        idxCount.clear();

        // ==========================================
        // PASS 2: Right to Left
        // Calculate distances from the current element to all identical elements on its RIGHT.
        // ==========================================
        for (int i = n - 1; i >= 0; i--) {
            ll sum = idxSum[arr[i]];
            ll count = idxCount[arr[i]];

            // The absolute difference formula |i - j| resolves to (j - i) 
            // because the current index 'i' is always strictly less than 
            // all previously seen indices 'j' (since we are moving backward).
            // Distances = (j1 - i) + (j2 - i) ... = (sum of all right j's) - (count * i)
            ans[i] += sum - (count * i);

            // Include current index in the running totals for future iterations
            idxSum[arr[i]] += i;
            idxCount[arr[i]] += 1;
        }

        return ans;
    }
};