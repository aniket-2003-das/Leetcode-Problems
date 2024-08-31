class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string str1 = string(4-to_string(num1).length(), '0') + to_string(num1);
        string str2 = string(4-to_string(num2).length(), '0') + to_string(num2);
        string str3 = string(4-to_string(num3).length(), '0') + to_string(num3);
        string ans;

        for(int i=0; i<4; i++){
            char mini=min(str1[i], min(str2[i], str3[i]));
            ans.push_back(mini);
        }
        int result=stoi(ans);
        return result;
    }
};