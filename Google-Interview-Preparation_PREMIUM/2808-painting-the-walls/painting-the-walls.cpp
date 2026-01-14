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
        n = cost.size();
        dp = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        return rec(0, n, cost, time);
    }
};