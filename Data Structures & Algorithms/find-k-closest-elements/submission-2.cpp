class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size()-k; //possible range of start indices
        while(left<right){
            int mid = left+(right-left)/2; //Choosing middle window for binary search
            if(x-arr[mid]>arr[mid+k]-x){
                left=mid+1;//eliminating the left start indices of window
            }
            else{
                right=mid;
            }

        }
        return vector<int>(arr.begin()+left,arr.begin()+left+k);
    }
};