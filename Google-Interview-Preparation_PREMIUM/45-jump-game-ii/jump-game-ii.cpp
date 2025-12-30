class Solution {
public:
    vector<int> dp;
    int n;

    int rec(int level, vector<int>& nums) {
        if(level == n-1) return 0;
        if(level > n-1) return 1e9;

        if(dp[level] != -1) return dp[level];

        int ans = 1e9;
        for(int i = 1; i <= nums[level]; i++) {
            ans = min(ans, 1 + rec(level + i, nums));
        }

        return dp[level] = ans;
    }

    int jump(vector<int>& nums) {
        n = nums.size();
        dp = vector(n + 1, -1);

        return rec(0, nums);
    }
};