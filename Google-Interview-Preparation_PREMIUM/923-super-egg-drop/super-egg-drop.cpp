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
        int x1 = 1, x2 = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            int val1 = helper(n - mid, k);
            int val2 = helper(mid - 1, k - 1);

            if(val1 >= val2) {
                x1 = mid;
                low = mid + 1;
            } else {
                x2 = mid;
                high = mid - 1;
            }

            if(val1 == val2) {
                break;
            }
        }

        int val1 = 1 + max(helper(x1 - 1, k - 1) , helper(n - x1, k));
        int val2 = 1 + max(helper(x2 - 1, k - 1), helper(n - x2, k));

        return dp[n][k] = min(val1, val2);
    }

    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        if(k == 1) return n;

        return helper(n,k);
    }
};