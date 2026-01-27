class Solution {
public:
    vector<vector<pair<int,int>>> graph;
    vector<int> vis;
    vector<int> dist;
    int N;
    const int INF = 1e9;

    int dijkshtra() {
        dist = vector<int>(N, INF);
        vis = vector<int>(N, 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            // wt, source
        pq.push({0, 0});
        dist[0] = 0;

        while(!pq.empty()) {
            auto [wt, node] = pq.top(); pq.pop();

            if(vis[node]) continue;
            vis[node] = 1;

            for(auto &neighbour: graph[node]) {
                auto [neigh, weight] = neighbour;
                if(dist[neigh] > wt + weight) {
                    dist[neigh] = wt + weight;
                    pq.push({ dist[neigh], neigh });
                }
            }
        }

        return dist[N-1] == INF ? -1 : dist[N-1];
    }

    int minCost(int n, vector<vector<int>>& edges) {
        N = n;
        graph = vector<vector<pair<int,int>>>(n);

        for(auto &edge: edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2] * 2});
        }
        return dijkshtra();
    }
};