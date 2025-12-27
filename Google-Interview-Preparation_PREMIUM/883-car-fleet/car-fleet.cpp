class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>> steps;
        int n = position.size();

        for(int i = 0; i < n; i++) {
            steps.push_back({ position[i], float(target - position[i]) / (speed[i] * 1.0)});
        }

        sort(steps.begin(), steps.end());

        int ans = 1;

        float prevSteps = steps[n - 1].second;
        for(int i = n - 2; i >= 0; i--) {
            if(prevSteps >= steps[i].second) continue;
            else {
                ans++;
                prevSteps = steps[i].second;
            }
        }

        return ans;
    }
};

// pos  : [0, 3, 5, 8, 10]. 12
// steps : [12, 3, 7, 1, 1]

