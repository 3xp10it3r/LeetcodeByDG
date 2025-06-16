class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string ans = "";
        map<int, int> mp;
        
        for(int i = 0; i < indices.size(); i++) {
            string ns = s.substr(indices[i], sources[i].size());
            
            if(sources[i] == ns) {
                mp[indices[i]] = i;
            }
        }
        
        for(int i = 0; i < s.size(); i++) {
            if(mp.find(i) != mp.end()) {
                ans += targets[mp[i]];
                i += sources[mp[i]].size() - 1;
            } else {
                ans += s[i];
            }
        }
        
        return ans;
    }
};