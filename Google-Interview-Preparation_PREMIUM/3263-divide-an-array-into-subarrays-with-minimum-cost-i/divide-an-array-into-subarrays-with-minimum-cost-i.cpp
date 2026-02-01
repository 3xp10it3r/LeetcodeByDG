class Solution {
public:
    int minimumCost(vector<int>& nums) {

        int num1 = 100;
        int num2 = 100;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < num1) {
                num2 = num1;
                num1 = nums[i];
            } else if(nums[i] < num2) {
                num2 = nums[i];
            }
        }
        return nums[0] + num1 + num2;
    }
};