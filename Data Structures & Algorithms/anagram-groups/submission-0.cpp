class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m; 
        for (auto i: strs) {
            vector<int> cnt(26,0);
            for (int j = 0; j < i.length(); j++) {
                cnt[i[j]-'a']++;
            }
            string key = "";
            for (int z = 0; z < 26; z++) {
                if (cnt[z] > 0) {
                    while (cnt[z] > 0) {
                        key += (z + 'a');
                        cnt[z]--;
                    }
                }
            }
            m[key].push_back(i);
        }
        vector<vector<string>> ans; 
        for (auto i: m) {
            ans.push_back(i.second);
        }
        return ans; 
    }
};
