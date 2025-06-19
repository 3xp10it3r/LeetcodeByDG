class Solution {
public:
    char next(char ch) {
        return ch == '9' ? '0' : ch + 1;
    }

    char prev(char ch) {
        return ch == '0' ? '9' : ch - 1;
    }

    vector<string> getNextOptions(string s) {
        vector<string> ans;

        for(int i = 0; i < 4; i++) {
            string copy = s;
            copy[i] = next(s[i]);
            ans.push_back(copy);
            copy[i] = prev(s[i]);
            ans.push_back(copy);
        }

        return ans;
    }
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> deadendsSet(deadends.begin(), deadends.end());

        unordered_map<string, int> vis;

        queue<string> q;

        q.push("0000");

        int level = 0;

        while(!q.empty()) {
            int sz = q.size();

            for(int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();

                if(node == target) return level;

                if(vis[node] || deadendsSet.count(node)) continue;
                vis[node] = true;

                for(auto &option: getNextOptions(node)) {
                    q.push(option);
                }
            }

            level++;
        }

        return -1;
    }
};