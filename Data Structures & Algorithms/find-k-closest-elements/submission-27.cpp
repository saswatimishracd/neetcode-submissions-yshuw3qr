class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int i=0,j=n-k,mid=0;
        vector<int> res;
        while(i<j){
            mid=i+(j-i)/2;
            if(x-arr[mid]>arr[mid+k]-x){
                mid++;
                i=mid;
            }
            else{
                j=mid;
            }
        }
        for(int a=0;a<k;a++){
            res.push_back(arr[a+mid]);
        }
        return res;
    }
};