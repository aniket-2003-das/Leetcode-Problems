class Solution {
public:
    # define long long ll
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left=low;
        int right=mid+1;

        // Storing elements in temp array in a sorted manner.
        while (left<=mid && right<=high) {
            if (arr[left]<=arr[right]) temp.push_back(arr[left++]);
            else temp.push_back(arr[right++]);
        }

        // if elements on the left half are still left //
        while(left<=mid) temp.push_back(arr[left++]);
        //  if elements on the right half are still left //
        while(right<=high) temp.push_back(arr[right++]);
        // transfering all elements from temporary to arr //
        for (int i=low; i<=high; i++) arr[i]=temp[i-low];
    }

    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right=mid+1;
        int cnt=0;
        for (int i=low; i<=mid; i++) {
            while (right<=high && arr[i]>(2ll*arr[right])) right++;
            cnt+=(right-(mid+1));
        }
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt=0;
        if (low>=high) return cnt;
        int mid=(low+high)/2 ;
        cnt+=mergeSort(arr, low, mid);  // left half
        cnt+=mergeSort(arr, mid + 1, high); // right half
        cnt+=countPairs(arr, low, mid, high); //Modification
        merge(arr, low, mid, high);  // merging sorted halves
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(nums, 0, n-1);
    }
};