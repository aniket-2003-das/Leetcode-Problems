class Solution {
public:
    int findMin(vector<int>& arr) {
        int low=0, high=arr.size()-1;
        int ans=INT_MAX;

        while (low <= high) {
            int mid=(low+high)/2;
            // Search Space=Sorted,
            // then arr[low] is min.
            if (arr[low]<=arr[high]) {
                ans=min(ans, arr[low]);
                break;
            }

            if (arr[low]<=arr[mid]) {
                ans=min(ans, arr[low]);
                low=mid+1;
            }

            else {
                ans=min(ans, arr[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};