class Solution {
public:
    
    int dp[301][27][27];
    
    int dist(int a, int b) {
        if(a == -1 || b == -1) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        
        return abs(x1-x2) + abs(y1-y2);
    }
    
    int helper(int level, int finger1, int finger2, string& word, int n) {
        if(level == n) return 0;
        
        if(dp[level][finger1 + 1][finger2 + 1] != -1) 
            return dp[level][finger1 + 1][finger2 + 1];
        
        // use finger 1
        
        int ch = word[level] - 'A';
        
        int cost1 = dist(finger1, ch) + helper(level + 1, ch, finger2, word, n);
        int cost2 = dist(finger2, ch) + helper(level + 1, finger1, ch, word, n);
        
        
        return dp[level][finger1 + 1][finger2 + 1]  = min(cost1, cost2);
        
    }
    
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        
        int n = word.size();
        
        return helper(0, -1, -1, word, n);
    }
};