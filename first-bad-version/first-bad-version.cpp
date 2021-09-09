// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1, e = n;
        
        int idx = -1;
        while(s <= e) {
            int mid = (int)(((long)s + e) / 2);
            
            if(isBadVersion(mid)) {
                idx = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        
        return idx;
    }
};