class Solution {
public:
    int findDays(vector<int> &weights, int cap) {
        int days=1; 
        int load=0;
        int n=weights.size();

        for (int i=0; i<n; i++) {
            if (load+weights[i]>cap) {
                days+=1; 
                load=weights[i];
            }
            //load the weight on the same day.
            else load+=weights[i];
        }
        return days;
    }

    int shipWithinDays(vector<int> &weights, int days) {
        int low=*max_element(weights.begin(), weights.end());
        int high=accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid=(low+high)/2;
            int numberOfDays=findDays(weights, mid);
            if (numberOfDays<=days) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};