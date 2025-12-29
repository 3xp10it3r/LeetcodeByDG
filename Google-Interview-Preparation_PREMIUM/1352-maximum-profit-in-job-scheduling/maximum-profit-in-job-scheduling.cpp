class Solution {
public:
    int helper(int index, vector<vector<int>>& v, vector<int>& dp) {
        if(index >= v.size()) return 0;

        if(dp[index] != -1) return dp[index];

        int nextIndex = lower_bound(v.begin() + index, v.end(), vector<int>{v[index][1], -1, -1}) - v.begin();
        return dp[index] = max(helper(index + 1, v, dp), v[index][2] + helper(nextIndex, v, dp));
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        // {startTime, endTime, Profit}

        int n = profit.size();

        for(int i = 0; i < n; i++) {
            v.push_back({ startTime[i], endTime[i], profit[i]});
        }

        sort(v.begin(), v.end());

        vector<int> dp(n, -1);

        return helper(0, v, dp);
    }
};