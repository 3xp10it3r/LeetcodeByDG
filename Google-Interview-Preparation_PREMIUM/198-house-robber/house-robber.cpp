class Solution {
public:
    int n;
    vector<int> dp;

    int rec(int level, vector<int>& nums) {
        if(level >= n) return 0;

        if(dp[level] != -1) return dp[level];

        return dp[level] = max(nums[level] + rec(level + 2, nums), rec(level + 1, nums));
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        dp = vector(n + 1, -1);

        return rec(0, nums);
    }
};