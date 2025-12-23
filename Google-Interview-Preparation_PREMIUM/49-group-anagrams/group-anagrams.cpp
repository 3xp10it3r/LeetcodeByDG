class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sort each string 10^6 log 10^6
        // then use map

        unordered_map<string, vector<string>> mp;

        for(auto str : strs) {
            string prev = str;
            sort(str.begin(), str.end());
            mp[str].push_back(prev);
        }

        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it -> second);
        }

        return ans;
    }
};