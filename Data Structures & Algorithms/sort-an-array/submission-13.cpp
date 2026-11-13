class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }

        int partition(vector<int>& nums,int low, int high) 
        {
            if (low < high) {
                int pivot = nums[high];
                int i = low-1;
                int j = low;
                while (j<high) {
                    if (nums[j] <= pivot) {
                        i++;
                        swap(nums[i],nums[j]);
                    }
                    j++;
                }
                swap(nums[i+1],nums[high]);
                return i+1;
            }
            return 0;
        }


        void quickSort(vector<int>& nums,int low,int high) 
        {
            if(low<high){
                int partitionIdx = partition(nums,low,high);
                quickSort(nums,low,partitionIdx-1);
                quickSort(nums,partitionIdx+1,high);
            }
        }

};