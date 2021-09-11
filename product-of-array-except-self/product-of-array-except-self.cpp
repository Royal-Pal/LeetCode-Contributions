class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> sol(n, 0);
        
        int zero_cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                zero_cnt++;
                
                if(zero_cnt > 1) {
                    return sol;
                }
            }
        }
        
        int product = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                continue;
            }
            product *= nums[i];
        }
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                sol[i] = product;
                continue;
            }
            
            if(zero_cnt == 1) {
                sol[i] = 0;
            } else {
                sol[i] = product / nums[i];
            }
        }
        
        return sol;
    }
};