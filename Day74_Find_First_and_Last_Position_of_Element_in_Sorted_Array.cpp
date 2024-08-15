class Solution {
public:
    int First(vector<int>& nums, int target, int n){
        int low=0, high=n-1;
        int first=-1;

        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) first=mid, high=mid-1;
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return first;
    }

    int Last(vector<int>& nums, int target, int n){
        int low=0, high=n-1;
        int last=-1;

        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) last=mid, low=mid+1; 
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return last;        
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;

        ans.push_back(First(nums, target, n));
        ans.push_back(Last(nums, target, n));
        return ans;
    }
};