class Solution {
public:
    vector<vector<bool>> dp;

    // bool checkPalindrome(int i, int j, string& s) {
    //     if(i >= j) return true;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s[i] == s[j]){
    //         return dp[i][j] = checkPalindrome(i+1, j-1, s);
    //     }

    //     return dp[i][j] = false;
    // }

    string longestPalindrome(string s) {
        int n = s.size();

        dp = vector<vector<bool>>(n, vector<bool>(n, false));
        int mxLen = 0;
        int startIndex = -1;

        // for 1 length 
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
            mxLen = 1;
            startIndex = i;
        }

        // for 2 length 
        for(int i = 0; i + 1 < n; i++) {
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                mxLen = 2;
                startIndex = i;
            }
        }

        // for >= 3 length

        for(int len = 3; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if(s[i] == s[j] && dp[i + 1][j - 1]){
                    dp[i][j] = true;
                    if(len > mxLen) {
                        mxLen = len;
                        startIndex = i;
                    }
                }
            }
        }

        return s.substr(startIndex, mxLen);
    }
};