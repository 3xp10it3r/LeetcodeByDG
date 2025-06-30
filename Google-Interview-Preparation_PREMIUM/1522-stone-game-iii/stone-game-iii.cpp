class Solution {
public:
    int dp[50010];
    int helper(int level, const vector<int>& stoneValue) {

        int n = stoneValue.size();
        
        if(level >= n) return 0;

        if(dp[level] != -1) return dp[level];

        int ans = -1e9;

        int sum = 0;

        for(int i = 0; i < 3; i++) {
            if(level + i < n) {
                sum += stoneValue[level + i];
                ans = max(ans, sum - helper(level + i + 1, stoneValue));
            }
        }

        return dp[level] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp, -1, sizeof(dp));

        int value = helper(0, stoneValue);

        if(value > 0) return "Alice";
        else if(value < 0) return "Bob";
        else return "Tie";
    }
};