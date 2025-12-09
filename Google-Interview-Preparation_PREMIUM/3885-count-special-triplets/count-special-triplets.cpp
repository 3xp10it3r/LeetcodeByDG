class Solution {
public:
    const int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpFromStart, mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int ans = 0; 

        for(int i = 0; i < n; i++) {
            mp[nums[i]]--;

            ans = (ans % MOD + (1LL * mp[nums[i] * 2] * mpFromStart[nums[i] * 2]) % MOD) % MOD;

            mpFromStart[nums[i]]++;
        }

        return ans;
    }
};