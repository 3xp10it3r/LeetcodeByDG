class Solution {
public:
    string minWindow(string s, string t) {


        unordered_map<char,int> mp;

        for(auto ch: t) mp[ch]++;

        int len = t.size();

        int n = s.size();
        int head = -1, tail = 0;

        int startIndex = -1, length = 1e9;

        int cnt = 0;
        while(head < n) {
            while(head + 1 < n && cnt < len){
                head++;
                if(mp[s[head]] > 0) {
                    cnt++;
                } 
                mp[s[head]]--;
            }
            // cout << "t : " << tail << "h : " << head << endl;
            if(cnt == len && (head - tail + 1) < length) {
                startIndex = tail;
                length = head - tail + 1;
            }

            if(tail > head) {
                tail++;
                head = tail - 1;
            } else {
                //remove from ds
                mp[s[tail]]++;
                if(mp[s[tail]] > 0) {
                    cnt--;
                }
                // mp[s[tail]]--;
                tail++;
            }
        }

        if(startIndex == -1) return "";
        return s.substr(startIndex, length);
    }
};