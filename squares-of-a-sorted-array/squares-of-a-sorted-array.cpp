class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        
        int small_ele_idx = 0;
        for(int i = 1; i < n; i++) {
            if(abs(nums[i]) < abs(nums[small_ele_idx])) {
                small_ele_idx = i;
            }
        }
        
        vector<int> res;
        res.push_back(nums[small_ele_idx] * nums[small_ele_idx]);
        
        int l = small_ele_idx - 1, r = small_ele_idx + 1;
        
        while(l >= 0 && r < n) {
            if(abs(nums[l]) < abs(nums[r])) {
                res.push_back(nums[l] * nums[l]);
                l--;
            } else {
                res.push_back(nums[r] * nums[r]);
                r++;
            }
        }
        
        while(l >= 0) {
            res.push_back(nums[l] * nums[l]);
            l--;
        }
        while(r < n) {
            res.push_back(nums[r] * nums[r]);
            r++;
        }
        
        return res;
    }
};