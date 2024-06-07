class Solution {
public:
    int reverse(int x) {
        int temp = x;
        long a=0;
        while(x!=0) {
            a = a*10 + x%10;
            x /= 10;
        }
        if (a>INT_MAX || a<INT_MIN){ 
            return 0;
        }
        else{
            return a;
        }
    }
};