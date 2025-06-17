class Solution {
public:
    int dp[10010][101];

    int helper(int n, int k) {
        if(k == 1) 
            return n;
        
        if(n <= 0) return 0;
        
        if(dp[n][k] != -1) return dp[n][k];

        int ans = 1e9;

        int low = 1, high = n;
        int res = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            int broken = helper(mid - 1, k - 1);     // egg breaks
            int notBroken = helper(n - mid, k);      // egg doesn't break
            int temp = 1 + max(broken, notBroken);

            res = min(res, temp);

            if(broken < notBroken) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

            // if(val1 == val2) {
            //     break;
            // }
        }

        // int val1 = 1 + max(helper(x1 - 1, k - 1) , helper(n - x1, k));
        // int val2 = 1 + max(helper(x2 - 1, k - 1), helper(n - x2, k));

        return dp[n][k] = res;
    }

    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        if(k == 1) return n;

        return helper(n,k);
    }
};