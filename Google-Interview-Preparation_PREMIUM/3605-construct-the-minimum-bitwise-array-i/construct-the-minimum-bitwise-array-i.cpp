class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int x: nums) {
            if(x == 2) ans.push_back(-1);
            else
            for(int i = 0 ; i <= x; i++) {
                if((i | (i + 1) )== x) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};





