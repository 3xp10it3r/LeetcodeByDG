class Solution {
public:
    bool queryString(string s, int n) {
        // Optimization: any number > 1024 can't be covered by s of length <= 1000
        int limit = min(n, 1024); 
        
        // For each number from 1 to limit
        for (int num = 1; num <= limit; ++num) {
            // Convert num to binary string
            string bin = toBinary(num);

            // Check if it exists in s
            if (s.find(bin) == string::npos) {
                return false; // if not found, return false
            }
        }

        // All numbers found
        return true;
    }

    // Helper: convert number to binary string
    string toBinary(int num) {
        string res;
        while (num > 0) {
            res = (char)('0' + (num % 2)) + res;
            num /= 2;
        }
        return res;
    }
};
