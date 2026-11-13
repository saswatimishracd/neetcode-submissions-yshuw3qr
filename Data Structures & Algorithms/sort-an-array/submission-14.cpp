class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }

    void mergeSort(vector<int>& nums,int low,int high){
        if(low<high){
            int mid = (high-low)/2+low;
            mergeSort(nums,low,mid);
            mergeSort(nums,mid+1,high);
            merge(nums,low,mid,high);
        }
    }
    void merge(vector<int>& nums,int low,int mid,int high){
        int i = low;
        int j = mid+1;
        int n = high-low+1;
        int k = 0;
        vector<int> temp(n);
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                temp[k] = nums[i];
                i++; k++;
            }
            else{
                temp[k] = nums[j];
                j++; k++;
            }
        }
        while(i<=mid){
            temp[k] = nums[i];
            i++; k++;
        }
        while(j<=high){
            temp[k] = nums[j];
            j++; k++;
        }
        for(int t=low;t<=high;t++){
            nums[t] = temp[t-low];
        }
    }

};