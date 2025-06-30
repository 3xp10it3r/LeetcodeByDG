class Solution {
public:

    int dp[21][3010];
    int helper(int level, vector<int>& nums, int target) {
        if(level == nums.size()) {
            if(target == 0) return 1;
            else return 0;
        }

        if(level > nums.size()) return 0;

        if(dp[level][target + 1000] != -1) return dp[level][target + 1000];

        int ways = 0;

        ways += helper(level + 1, nums, target + nums[level]);

        ways += helper(level + 1, nums, target - nums[level]);

        return dp[level][target + 1000] = ways;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));

        return helper(0, nums, target);
    }
};