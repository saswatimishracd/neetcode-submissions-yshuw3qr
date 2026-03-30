class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left=0,right=n-k,mid=0;
        vector<int> result;
        while(left<right){
            mid = left+(right-left)/2;
            if(x-arr[mid]>arr[mid+k]-x){
                left=mid+1;
            }
            else{
                right--;
            }
        }
        for(int i=0;i<k;i++){
            result.push_back(arr[i+left]);
        }
        return result;
    }
};