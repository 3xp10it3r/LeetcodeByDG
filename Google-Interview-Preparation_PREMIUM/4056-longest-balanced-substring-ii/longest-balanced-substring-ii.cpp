class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;

        // case 1: single char only
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) cnt++;
            else cnt = 1;
            ans = max(ans, cnt);
        }

        // case 2: only 2 distinct char {"ab", "ac", "bc"}
        vector<string> combination = {"ab", "ac", "bc"};

        for(auto comb: combination) {
            int x = comb[0], y = comb[1];
            map<int,int> mp;
            mp[0] = -1;
            cnt = 0;

            for(int i = 0; i < n; i++) {
                if(s[i] == x) cnt++;
                else if(s[i] == y) cnt--;
                else {
                    mp.clear();
                    cnt = 0;
                }

                if(!mp.count(cnt)) mp[cnt] = i;
                ans = max(ans, i - mp[cnt]);
            }
        }

        // case 3: all three chars.
        map<pair<int,int>, int> mpp;
        mpp[{0,0}] = -1;
        int v1 = 0, v2 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') v1++;
            else if(s[i] == 'b') v2++;
            else v1--,v2--;

            if(!mpp.count({v1,v2})) mpp[{v1,v2}] = i;
            ans = max(ans, i - mpp[{v1,v2}]);  
        }

        return ans;
    }
};