class Solution {
public:
    int calculateKadaneImpact(vector<int>& nums, int target, int k) {
        int mx = 0, cur = 0;

        for(auto num : nums) {
            if(num == target) cur++;
            if(num == k) cur--;
            
            if(cur < 0) cur = 0;

            mx = max(mx, cur);
        }

        return mx;
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(auto num : nums) {
            mp[num]++;
        }
        
        int maxFreq = 0;

        for(const auto &[key, _]: mp) {
            maxFreq = max(maxFreq, calculateKadaneImpact(nums, key, k));
        }

        return mp[k] + maxFreq;
    }
};