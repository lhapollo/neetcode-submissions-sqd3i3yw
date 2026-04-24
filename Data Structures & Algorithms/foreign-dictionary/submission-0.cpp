class Solution {
public:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> in;

    string foreignDictionary(vector<string>& words) {
        for (string w: words) {
            for (auto c: w) {
                adj[c] = unordered_set<char>();
                in[c] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; i ++) {
            string w1 = words[i], w2 = words[i+1];
            int minLen = min(w1.size(), w2.size());
            if (w1.size() > w2.size() && w1.substr(0, minLen) == w2.substr(0, minLen)) return "";

            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    if (!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        in[w2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q; 
        for (auto &[c, deg]: in) {
            if (deg == 0) q.push(c);
        }

        string ans; 
        while (!q.empty()) {
            auto ch = q.front();
            q.pop();
            ans += ch;

            for (auto nei: adj[ch]) {
                in[nei]--;
                if (in[nei] == 0) q.push(nei);
            }
        }

        return ans.size() == in.size() ? ans: "";
    }
};
