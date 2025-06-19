class Solution {
public:
    static const int MAX = 1e4;
    bool primes[MAX];

    void preCompute() {
        fill(primes, primes + MAX, true);
        primes[0] = false;
        primes[1] = false;

        for(int i = 2; i * i < MAX; i++) {
            if(primes[i]) {
                for(int j = i * i; j < MAX; j += i) {
                    primes[j] = false;
                }
            }
        }
    }

    vector<int> getNextOptions(int n) {
        vector<int> ans;
        string s = to_string(n);

        for(int i = 0; i < s.size(); i++) {
            string copy = s;
            if(s[i] != '9') {
                copy[i] = s[i] + 1;
                ans.push_back(stoi(copy));
            }

            copy = s;

            if(s[i] != '0') {
                copy[i] = s[i] - 1;
                ans.push_back(stoi(copy));
            }
        }

        return ans;
    }

    int minOperations(int n, int m) {
        preCompute();
    
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(MAX, INT_MAX);

         
        if(primes[n] || primes[m]) return -1;

        if(m == n) return n;

        pq.push({n, n});
        dist[n] = n;

        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if(node == m) return cost;

            for(auto neighbour: getNextOptions(node)) {
                if(primes[neighbour]) continue;
                if(dist[neighbour] > dist[node] + neighbour) {
                    pq.push({dist[node] + neighbour, neighbour});
                    dist[neighbour] = dist[node] + neighbour;
                }
            }
        }

        return -1;
    }
};