class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int totalK = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == k) totalK++;
        }
        int prefixCountK = 0;
        int freq[100005]{};
        int maxval[100005]{};
        int res = 0;
        for (int j = 0; j < nums.size(); j++) {
            int n = nums[j];
            maxval[n] = max(maxval[n], prefixCountK - freq[n]);
            prefixCountK += (n == k) ? 1 : 0;
            freq[n]++;
            res = max(res, (totalK - prefixCountK) + maxval[n] + freq[n]);
        }
        return res;
    }
};