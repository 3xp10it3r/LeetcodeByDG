class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int tail = 0, head = -1;

        unordered_map<char,int> mp;

        int ans = 0;
        while(head < n) {
            while(head + 1 < n && mp[s[head+1]] < 1) {
                head++;
                mp[s[head]]++;
            }

            ans = max(ans, head - tail + 1);

            if(head < tail) {
                tail = head + 1;
                head = tail;
            } else {
                mp[s[tail]]--;
                tail++;
            }
        }

        return ans;
    }
};