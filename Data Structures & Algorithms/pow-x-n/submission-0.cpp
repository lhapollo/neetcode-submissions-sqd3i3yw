class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1; 
        int mag = abs(n);
        double res = myPow(x, mag/2); 
        res *= res; 
        if (mag % 2 == 1) res *= x; 
        if (n < 0) res = 1/res;
        return res;  
    }
};
