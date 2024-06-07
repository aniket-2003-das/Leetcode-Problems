class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long digit = 0;
        if (x < 0) {
            return 0;
        }
        while(x!=0) {
            digit = (10*digit + x%10);
            x/=10;
        }
        if (digit == temp) {
            return 1;
        } 
        else {
            return 0;
        }
    }
};