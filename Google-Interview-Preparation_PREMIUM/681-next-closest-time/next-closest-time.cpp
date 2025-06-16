class Solution {
public:

    bool isValid(int tm, unordered_set<int>& st) {
        int h = tm / 60, m = tm % 60;

        for(int d: {h/10, h%10, m/10, m%10}) {
            if(!st.count(d)) return false;
        }
        
        return true;
    }

    string convert(string t) {
        if(t.size() == 1) {
            return "0" + t;
        }
        return t;
    }

    string nextClosestTime(string time) {
        int minutes = stoi(time.substr(0, 2)) * 60;
        minutes += stoi(time.substr(3, 2));

        unordered_set<int> allowed;

        for(auto ch: time) {
            if(ch != ':') {
                allowed.insert(ch - '0');
            }
        }

        const int totalMinutes = 24 * 60;

        while(true) {
            
            minutes = (minutes + 1) % totalMinutes;

            if(isValid(minutes, allowed)) {
                return convert(to_string(minutes/60)) + ":" + convert(to_string(minutes % 60));
            }
        }
        return "";
    }
};