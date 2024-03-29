class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n % 2 == 0) {
            if (n < 0)
                return myPow(x*x, n/2);
            else
                return myPow(x*x, n/2);
        }
        else {
            if (n < 0)
                return (1/x)*myPow(x, n+1);
            else
                return x*myPow(x, n-1);
        }
    }
};
