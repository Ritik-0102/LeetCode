class Solution {
public:
    int getSum(int a, int b) {
        
        while(b != 0){
            int carry = (a & b) << 1;
            a = (a ^ b); // Find the Sum without Carry
            b = carry; // Set b to the carry to add it in the next iteration
        }

        return a;
    }
};