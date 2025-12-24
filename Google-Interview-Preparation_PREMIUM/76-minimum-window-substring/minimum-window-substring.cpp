class Solution {
public:
    string minWindow(string s, string t) {
        int len = t.size();

        int n = s.size();

        int head = -1, tail = 0;

        int index = -1, length = 1e9;
        
        // ds
        unordered_map<char, int> mp;
        int cnt = 0;

        for(auto& ch: t) {
            mp[ch]++;
        }

        while(tail < n) {
            while(head + 1 < n && cnt < len) {
                head++;
                if(mp[s[head]] > 0) {
                    cnt++;
                }
                mp[s[head]]--;
            }

            if(cnt == len && (head - tail + 1) < length){
                index = tail;
                length = head - tail + 1;
            }

            if(tail > head) {
                tail++;
                head = tail - 1;
            } else {
                mp[s[tail]]++;
                if(mp[s[tail]] > 0)
                    cnt--;
                tail++;
            }
        }

        if(index == -1) return "";
        return s.substr(index, length);
    }
};