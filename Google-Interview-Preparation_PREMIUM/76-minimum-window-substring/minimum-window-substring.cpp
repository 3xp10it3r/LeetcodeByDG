class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size();
        int len = t.size();
        
        int head = -1, tail = 0;
        
        int startIndex = -1;
        int ansLength = 1e9;
        
        
        //ds 
        unordered_map<char, int> mp;
        
        int cnt = 0;
        
        //ds initial update
        
        for(auto &ch: t) {
            mp[ch]++;
        }
        
        while(head < n) {
            while(head + 1 < n && cnt < len) {
                head++;
                
                if(mp[s[head]] > 0) {
                    cnt++;
                }
                
                mp[s[head]]--;
            }
            
            if(cnt == len && (head - tail + 1) < ansLength) {
                startIndex = tail;
                ansLength = head - tail + 1;
            }
            
            if(tail > head) {
                head = tail;
                tail = head + 1;
            } else {
                mp[s[tail]]++;
                if(mp[s[tail]] > 0) {
                    cnt--;
                }
                tail++;
            }
        }
        if(startIndex == -1) return "";
        return s.substr(startIndex, ansLength);
    }
};