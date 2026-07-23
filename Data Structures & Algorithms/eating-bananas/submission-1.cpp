class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int result = INT_MAX;
        while(high>=low){
        int totalCalculatedTime = 0;
           int mid = low + (high-low)/2;
           for(int pile:piles){
                totalCalculatedTime += ceil((double)pile/mid);
           } 
        if (h>=totalCalculatedTime){
             high = mid-1;
             if(result>mid) result=mid;
           }
           else {
            low = mid+1;
           }
        }
        return result;
    }
};
