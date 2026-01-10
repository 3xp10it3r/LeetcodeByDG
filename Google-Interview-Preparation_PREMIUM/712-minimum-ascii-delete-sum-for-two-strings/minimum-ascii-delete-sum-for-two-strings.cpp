class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int getRemainingStringAscii(int index, string& s) {
        int ans = 0;
        for(int i = index; i < s.size(); i++) {
            ans += s[i];
        }
        return ans;
    }

    int rec(int i, int j, string& s1, string& s2) {
        if(i == n && j == m){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(i == n && j < m) return dp[i][j] = getRemainingStringAscii(j, s2);
        if(i < n && j == m) return dp[i][j] = getRemainingStringAscii(i, s1);
        
        if(s1[i] == s2[j]) {
            return dp[i][j] = rec(i+1, j+1, s1, s2);
        }

        return dp[i][j] = min(s1[i] + rec(i+1, j, s1, s2), s2[j] + rec(i, j+1, s1, s2));
    }

    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();

        dp = vector(n+1, vector<int>(m + 1, -1));
        return rec(0, 0, s1, s2);    
    }
};