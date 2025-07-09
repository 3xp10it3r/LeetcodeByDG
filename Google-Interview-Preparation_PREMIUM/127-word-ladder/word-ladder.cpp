class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 1;

        queue<string> q;

        q.push(beginWord);

        unordered_set<string> words(wordList.begin(), wordList.end());

        while(!q.empty()) {
            int sz = q.size();
            for(int k = 0; k < sz; k++) {
                string node = q.front(); q.pop();

                if(node == endWord) return ans;

                for(int i = 0; i < node.size(); i++) {
                    string copy = node;
                    for(int ch = 'a'; ch <= 'z'; ch++) {
                        copy[i] = ch;
                        if(words.count(copy)) {
                            q.push(copy);
                            words.erase(copy);
                        }
                        copy = node;
                    }
                }
            }

            ans++;
        }

        return 0;
    }
};