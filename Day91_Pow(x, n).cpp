class Solution {
public:
    long double power(double x, long int n) {
        if (n==1) return x;
        if (n==0) return 1; 
        if (n<0) return 1/power(x, -n);
        if (n%2==0) return power(x*x, n/2); 
        else return x*power(x*x, n/2); 
    }
    
    long double myPow(double x, int n) {
        return power(x, n); 
    }
};