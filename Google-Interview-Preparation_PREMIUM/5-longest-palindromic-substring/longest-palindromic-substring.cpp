class Solution {
public:
    vector<vector<int>> dp;

    bool checkPalindrome(int i, int j, string& s) {
        if(i >= j) return true;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i]==s[j]){
            return dp[i][j] = checkPalindrome(i+1, j-1, s);
        }

        return dp[i][j] = false;
    }

    string longestPalindrome(string s) {
        int n = s.size();

        dp = vector<vector<int>>(n, vector<int>(n, -1));
        int mxLen = 0;
        int startIndex = -1;

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