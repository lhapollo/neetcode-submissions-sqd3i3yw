class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rl = 0, rm = matrix.size()-1;
        int rmid;
        while(rl <= rm) {
            rmid = (rl+rm)/2; 
            if (target >= matrix[rmid][0] && target <= matrix[rmid][matrix[rmid].size()-1]) break;
            else if (target < matrix[rmid][0]) {
                rm = rmid-1;
            } else {
                rl = rmid+1;
            }
        }
        int l = 0, r = matrix[rmid].size()-1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (matrix[rmid][mid] == target) return true;
            else if (matrix[rmid][mid] < target) l = mid+1;
            else r = mid-1;
        }
        return false; 

    }
};
