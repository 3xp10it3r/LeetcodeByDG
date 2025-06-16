class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        // getting the breakpoint (maximium prefix matches between next permutation) (from behind to make lexicographycally greater)
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                index = i;
                break;
            }
        }

        // if no such breakpoints found then we need to go lower one so simply reversing the array will help;

        if(index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // if breakpoint found then we will find the least number which is greater than that index's number so we can swap and find least number which is greater than current permute.
        for(int i = n-1; i > index; i--) {
            if(nums[i] > nums[index]) {
                swap(nums[i],nums[index]);
                break;
            }
        }

        // after swap we need to make whatever after the index as sorted, so in this case reversing will help.

        reverse(nums.begin() + index + 1, nums.end());
        return;
    }
};