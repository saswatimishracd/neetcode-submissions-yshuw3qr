class Solution {
public:
    int mySqrt(int x) {
        int left = 0; int right = x/2;
        while(left<=right){
            int mid = left+(right-left)/2;
            long long mul = 1LL*mid*mid;
            if(mul==x) return mid;
            else if(mul>x){               
                right = mid-1;
            }
            else{
                long long mul2 = 1LL * (mid+1) * (mid+1);
                if(mul2>x){
                    return mid;
                }
                left = mid+1;
            }
        }
        return 1;
    }
};