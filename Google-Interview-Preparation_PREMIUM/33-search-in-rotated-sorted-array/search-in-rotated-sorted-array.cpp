class Solution {
public:

    int binary_search(vector<int>& nums, int left, int right, int target) {
        int low = left, high = right;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else high = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        int peak = n - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            
            if(nums[mid] < nums[0]) {
                peak = mid;
                high = mid - 1;
            } else if(nums[mid] >= nums[0]) {
                low = mid + 1;
            }
        }

        cout << "peak" << peak << endl;

        int l = binary_search(nums, 0, peak - 1, target);
        int r = binary_search(nums, peak, n - 1, target);

        if(l != -1) return l;
        if(r != -1) return r;
        return -1;
    }
};