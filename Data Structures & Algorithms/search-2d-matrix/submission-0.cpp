class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& m: matrix) {
            int l = 0, r = m.size()-1;
            while (l <= r) {
                int mid = (l+r)/2;
                if (m[mid] == target) return true;
                else if (m[mid] > target) r = mid-1;
                else l = mid+1;
            }
        }
        return false;
    }
};
