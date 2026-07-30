class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        while (high >= low) {
            int mid = low + (high - low) / 2;
            int noOfDays = 0;
            int weight = mid;
            int i = 0;
            while (i < n) {
                while (i < n && weight >= weights[i]) {
                    weight -= weights[i];
                    i++;
                }
                noOfDays++;
                weight = mid;
            }

            if (noOfDays > days) {
                low = mid + 1;
            } else if (noOfDays <= days) {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};