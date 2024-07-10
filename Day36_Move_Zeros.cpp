class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) {
                j=i;
                break;
            }
        }
        if (j==-1) return;

        for(int i=j+1; i<nums.size(); i++){
            if(nums[i]!=0){
                swap(nums[i], nums[j]);
                j++;
            }
        }

    }


    //     int n=a.size();
    //     int j=0;
    //     for(int i=0;i<n;i++){
    //         if(a[i]!=0){
    //             a[j]=a[i];
    //             j++;
    //         }
    //     }
    //     for(;j<n;j++) a[j]=0;
    // }
};