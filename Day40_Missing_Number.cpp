class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XOR1=0; 
        int XOR2=0;

        for(int i=1; i<=nums.size(); i++){
            XOR1 = XOR1^nums[i-1];
            XOR2 = XOR2^i;
        }
        return XOR1^XOR2;
    }
};