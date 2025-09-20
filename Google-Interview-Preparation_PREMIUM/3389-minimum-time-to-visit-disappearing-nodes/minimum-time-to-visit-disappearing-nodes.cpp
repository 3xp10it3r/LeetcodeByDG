class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> graph(n);

        for(int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> dist(n, INT_MAX);
        vector<int> visited(n, 0);

        pq.push({0, 0});
        dist[0] = 0;

        while(!pq.empty()){
            auto node = pq.top().second; pq.pop();

            if(visited[node]) continue;
            visited[node] = 1;

            for(auto v: graph[node]){
                int neighbour = v.first;
                int cost = v.second;
                if(dist[neighbour] > dist[node] + cost && disappear[neighbour] >  dist[node] + cost) {
                    dist[neighbour] = dist[node] + cost;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};