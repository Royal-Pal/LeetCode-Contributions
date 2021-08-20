class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        int dp[n][m];
        
        for(int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int min_fpath = INT_MAX;
                
                if(j != 0) {
                    min_fpath = min(min_fpath, dp[i - 1][j - 1]);
                }
                if(j != m - 1) {
                    min_fpath = min(min_fpath, dp[i - 1][j + 1]);
                }
                min_fpath = min(min_fpath, dp[i - 1][j]);
                
                dp[i][j] = min_fpath + matrix[i][j];
            }
        }
        
        int ans = INT_MAX;
        for(int j = 0; j < m; j++) {
            ans = min(ans, dp[n - 1][j]);
        }
        
        return ans;
    }
};