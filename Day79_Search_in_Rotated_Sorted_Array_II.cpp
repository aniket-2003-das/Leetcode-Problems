class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0, high=n-1;

        while (low<=high) {
            int mid = low + (high-low)/2;

            // if mid points the target
            if (arr[mid]==k) return -1;

            // Edge case: arr[low]==arr[mid]==arr[high]
            if (arr[low]==arr[mid] && arr[mid]==arr[high]) {
                low=low+1;
                high=high-1;
                continue;
            }

            // if left part is sorted:
            else if (arr[low]<=arr[mid]) {
                if (arr[low]<=k && k<=arr[mid]) high=mid-1;
                else low=mid+1;
            }
            // if right part is sorted:
            else { 
                if (arr[mid]<=k && k<=arr[high]) low=mid+1;
                else high=mid-1;
            }
        }
        return 0;
    }
};