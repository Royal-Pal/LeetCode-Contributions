class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) {
            return 0;
        }
        
        unordered_set<int> us;
        
        for(int i = 0; i < n; i++) {
            us.insert(nums[i]);
        }
        
        int max_len = 1, curr_len = 1;
        for(auto i: us) {
            int curr_ele = i;
            
            if(us.find(curr_ele - 1) == us.end()) {
                while(us.find(curr_ele + 1) != us.end()) {
                    curr_len++;
                    curr_ele++;
                }
                
                max_len = max(max_len, curr_len);
            }
            curr_len = 1;
        }
        
        return max_len;
    }
};