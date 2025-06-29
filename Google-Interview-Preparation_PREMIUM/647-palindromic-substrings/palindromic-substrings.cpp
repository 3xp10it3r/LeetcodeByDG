class Solution {
public:
    int dp[1001][1001];
    bool isPalindrome(string& s, int i, int j) {
        if(i >= j) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = s[i] == s[j] ? isPalindrome(s, i + 1, j - 1): 0;
    }
    int countSubstrings(string s) {
        int count = 0;

        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                count += isPalindrome(s, i, j);
            }
        }

        return count;
    }
};

// O(n^2)