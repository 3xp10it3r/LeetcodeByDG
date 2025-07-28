class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        int cnt = 0;

        // vector<int> v;
        // v.push_back(nums[0]);

        // for(int i = 1; i < nums.size(); i++) {
        //     if(v.back() == nums[i]) continue;
        //     v.push_back(nums[i]);
        // }

        int last = nums[0];

        for(int i = 1; i < nums.size() - 1; i++) {
            if(nums[i] == last || nums[i] == nums[i+1]) continue;
            if(nums[i] > last && nums[i] > nums[i+1]) cnt++;
            if(nums[i] < last && nums[i] < nums[i+1]) cnt++;

            last = nums[i];
        }

        return cnt;
    }
};