class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        
        vector<int> dp(tri.back());
        
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[j] = min(dp[j], dp[j + 1]) + tri[i][j];
            }
        }
        
        return dp[0];
    }
};