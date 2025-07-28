class Solution {
public:
    int digits(int n) {
        int sum = 0, mul = 1;
        while(n) {
            int d = n % 10;

            sum += d;
            mul *= d;

            n/=10;
        }

        return sum + mul;
    }

    bool checkDivisibility(int n) {
        return (n%digits(n) == 0);
    }
};