class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        
        int p = 0;
        for(int i = 0; i < 32; i++) {
            if(n & (1 << (31 - i))) {
                ans += pow(2, p);
            }
            p++;
        }
        
        return ans;
    }
};