/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {
        if(!node) return NULL;

        Node* clone = new Node(node->val);
        mp[node] = clone;

        for(auto neighbour: node->neighbors) {
            if(mp.find(neighbour) != mp.end()) {
                clone->neighbors.push_back(mp[neighbour]);
            } else {
                clone->neighbors.push_back(dfs(neighbour));
            }
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};