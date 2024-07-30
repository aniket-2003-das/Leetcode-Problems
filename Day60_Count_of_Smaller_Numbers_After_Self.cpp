class Solution {
public:
    void merge(vector<int> &count, vector<pair<int, int>> &v, int left, int mid, int right) {
        vector<pair<int, int>> temp(right-left+1);
        int i=left;
        int j=mid+1;
        int k=0;

        while(i<=mid && j<=right) {
            // mind that we're sorting in descending order
            if (v[i].first<=v[j].first) temp[k++] = v[j++];
            else {
                // only line responsible to update count, related to problem constraint, 
                // remaining part is just regular mergeSort 
                count[v[i].second] += right-j+1;
                temp[k++]=v[i++];
            }
        }
        while(i<=mid) temp[k++]=v[i++];
        while(j<=right) temp[k++]=v[j++];
        for(int i=left; i<=right; i++) v[i]=temp[i-left];
    }        


    void mergeSort(vector<int> &count, vector<pair<int, int>> &v, int left, int right) {
        if (left>=right) return;
        int mid=left+(right-left)/2;
        mergeSort(count, v, left, mid);
        mergeSort(count, v, mid+1, right);
        merge(count, v, left, mid, right);
    }


    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int, int>> v(n);

        for (int i=0; i<n; i++) v[i]=make_pair(nums[i], i);
        vector<int> count(n, 0);

        // sorting in descending order
        mergeSort(count, v, 0, n-1);
        return count;
    }
};