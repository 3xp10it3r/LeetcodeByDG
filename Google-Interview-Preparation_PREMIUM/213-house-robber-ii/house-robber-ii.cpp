class Solution {
public:

    vector<int> dp;

    int rec(int level, vector<int>& nums, int n) {
        if(level >= n) return 0;

        if(dp[level] != -1) return dp[level];

        return dp[level] = max(nums[level] + rec(level + 2, nums, n), rec(level + 1, nums, n));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp = vector(n + 1, -1);

        if (n == 1) return nums[0];

        int withoutLast = rec(0, nums, n-1);
        dp.assign(n, -1);
        return max(withoutLast, rec(1, nums, n));
    }
};