class Solution {
public:
    // strips even powers from a number so if multiplied by other number with same odd power elements then
    // makes that to perfect square;
    int strip(int num) {
        int ans = 1;
        
        for(int i = 2; i <= sqrt(num); i++) {
            int cnt = 0;

            while(num % i == 0) {
                cnt++;
                num /= i;
            }
            // odd power
            if(cnt % 2) ans *= i;
        }

        if(num > 1) ans *= num;

        return ans;
    }

    void dfs(int node, int parent, map<int,int>& mp, long long &ans, vector<vector<int>> &graph, vector<int>& nums) {
        int s = strip(nums[node]);
        ans += mp[s];
        mp[s]++;

        for(auto neighbour: graph[node]) {
            if(neighbour == parent) continue;
            dfs(neighbour, node, mp, ans, graph, nums);
        }

        mp[s]--;
    }

    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        long long ans = 0;

        vector<vector<int>> graph(n);

        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        map<int,int> mp;

        dfs(0, -1, mp, ans, graph, nums);

        return ans;
    }
};