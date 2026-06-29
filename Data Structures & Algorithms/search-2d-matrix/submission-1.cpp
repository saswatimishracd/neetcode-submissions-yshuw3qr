class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0; int right = matrix.size()-1;
        while(left <= right){
            int mid = left+(right-left)/2;
            if(matrix[mid][0]==target) return true;
            else if(matrix[mid][0]>target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        int row = right;
        if (row < 0) return false;
        int left1=0;int right1=matrix[0].size()-1;
        while(left1<=right1){
            int mid = left1+(right1-left1)/2;
            if(matrix[row][mid]==target) return true;
            else if(matrix[row][mid]>target) {
                right1 = mid-1;
            }
            else{
                left1 = mid+1;
            }
        }
        return false;
    }
};
