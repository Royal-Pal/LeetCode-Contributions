class Solution {
public:
    void rec(int n, int k, int i, vector<int> &v, vector<vector<int>> &comb) {
        if(k == 0) {
            comb.push_back(v);
            return;
        }
        
        for(int j = i; j <= n; j++) {
            v.push_back(j);
            rec(n, k - 1, j + 1, v, comb);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > comb;
        vector<int> v;
        
        rec(n, k, 1, v, comb);
        
        return comb;
    }
};