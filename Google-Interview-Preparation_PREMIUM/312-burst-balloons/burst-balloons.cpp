class Solution {
public:

    int rec(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {

        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mx = 0;

        for(int k = i; k <= j; k++) {
            int burst = nums[k] * nums[i-1] * nums[j+1] + rec(i, k-1, nums, dp) + rec(k + 1, j, nums, dp);
            mx = max(mx, burst);
        }

        return dp[i][j] = mx;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return rec(1, n - 2, nums, dp);
    }
};