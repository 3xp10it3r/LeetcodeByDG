class LRUCache {
public:
                // key, value, pointer to DLL
    unordered_map<int, pair<int, list<int>::iterator>> mp;
    list<int> order;
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        order.erase(mp[key].second);
        order.push_back(key);

        mp[key] = {mp[key].first, prev(order.end())};
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            order.erase(mp[key].second);
        } else if(mp.size() == capacity) {
            mp.erase(*order.begin());
            order.erase(order.begin());
        }

        order.push_back(key);
        mp[key] = {value, prev(order.end())}; 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */