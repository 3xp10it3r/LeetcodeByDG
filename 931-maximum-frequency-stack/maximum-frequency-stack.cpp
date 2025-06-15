class FreqStack {
public:
    unordered_map<int,int> mp;
    map<int, stack<int>> group;
    int maxCnt;

    FreqStack() {
        mp.clear();
        group.clear();
        maxCnt = 0;
    }
    
    void push(int val) {
        mp[val]++;
        group[mp[val]].push(val);

        if(mp[val] > maxCnt) {
            maxCnt++;
        }
    }
    
    int pop() {
        int tmp = group[maxCnt].top();
        group[maxCnt].pop();
        mp[tmp]--;
        if(group[maxCnt].size() == 0) maxCnt--;
        return tmp;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */