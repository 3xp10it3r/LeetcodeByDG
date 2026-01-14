class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        int n = asteroids.size();

        for(int i = 0; i < n; i++) {
            st.push(asteroids[i]);

            while(!st.empty()){
                int t1 = st.top(); st.pop();
                if(st.empty()) {
                    st.push(t1);
                    break;
                }

                int t2 = st.top(); st.pop();

                if((t1 >= 0 && t2 >= 0) || (t1 <= 0 && t2 <= 0) || (t1 > 0 && t2 < 0)) {
                    st.push(t2);
                    st.push(t1);
                    break;
                }

                if(abs(t1) == abs(t2)){}
                else if(abs(t1) > abs(t2)) {
                    st.push(t1);
                } else {
                    st.push(t2);
                }
            }
        }

        vector<int> ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};