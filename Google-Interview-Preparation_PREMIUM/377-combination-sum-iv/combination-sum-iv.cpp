class Solution {
public:
    int dp[1001];

    int helper(int target, vector<int>& nums) {
        if(target == 0) return 1;

        if(dp[target] != -1) return dp[target];

        dp[target] = 0;

        for(auto &num : nums) {
            if(num <= target) {
                dp[target] += helper(target - num, nums);
            }
        }

        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));

        return helper(target, nums);
    }
};