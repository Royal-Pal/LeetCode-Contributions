class Solution {
public:
    void reverse(vector<int> &nums, int s, int e) {
        while(s <= e) {
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
        return;
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
//         reverse part 1
        reverse(nums, 0, n - k - 1);
        
//         reverse part 2
        reverse(nums, n - k, n - 1);
        
//         reverse whole array
        reverse(nums, 0, n - 1);
        
        return;
    }
};