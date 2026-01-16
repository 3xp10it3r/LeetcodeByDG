class Solution {
public:
    const int MOD = 1e9 + 7;
    unordered_set<int> helper(vector<int>& fences, int last) {
        unordered_set<int> st;

        int n = fences.size();

        fences.push_back(1);
        fences.push_back(last);

        sort(fences.begin(), fences.end());

        for(int i = 0; i < n+2; i++) {
            for(int j = i+1; j < n+2; j++) {
                st.insert(abs(fences[i] - fences[j]));
            }
        }
        
        return st;
    }

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int> sideH = helper(hFences, m);
        unordered_set<int> sideV = helper(vFences, n);

        int ans = 0;

        for(auto &x: sideH) {
            if(sideV.find(x) != sideV.end()) {
                ans = max(ans, x);
            }
        }

        if(ans == 0) return -1;

        int rAns = (1LL * ans * ans) % MOD;

        return rAns;
    }
};

// 4 4
// h 2 
// v 2,3

// {1, 2, 0}

// {1,2,2,1,1}