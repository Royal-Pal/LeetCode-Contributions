class Solution {
public:
    vector<int> getRow(int ri) {
        vector<int> pt(ri + 1, 0);
        
        pt[0] = 1;
        for(int i = 0; i <= ri; i++) {
            for(int j = i; j > 0; j--) {
                pt[j] += pt[j - 1];
            }
        }
        
        return pt;
    }
};