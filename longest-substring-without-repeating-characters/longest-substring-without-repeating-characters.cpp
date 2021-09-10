class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        
        vector<int> occ(257, 0);
        
        int max_len = 0, start = 0;
        for(int i = 0; i < n; i++) {
            int idx = (int)((char)s[i]);
            
            occ[idx]++;
            if(occ[idx] > 1) {
                max_len = max(max_len, i - start);
                
                while(start < i) {
                    occ[(int)((char)s[start])]--;
                    
                    if(occ[idx] == 1) {
                        start++;
                        break;
                    }
                    
                    start++;
                }
            }
        }
        
        max_len = max(max_len, n - start);
        
        return max_len;
    }
};