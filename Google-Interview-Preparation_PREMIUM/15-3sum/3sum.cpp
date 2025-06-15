class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        
        unordered_set<int> dups;
        
        unordered_map<int,int> seen;
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(dups.insert(nums[i]).second) {
                for(int j = i + 1; j < n; j++) {
                    int complement = -nums[i] - nums[j];
                    auto it = seen.find(complement);
                    
                    if(it != seen.end() && it->second == i) {
                        vector<int> temp = {nums[i], nums[j], complement};
                        
                        sort(temp.begin(), temp.end());
                        
                        ans.insert(temp);
                    }
                    
                    seen[nums[j]] = i;
                }
            }
        }
        
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};