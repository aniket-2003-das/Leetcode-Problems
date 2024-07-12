class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xoor=0;
        for(int i=0; i<nums.size(); i++){
            xoor = xoor^nums[i];
        }
        return xoor;
    }
};