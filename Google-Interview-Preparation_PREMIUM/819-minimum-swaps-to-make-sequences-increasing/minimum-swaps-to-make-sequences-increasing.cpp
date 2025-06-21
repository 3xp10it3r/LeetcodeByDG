class Solution {
public:
    int dp[(int)1e5 + 7][2];
    int rec(int level, int isSwapped, vector<int>& nums1, vector<int>& nums2, int n) {
        if(level == n) return 0;
        
        if(dp[level][isSwapped] != -1) return dp[level][isSwapped]; 
        
        int prev1 = nums1[level - 1];
        int prev2 = nums2[level - 1];
        
        if(isSwapped) {
            swap(prev1, prev2);
        }
        
        int ans = INT_MAX;
        // no swap
        
        if(nums1[level] > prev1 && nums2[level] > prev2) {
            ans = rec(level + 1, 0, nums1, nums2, n);
        }
        
        // with swap
        
        if(nums1[level] > prev2 && nums2[level] > prev1) {
            ans = min(ans, 1 + rec(level + 1, 1, nums1, nums2, n));
        }
        
        return dp[level][isSwapped] = ans;
    }
    
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        memset(dp, -1, sizeof(dp));
        
        // no swap // swap
        return min(rec(1, 0, nums1, nums2, n), 1 + rec(1, 1, nums1, nums2, n));
    }
};