class Solution {
public:
    int dp[1001][1001];
    bool checkPalindrome(int i, int j, string& s) {
        if(i >= j) return dp[i][j] = true;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j])
            return dp[i][j] = checkPalindrome(i+1, j-1, s);
        
        return dp[i][j] = false;
    }

    string longestPalindrome(string s) {
        int n = s.size();

        memset(dp, -1, sizeof(dp));

        int mxLen = 0, startIndex = -1;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(checkPalindrome(i, j, s)) {
                    if(mxLen < j - i + 1) {
                        mxLen = j - i + 1;
                        startIndex = i;
                    }
                }
            }
        }

        return s.substr(startIndex, mxLen);
    }
};