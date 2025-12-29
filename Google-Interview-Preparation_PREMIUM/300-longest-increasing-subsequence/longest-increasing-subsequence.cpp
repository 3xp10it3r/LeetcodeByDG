class Solution {
public:
    int n;

    int helper(int index, vector<int>& nums, vector<int>& dp) {
        if(index < 0) return 0;

        if(dp[index] != -1) return dp[index];

        int ans = 1;

        for(int prevTaken = 0; prevTaken < index; prevTaken++){
            if(nums[prevTaken] < nums[index]) {
                ans = max(ans, 1 + helper(prevTaken, nums, dp));
            }
        }

        return dp[index] = ans;
    }
    

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n+1, -1);

        int longest = 1;
        for(int i = 0; i < n; i++) {
            longest = max(longest, helper(i, nums, dp));
        }

        return longest;
    }
};