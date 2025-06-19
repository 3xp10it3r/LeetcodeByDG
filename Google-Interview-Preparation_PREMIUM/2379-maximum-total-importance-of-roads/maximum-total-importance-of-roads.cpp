class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indeg(n, 0);

        for(auto &road: roads) {
            int u = road[0];
            int v = road[1];

            indeg[u]++;
            indeg[v]++;
        }


        sort(indeg.rbegin(), indeg.rend());

        long long ans = 0;

        int k = n;

        for(auto x: indeg) {
            ans += 1LL * k * x;
            k--;
        }

        return ans;
    }
};