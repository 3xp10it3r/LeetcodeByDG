class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n);

        vector<int> vis(n, 0);
        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);
        

        for(auto &road: roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        priority_queue< vector<long long>, vector<vector<long long>>, greater<vector<long long>> > pq;

        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()) {
            auto temp = pq.top();
            long long node = temp[1];
            long long wt = temp[0];
            pq.pop();

            // if(vis[node]) continue;
            // vis[node] = 1;

            if (wt > dist[node]) continue;

            for(auto neighbour: graph[node]) {

                long long ne = neighbour.first;
                long long wtn = neighbour.second;

                if(dist[ne] > dist[node] + wtn) {
                    dist[ne] = dist[node] + wtn;
                    ways[ne] = ways[node] % MOD;
                    pq.push({dist[ne], ne});
                } else if(dist[ne] == dist[node] + wtn){
                    ways[ne] = (ways[ne] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1] % MOD;
    }
};