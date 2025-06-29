class Solution {
public:
    int dp[101][101];
    vector<int> suffixSum;

    int helper(int level, int M,  vector<int>& piles) {
        if(level >= piles.size()) return 0;

        if(level + 2 * M >= piles.size()) return suffixSum[level];

        if(dp[level][M] != -1) return dp[level][M];

        int result = 0;

        for(int x = 1; x <= 2*M; x++) {
            result = max(result, 
                            suffixSum[level] - helper(level + x, max(M, x), piles));
        }

        return dp[level][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
        if(piles.empty()) return 0;

        memset(dp, -1, sizeof(dp));

        int n = piles.size();

        suffixSum.resize(n);

        suffixSum[n-1] = piles[n-1];

        for(int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        return helper(0, 1, piles);
    }
};