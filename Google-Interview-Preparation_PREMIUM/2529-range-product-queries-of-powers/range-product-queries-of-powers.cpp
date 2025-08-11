class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> arr;

        for(int i = 0; i < 31; i++) {
            if(n & (1 << i)) {
                arr.push_back((1 << i) % MOD);
            }
        }

        for(int i = 1; i < arr.size(); i++) {
            arr[i] = (1LL * arr[i-1] * arr[i]) % MOD;
        }

        vector<int> ans;

        for(auto query: queries) {
            int left = query[0];
            int right = query[1];

            long long val = arr[right];

            if(left - 1 >= 0) val = (val * modPow(arr[left - 1], MOD - 2)) % MOD;

            ans.push_back((int)val);
        }

        return ans;
    }
};