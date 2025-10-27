class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int prev = 0, cur = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            cur = 0;
            for(int j = 0; j < m; j++) {
                if(bank[i][j] == '1') cur++;
            }

            ans += (prev * cur);
            if(cur != 0)
                prev = cur;
        }

        return ans;
    }
};