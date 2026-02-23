class Solution {
public:
    // void printj(vector<vector<int>>& envelopes) {
    //     for(auto e : envelopes){
    //         cout << e[0] << " " << e[1] << endl;
    //     }
    // }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0]; 
        });

        // printj(envelopes);

        vector<int> lis;

        for(auto &envelope: envelopes) {
            int height = envelope[1];

            if(lis.empty() || lis.back() < height) {
                lis.push_back(height);
            } else {
                auto it = lower_bound(lis.begin(), lis.end(), height);
                *it = height;
            }
        }

        return lis.size();
    }
};