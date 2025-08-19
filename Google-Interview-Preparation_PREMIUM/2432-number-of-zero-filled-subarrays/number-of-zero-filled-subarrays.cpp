class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        int curLen = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) curLen++;
            else {
                if(curLen)
                ans += 1LL * curLen * (curLen + 1) / 2;
                curLen = 0;
            }
        }

        if(curLen) {
            ans += 1LL * curLen * (curLen + 1) / 2;
        }

        return ans;
    }
};