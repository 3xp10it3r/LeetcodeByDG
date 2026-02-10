class Solution {
public:
    bool check(int cap, vector<int>& weights, int days) {
        int d = 0;
        int cur = 0;
        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] > cap) return false;
            if(cur + weights[i] > cap) {
                cur = weights[i];
                d++;
            } else if(cur + weights[i] == cap){
                cur = 0;
                d++;
            } else{
                cur += weights[i];
            }
        }

        if(cur) d++;

        return d <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *min_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);

        cout << lo << " " << hi << endl;

        int ans = INT_MAX;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if(check(mid, weights, days)) {
                hi = mid - 1;
                ans = mid;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};