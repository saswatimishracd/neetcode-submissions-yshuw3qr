class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        return quickSort(nums,low,high);
    }

    vector<int> quickSort(vector<int>& nums,int low,int high){
        if(low>=high) return nums;
        int pivotIdx = partition(nums,low,high);
        quickSort(nums,low,pivotIdx-1);
        quickSort(nums,pivotIdx+1,high);
        return nums;
    }

    int partition(vector<int>& nums,int low,int high){
        int pivot = nums[high];
        int i=low-1;
        for(int j=low;j<high;j++){
            if(nums[j]<pivot){
                i++;
                swap(nums[j],nums[i]);
            }
        }
        swap(nums[i+1],nums[high]);
        return i+1;
    }
};