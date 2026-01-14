class Solution {
public:
    int n = 0;

    vector<vector<int>> dp;

    int rec(int i, int noOfWallsRemaining, vector<int>& cost, vector<int>& time) {
        if(noOfWallsRemaining <= 0)
            return 0;

        if(i == n)
            return 1e9;

        if(dp[i][noOfWallsRemaining] != -1) 
            return dp[i][noOfWallsRemaining];

        int take = cost[i] + rec(i+1, noOfWallsRemaining - (time[i] + 1), cost, time);
        int notTake = rec(i+1, noOfWallsRemaining, cost, time);

        return dp[i][noOfWallsRemaining] = min(take, notTake);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 1e9));

        for (int i = 0; i <= n; i++) dp[i][0] = 0;

        for(int i = n; i >= 0; i--) {
            for(int noOfWallsRemaining = 1; noOfWallsRemaining <= n; noOfWallsRemaining++) {
                if(i == n) {
                    dp[i][noOfWallsRemaining] = 1e9;
                    continue;
                }
                if(noOfWallsRemaining == 0) {
                    dp[i][noOfWallsRemaining] = 0;
                    continue;
                }

                int next = max(0, noOfWallsRemaining - (1 + time[i]));

                dp[i][noOfWallsRemaining] = min(cost[i] + dp[i+1][next], dp[i+1][noOfWallsRemaining]);
            }
        }

        return dp[0][n];

        // return rec(0, n, cost, time);
    }
};