class Solution {
public:
    bool isValid(vector<int>& piles, int h, int maxPerHour) {
        for(auto pile: piles) {
            h -= ceil(pile * 1.0 / maxPerHour);
        }

        if(h < 0) return false;
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());

        int ans = INT_MAX;
        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(isValid(piles, h, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};