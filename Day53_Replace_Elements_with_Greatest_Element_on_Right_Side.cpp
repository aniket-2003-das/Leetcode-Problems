class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        if(arr.size()==1) return {-1};
        int Maxi = max(arr[n- 2], arr[n-1]);

        for(int i=n-3; i>=0; i--){
            if(arr[i]>Maxi){
                int temp=Maxi;
                Maxi=arr[i];
                arr[i]=temp;
            }
            else arr[i] = Maxi;

        }
        arr[n-2]=arr[arr.size()-1];
        arr[n-1]=-1;
        return arr;
    }
};