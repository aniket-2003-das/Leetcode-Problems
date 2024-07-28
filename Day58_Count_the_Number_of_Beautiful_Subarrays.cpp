class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long xr=0;
        unordered_map<int, int> mpp;
        mpp[xr]++; // Insert the value {0,1}.
        long long cnt=0;
        int k=0;

        for(int i=0; i<n; i++){
            xr^=nums[i];
            //By formula: x = xr^k:
            int x=xr^k;
            cnt+=mpp[x];
            mpp[xr]++;
        }
        return cnt;
    }
};