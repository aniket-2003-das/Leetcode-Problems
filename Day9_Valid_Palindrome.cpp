class Solution {
public:
    bool help(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        string S;
        for (char ch : s) {
            if (isalnum(ch)) {
                S += tolower(ch);
            }
        }
        return help(S, 0, S.size() - 1);
    }
};