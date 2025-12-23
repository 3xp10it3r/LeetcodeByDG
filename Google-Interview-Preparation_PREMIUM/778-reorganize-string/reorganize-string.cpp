class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        unordered_map<char, int> mp;

        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
            if(mp[s[i]] > ceil(n/2.0)) return "";
        }

        priority_queue<pair<int,char>> pq;

        for(auto p : mp) {
            pq.push({ p.second, p.first });
        }

        string ans = "";
        while(pq.size() >= 2) {
            auto top1 = pq.top(); pq.pop();
            auto top2 = pq.top(); pq.pop();

            ans += top1.second;
            ans += top2.second;

            if(top1.first - 1 > 0) pq.push({top1.first - 1, top1.second});
            if(top2.first - 1 > 0) pq.push({top2.first - 1, top2.second});
        }

        if(pq.size() == 1) ans += pq.top().second;

        return ans;
    }
};