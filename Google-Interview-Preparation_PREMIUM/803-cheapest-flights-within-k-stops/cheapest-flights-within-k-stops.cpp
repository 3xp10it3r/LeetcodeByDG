class Solution {
public:
    const int INF = 1e8;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& flight : flights) {
            int a = flight[0], b = flight[1], w = flight[2];
            graph[a].push_back({b, w});
        }

        // dijkstra(src);

        vector<int> stops(n + 1, INF);

        priority_queue < vector<int>, vector<vector<int>>,
            greater<vector<int>> > pq;

        // dist, source, stops
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            int distance = temp[0];
            int node = temp[1];
            int steps = temp[2];

            if (steps > stops[node] || steps > k + 1)
                continue;
            stops[node] = steps;

            if (node == dst)
                return distance;

            for (auto& [ne, price] : graph[node]) {
                pq.push({distance + price, ne, steps + 1});
            }
        }

        return -1;
    }
};