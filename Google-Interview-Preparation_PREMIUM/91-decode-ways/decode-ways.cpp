class Solution {
public:
    int dp[105];
    int fun(int i, string& s) {
        if (i == s.size()) return 1;

        if (i > s.size()) return 0;

        if (dp[i] != -1) return dp[i];

        int ways = 0;

        if (s[i] - '0' > 0) ways += fun(i + 1, s);

        if (i + 1 < s.size()) {

            int number = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if (number >= 10 && number <= 26)
                ways += fun(i + 2, s);
        }
        
        return dp[i] = ways;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return fun(0, s);
    }
};