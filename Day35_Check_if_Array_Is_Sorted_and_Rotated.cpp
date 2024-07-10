class Solution {
public:
    bool check(vector<int>& nums){
        int n = nums.size();
        int count = 0;
        
        for (int i=1; i<n; i++){
            if (nums[i-1] > nums[i]) count++;
        }
        // condition property of sorted and rotated array.
        if (nums[n-1] > nums[0]) count++;
        // If the count of violations is less than or equal to 1, return true
        return (count<=1);
    }
};