class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // use hashmap

        int n = nums.size();
        
        unordered_map<int,int> mp;

        for(auto num : nums) {
            mp[num]++;
        }

        vector<vector<int>> bucket(n + 1);

        for(auto it = mp.begin(); it != mp.end(); it++) {
            bucket[it->second].push_back(it->first);
        }

        vector<int> ans;
        for(int i = n; i >= 1; i--) {
            for(auto el: bucket[i]) {
                ans.push_back(el);
                k--;
                if(k == 0) return ans;
            }
        }

        return ans;
    }
};