class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // approach- prefix and suffix product arrays.

        int n = nums.size();
        vector<int> prefixProd(n, 1), suffixProd(n, 1);

        for(int i = 1; i < n; i++) {
            prefixProd[i] = prefixProd[i-1] * nums[i-1];
        }

        for(int i = n-2; i >= 0; i--) {
            suffixProd[i] = suffixProd[i+1] * nums[i+1];
        }

        // for(int i = 0; i < n; i++) 
        //     cout << prefixProd[i] << " ";
        // cout << endl;

        // for(int i = 0; i < n; i++) 
        //     cout << suffixProd[i] << " ";
        // cout << endl;

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            ans[i] = prefixProd[i] * suffixProd[i];
        }
        
        return ans;
    }
};