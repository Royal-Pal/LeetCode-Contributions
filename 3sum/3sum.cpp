class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int> > sol;
        
        if(n < 3) {
            return sol;
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int req_num1 = -nums[i];
            int s = i + 1, e = n - 1;
            
            while(s < e) {
                int curr_sum = nums[s] + nums[e];
                
                if(curr_sum < req_num1) {
                    s++;
                } else if(curr_sum > req_num1) {
                    e--;
                } else {
                    vector<int> v = {nums[i], nums[s], nums[e]};
                    sol.push_back(v);
                    
                    while(s < e && nums[s] == v[1]) {
                        s++;
                    }
                    while(s < e && nums[e] == v[2]) {
                        e--;
                    }
                }
            }
        }
        
        return sol;
    }
};