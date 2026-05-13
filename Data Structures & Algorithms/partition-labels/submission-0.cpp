class Solution {
public:
    unordered_map<char, int> um; 
    vector<int> partitionLabels(string s) {
        vector<int> ans; 

        for (int i = 0; i < s.length(); i++) {
            um[s[i]] = i;
        }

        int size = 0;
        int end_ind = 0;

        for (int i = 0; i < s.length(); i++) {
            size++;
            end_ind = max(end_ind, um[s[i]]); 
            if (end_ind == i) {
                ans.push_back(size);
                size = 0;
            }
        }

        return ans;
    }
};
