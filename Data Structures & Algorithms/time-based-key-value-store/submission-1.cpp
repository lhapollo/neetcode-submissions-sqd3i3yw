class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";
        int l = 0, r = mp[key].size() - 1;
        string ans = "";
        while (l <= r) {
            int m = (l+r)/2; 
            if (mp[key][m].second == timestamp) return mp[key][m].first;
            else if (mp[key][m].second < timestamp) {
                ans = mp[key][m].first; 
                l = m+1; 
            } else {
                r = m-1;
            }
        }
        return ans;
    }
};
