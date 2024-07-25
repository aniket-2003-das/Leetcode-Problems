class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int presum=0, cnt=0;
        map<int, int> mpp;
        mpp[0]=1;
        for(int i=0; i<nums.size(); i++){
            presum+=nums[i];
            int remove=presum-k;
            cnt+=mpp[remove];
            mpp[presum]+=1;
        }
        return cnt;
    }
};