class Solution {
public:
    int n;

    int helper(int index, int last_taken_index, vector<int>& nums, vector<vector<int>>& dp) {
        if(index >= n) return 0;

        if(dp[index][last_taken_index + 1] != -1) return dp[index][last_taken_index + 1];
        int take = -1e9;
        if(last_taken_index == -1 || nums[last_taken_index] < nums[index])
            take = 1 + helper(index + 1, index, nums, dp);

        int notTake = helper(index + 1, last_taken_index, nums, dp);



        return dp[index][last_taken_index + 1] = max(take, notTake);

    }
    

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return helper(0, -1, nums, dp);
    }
};