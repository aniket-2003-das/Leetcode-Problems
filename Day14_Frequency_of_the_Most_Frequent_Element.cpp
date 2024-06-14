class Solution {
#define ll long long
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        ll total = 0;
        int n = nums.size();
        int ans = INT_MIN;
        for (r; r < n; r++) {
            total += nums[r];
            while ((ll)(r - l + 1) * nums[r] > total + k)
                total -= nums[l++];
            ans = max(ans, (r - l + 1));
        }
        return ans;
    }
};