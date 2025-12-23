class Solution {
public:
    bool isAnagram(string s, string t) {
        // bruteforce - sort and compare

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // int n = s.size(), m = t.size();

        // if(n != m) return false;

        // for(int i = 0; i < n; i++) {
        //     if(s[i] != t[i]) return false;
        // }

        // return true;

        // optimal- use hashmap 

        unordered_map<char, int> mp;
        for(auto ch: s) {
            mp[ch]++;
        }

        for(auto ch: t) {
            mp[ch]--;
            if(mp[ch] < 0) return false;
        }

        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(mp[ch] > 0) return false;
        }
        return true;
    }
};