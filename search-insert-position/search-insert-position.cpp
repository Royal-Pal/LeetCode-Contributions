class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        
        int idx = 0;
        while(s <= e) {
            // cout << s << " " << e << "\n";
            int mid = (s + e) / 2;
            
            if(s == e && nums[s] != target) {
                if(nums[mid] < target) {
                    idx = mid + 1;
                } else {
                    // cout << 1;
                    idx = mid;
                }
                break;
            }
            
            if(nums[mid] == target) {
                idx = mid;
                break;
            } else if(nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        
        return idx;
    }
};