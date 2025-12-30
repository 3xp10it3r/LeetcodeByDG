class Solution {
public:
    bool isValid(int maxSplitSum, vector<int>& nums, int k) {
        int n = nums.size();

        int splits = k;

        int current = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] > maxSplitSum) return false;

            current += nums[i];

            if(current > maxSplitSum) {
                splits--;
                current = nums[i];
            }
        }


        if(current <= maxSplitSum) splits--;

        if(splits < 0) return false;
        return true; 
    }
    int splitArray(vector<int>& nums, int k) {
        int start = *min_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);

        int ans = INT_MAX;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(isValid(mid, nums, k)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};