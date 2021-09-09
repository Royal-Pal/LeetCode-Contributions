class Solution {
public:
    int binarySearch(vector<int> nums, int s, int e, int key) {
        if(s > e) {
            return -1;
        }
        
        int mid = (s + e) / 2;
        
        if(nums[mid] == key) {
            return mid;
        } else if(nums[mid] < key) {
            return binarySearch(nums, mid + 1, e, key);
        } else {
            return binarySearch(nums, s, mid - 1, key);
        }
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        return binarySearch(nums, 0, n - 1, target);
    }
};