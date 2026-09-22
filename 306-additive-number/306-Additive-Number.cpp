class Solution {
public:
    // Helper function because C++ integers crash if the number has more than 19 digits
    string addStrings(string a, string b) {
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            
            result.push_back((sum % 10) + '0'); // Add the last digit to result
            carry = sum / 10;                   // Carry over the rest
        }
        
        reverse(result.begin(), result.end());
        return result;
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();
        
        // i is the end position of the FIRST number
        for (int i = 1; i < n; i++) {
            
            // j is the end position of the SECOND number
            for (int j = i + 1; j < n; j++) {
                
                // Extract the first and second numbers from the string
                string num1 = num.substr(0, i);        // from index 0 to i
                string num2 = num.substr(i, j - i);    // from index i, length is (j - i)
                
                // RULE: No leading zeros allowed (unless the number is exactly "0")
                if ((num1.size() > 1 && num1[0] == '0') || 
                    (num2.size() > 1 && num2[0] == '0')) {
                    continue; // Skip this pair and try the next one
                }
                
                // Now, let's see if this pair works for the rest of the string
                string current1 = num1;
                string current2 = num2;
                int k = j; // k is our current position in the main string
                
                // Keep generating the next number as long as we haven't reached the end
                while (k < n) {
                    // Add the two numbers together
                    string next_sum = addStrings(current1, current2);
                    
                    // Does the rest of the string start with our new sum?
                    // num.substr(k, next_sum.size()) grabs the next chunk of the string to compare
                    if (num.substr(k, next_sum.size()) != next_sum) {
                        break; // It doesn't match. This pair failed.
                    }
                    
                    // It matched! Move our position 'k' forward by the length of the sum
                    k += next_sum.size();
                    
                    // Shift our numbers for the next round (num1 becomes num2, num2 becomes sum)
                    current1 = current2;
                    current2 = next_sum;
                }
                
                // If 'k' made it perfectly to the end of the string, we found a valid sequence!
                if (k == n) {
                    return true;
                }
            }
        }
        
        return false; // We tried every possible pair and none worked
    }

};