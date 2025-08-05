class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;
        int n = baskets.size();

        for(auto fruit: fruits) {
            bool found = false;
            for(int i = 0; i < n; i++) {
                if(baskets[i] >= fruit) {
                    baskets[i] = -1;
                    found = true;
                    break;
                }
            }
            if(!found) ans++;
        }

        return ans;
    }
};