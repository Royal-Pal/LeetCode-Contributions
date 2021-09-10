class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) {
            return false;
        }
        
        bool hasOneFound = false;
        
        while(n) {
            if(hasOneFound) {
                return false;
            }
            
            if(n & 1) {
                hasOneFound = true;
            }
            
            n >>= 1;
        }
        
        return true;
    }
};