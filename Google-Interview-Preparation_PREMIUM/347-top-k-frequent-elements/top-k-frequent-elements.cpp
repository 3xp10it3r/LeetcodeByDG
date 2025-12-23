class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // use hashmap

        int n = nums.size();
        
        unordered_map<int,int> mp;
        multimap<int,int, greater<int>> mp2;

        for(auto num : nums) {
            mp[num]++;
        }

        for(auto it = mp.begin(); it != mp.end(); it++) {
            mp2.insert({it -> second, it -> first});
        }

        vector<int> ans;
        for(auto it = mp2.begin(); it != mp2.end(); it++) {
            cout << it->first << " : " << it->second << endl;
            ans.push_back(it -> second);
            k--;
            if(k == 0) return ans;
        }

        return ans;
    }
};