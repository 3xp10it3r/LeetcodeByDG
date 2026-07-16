class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixMax;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i==0) prefixMax.push_back(nums[i]);
            else prefixMax.push_back(max(prefixMax[i-1], nums[i]));
        }
        vector<int> prefixGcd(n);
        for(int i = 0; i < n; i++) {
            prefixGcd[i] = __gcd(nums[i], prefixMax[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        for(int i = 0; i < n / 2; i++) {
            ans += __gcd(prefixGcd[i], prefixGcd[n-i-1]);
        }

        return ans;
    }
};

// [2,6,4]
// [2,6, 6]
// mx2 = 6
// pre[0] = 2
// [2, 6, 2]
// 2