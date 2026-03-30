class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int sum = 0,i=0,j=n-1;
        while(i<j){
            sum = numbers[i]+numbers[j];
            if(target==sum) return {i+1,j+1};
            if(sum>target){
                j--;
            }
            else{
            i++;
            }
        }
        return {};
        
    }
};
