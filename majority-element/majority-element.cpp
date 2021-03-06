class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int cnt = 0, candidate = -1;
        for(int i = 0; i < n; i++) {
            if(cnt == 0) {
                candidate = nums[i];
            }
            
            cnt += (nums[i] == candidate) ? 1 : -1;
        }
        
        return candidate;
    }
};