struct UnionFind {
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;
    
    void makeSet(string& x) {
        if(parent.find(x) == parent.end()) {
            parent[x] = x;
            rank[x] = 1;
        }
    }
    
    string find(string& x) {
        makeSet(x);
        
        if(parent[x] == x) return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void merge(string& x, string& y) {
        string xRoot = find(x);
        string yRoot = find(y);
        
        if(xRoot == yRoot) return;
        
        if(rank[xRoot] >= rank[yRoot]) {
            rank[xRoot] += rank[yRoot];
            parent[yRoot] = xRoot;
        } else {
            rank[yRoot] += rank[xRoot];
            parent[xRoot] = yRoot;
        }
    }
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        
        int n = sentence1.size();
        int m = sentence2.size();
        
        if(n != m) return false;
        
        UnionFind uf;
        
        for(auto &sPair: similarPairs) {
            uf.merge(sPair[0], sPair[1]);
        }
        
        for(int i = 0; i < n; i++) {
            if(sentence1[i] == sentence2[i]) continue;
            
            if(uf.find(sentence1[i]) != uf.find(sentence2[i])) return false;
        }
        
        return true;
    }
};