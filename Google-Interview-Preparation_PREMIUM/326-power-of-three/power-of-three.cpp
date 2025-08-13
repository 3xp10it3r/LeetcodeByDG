class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0; // 3^19 largest power of 3 such that it is inside integer.
    }
};
