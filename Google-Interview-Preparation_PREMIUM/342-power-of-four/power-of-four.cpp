class Solution {
public:
    bool isPowerOfFour(int n) {
        bitset<31> bits(n);

        if(n <= 0 || bits.count() != 1) return 0;

        for(int i = 0; i < 31; i+=2) {
            if(bits[i]) return 1;
        }

        return 0;
    }
};