//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long merge(long long arr[], long long low, long long mid, long long high) {
        vector<long long> temp;
        long long left=low; 
        long long right=mid+1;
        
        //Modification 1: cnt variable to count the pairs:
        long long cnt=0;
    
        //storing elements in the temporary array in a sorted manner//
        while (left<=mid && right<=high) {
            if (arr[left]<=arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                //Modification 2
                cnt+=(mid-left+1); 
                right++;
            }
        }
        while (left<=mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right<=high) {
            temp.push_back(arr[right]);
            right++;
        }
    
        // transfering all elements from temp to a.
        for (int i=low; i<=high; i++) {
            arr[i]=temp[i-low];
        }
    
        // Modification 3
        return cnt; 
    }
    
    
    long long mergeSort(long long arr[], long long low, long long high) {
        long long cnt=0;
        if (low>=high) return cnt;
        long long mid=(low+high)/2 ;
        cnt+=mergeSort(arr, low, mid);  // left half
        cnt+=mergeSort(arr, mid+1, high); // right half
        cnt+=merge(arr, low, mid, high);  // merging sorted halves
        return cnt;
    }


    long long int inversionCount(long long arr[], long long n) {
        // a[]: Input Array
        // Function to count inversions in the array.
        return mergeSort(arr, 0, n-1); 
    }
    
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends