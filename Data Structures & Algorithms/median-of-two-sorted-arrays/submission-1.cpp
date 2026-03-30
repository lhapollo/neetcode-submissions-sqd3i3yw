class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2; 
        int tot = A.size() + B.size();
        int half = (tot+1)/2;

        if (B.size() < A.size()) {
            swap(A,B);
        }

        int l = 0; 
        int r = A.size();

        while (l <= r) {
            int mid = (l+r)/2;
            int rem = half - mid; 

            int a_left = mid > 0? A[mid-1]: INT_MIN;
            int a_right = mid < A.size()? A[mid]: INT_MAX;
            int b_left = rem > 0? B[rem-1]: INT_MIN;
            int b_right = rem < B.size()? B[rem]: INT_MAX;

            if (a_left <= b_right && b_left <= a_right) {
                if (tot % 2 != 0) {
                    return max(a_left, b_left);
                } 
                return (max(a_left, b_left) + min(a_right, b_right)) / 2.0;
            } else if (a_left > b_right) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
