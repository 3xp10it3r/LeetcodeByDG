class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        int n = s.size();
            
        unordered_map<char, int> distinctChars;
        
        int head = -1, tail = 0;
        
        int ans = 0;
        
        while(head < n) {
            while(head + 1 < n && (int)distinctChars.size() + (!distinctChars.count(s[head + 1])) <= 2) {
                head++;
                distinctChars[s[head]]++;
            }
            
            ans = max(ans, head - tail + 1);
            
            if(tail > head) {
                head = tail;
                tail = head + 1;
            } else {
                distinctChars[s[tail]]--;
                if(distinctChars[s[tail]] == 0) {
                    distinctChars.erase(s[tail]);
                }
                tail++;
            }
        }
        return ans;
    }
};