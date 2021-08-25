class Solution {
public:
    void rec(int i, vector<int> nums, int n, vector<vector<int> >& permutes) {
        if(i == n) {
            permutes.push_back(nums);
            return;
        }
        
        for(int j = i; j < n; j++) {
            swap(nums[i], nums[j]);
            
            rec(i + 1, nums, n, permutes);
            
            swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > permutes;
        
        rec(0, nums, n, permutes);
        
        return permutes;
    }
};