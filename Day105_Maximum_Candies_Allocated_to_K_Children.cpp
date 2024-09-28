class Solution {
public:
    bool isPossible(long long mid, vector<int> &candies, long long k) {
        int n=candies.size();
        long long cnt=0;
        for(int i=0 ; i<n ; i++) cnt += 1ll*(candies[i]/mid);
        return cnt>=k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        sort(begin(candies),end(candies));
        long long totSum=accumulate(begin(candies), end(candies), 0ll);
        if(totSum<k) return 0;

        long long low=1 , high=totSum/k;
        while(low<=high) {
            long long mid=low+(high-low)/2;
            if(isPossible(mid,candies,k)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};
