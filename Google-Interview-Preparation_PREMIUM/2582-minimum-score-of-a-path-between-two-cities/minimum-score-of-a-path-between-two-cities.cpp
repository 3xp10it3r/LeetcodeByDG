class Solution {
public:
    int ans;
    

    void dfs(int node, vector<vector<pair<int,int>>>& graph, vector<int>& vis) {
        vis[node] = 1; 
        for(auto &neighbour: graph[node]) {
            ans = min(ans, neighbour.second);
            if(!vis[neighbour.first]) {
                dfs(neighbour.first, graph, vis);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> graph(n+1);
        vector<int> vis(n+1, 0);

        ans = 1e9;

        for(auto &road: roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        dfs(1, graph, vis);

        return ans;
    }
};