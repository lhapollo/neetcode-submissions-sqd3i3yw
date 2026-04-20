class Solution {
public:
    int diff_count(string a, string b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) cnt++;
        }
        return cnt;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> um;
        unordered_set<string> vis;
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = 0; j < wordList.size(); j++) {
                int diff = diff_count(wordList[i], wordList[j]);
                if (diff == 1) {
                    um[wordList[i]].push_back(wordList[j]);
                    um[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        queue<pair<string, int>> q;
        int ans = 0;

        for (auto word: wordList) {
            if (diff_count(beginWord, word) == 1) {
                q.push({word, 1});
            }
        }

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            vis.insert(curr.first);
            if (curr.first == endWord) {
                if (ans == 0) ans = curr.second;
                else ans = min(ans, curr.second);
            }
            for (auto i: um[curr.first]) {
                if (vis.find(i) == vis.end()) q.push({i, curr.second+1});
            }
        }
        return ans == 0? 0: ans+1;
    }
};
