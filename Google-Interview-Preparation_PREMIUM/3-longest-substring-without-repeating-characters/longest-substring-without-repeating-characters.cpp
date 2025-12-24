class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int ans = 0;

        unordered_map<char,int> mp;

        int head = -1, tail = 0;

        while(tail < n) {
            while(head + 1 < n && mp.find(s[head + 1]) == mp.end()){
                head++;
                mp[s[head]]++;
            }

            ans = max(ans, head - tail + 1);

            if(tail > head) {
                tail++;
                head = tail - 1;
            } else {
                mp[s[tail]]--;
                if(mp[s[tail]] == 0) mp.erase(s[tail]);
                tail++;
            }
        }

        return ans;
    }
};