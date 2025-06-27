class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++) {
            
            if(s[i] == ']') {
                
                string current = "";
                
                while(st.top() != '[') {
                    current.push_back(st.top());
                    st.pop();
                }
                
                st.pop();
                
                string val = "";
                
                while(!st.empty() && isdigit(st.top())) {
                    val.push_back(st.top());
                    st.pop();
                }
                
                reverse(val.begin(), val.end());
                
                int num = stoi(val);
                
                while(num) {
                    for(int k = current.size() - 1; k>= 0; k--) {
                        st.push(current[k]);
                    }
                    num--;
                }
            } else {
                st.push(s[i]);
            }
        }
        
        
        string ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};