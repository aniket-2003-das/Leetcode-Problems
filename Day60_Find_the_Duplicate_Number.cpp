class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++) {
            if(map.find(nums[i]) != map.end()) {
                return nums[i];
            } 
            else map[nums[i]] = 1;
        }
        return 0;
    }
};