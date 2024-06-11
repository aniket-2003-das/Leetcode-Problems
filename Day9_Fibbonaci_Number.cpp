class Solution {
public:
    // int fibo0 = 0;
    // int fibo1 = 1;
    // int fibo;
    // int fibonaci(int n, int st){
    //     if(n==0) return 0;
    //     if(n==1) return 1;
    //     while (st < n){
    //         fibo = fibo0 + fibo1;
    //         fibo0 = fibo1;
    //         fibo1 = fibo;
    //         st++;
    //     }
    //     return fibo;
    // }
    // int fib(int n) {
    //     return fibonaci(n, 1);
    // }
    int fib(int n) {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
};