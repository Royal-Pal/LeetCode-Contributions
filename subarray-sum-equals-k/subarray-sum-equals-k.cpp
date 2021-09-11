class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> um;
        um[0] = 1;
        
        int cnt = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            
            if(um.count(sum - k) > 0) {
                cnt += um[sum - k];
            }
            
            um[sum]++;
        }
        
        return cnt;
    }
};