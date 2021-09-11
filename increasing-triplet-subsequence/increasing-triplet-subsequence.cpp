class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3) {
            return false;
        }
        
        vector<int> mins(n, -1);
        vector<int> maxs(n, -1);
        
        mins[0] = 0;
        int min_idx = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] <= nums[min_idx]) {
                min_idx = i;
            }
            mins[i] = min_idx;
        }
        
        maxs[n - 1] = n - 1;
        int max_idx = n - 1;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] >= nums[max_idx]) {
                max_idx = i;
            }
            maxs[i] = max_idx;
        }
        
        for(int i = 0; i < n; i++) {
            if(mins[i] < i && maxs[i] > i) {
                return true;
            }
        }
        
        return false;
    }
};