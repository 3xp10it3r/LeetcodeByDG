class Solution {
public:
    // vector<int> dp;
    // int n;

    // int rec(int level, vector<int>& nums) {
    //     if(level == n-1) return 0;
    //     if(level > n-1) return 1e9;

    //     if(dp[level] != -1) return dp[level];

    //     int ans = 1e9;
    //     for(int i = 1; i <= nums[level]; i++) {
    //         ans = min(ans, 1 + rec(level + i, nums));
    //     }

    //     return dp[level] = ans;
    // }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 1e9);

        dp[n - 1] = 0; // at last index already there;

        for(int i = n - 2; i >= 0; i--) {

            for(int j = 1; j <= nums[i]; j++) {
                if(i + j < n) {
                    dp[i] = min(dp[i], 1 + dp[i + j]);
                }
            }
        }

        return dp[0];
    }
};