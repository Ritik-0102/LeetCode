class Solution {
public:
    // A power of two in binary representation always consists of exactly one 1 bit followed by zeros. 
    // For example:
    // 2 is 0010
    // 4 is 0100
    // 8 is 1000
    
    // If you subtract 1 from a power of two, all the bits after the 1 flip to 1, and the original 1 flips to 0.
    // 8 - 1 = 7 (which is 0111)

    // When you perform a bitwise AND operation (&) between n and n - 1, it compares the bits. For a power of two, n & (n - 1) will always equal exactly 0
    
    bool isPowerOfTwo(int n) {
        return (n > 0) && (n & (n-1)) == 0;
    }
};