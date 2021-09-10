class Solution {
public:
    int binarySearch(vector<int> nums, int s, int e, int key) {
        while(s <= e) {
            int mid = (s + e) / 2;
            
            if(s == e && nums[s] != key) {
                return -1;
            }
            
            if(nums[mid] == key) {
                return mid;
            } else if(nums[mid] < key) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<int> sol;
        
        for(int i = 0; i < n; i++) {
            int req_num = target - nums[i];
            
            int idx = binarySearch(nums, i + 1, n - 1, req_num);
            
            if(idx != -1) {
                sol.push_back(i + 1);
                sol.push_back(idx + 1);
                return sol;
            }
        }
        
        return sol;
    }
};