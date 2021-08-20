class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days[days.size() - 1];
        
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < days.size(); i++) {
            dp[days[i]] = 1;
        }
        
        // for(int i = 0; i <= n; i++) {
        //     cout << dp[i] << " ";
        // } cout << "\n";
        
        for(int i = 1; i <= n; i++) {
            if(dp[i] == 0) {
                dp[i] = dp[i - 1];
                continue;
            }
            
            int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
            
            op1 = dp[i - 1] + costs[0];
            op2 = dp[((i - 7) < 0) ? 0 : (i - 7)] + costs[1];
            op3 = dp[((i - 30) < 0) ? 0 : (i - 30)] + costs[2];
            
            dp[i] = min(op1, min(op2, op3));
        }
        
        // for(int i = 0; i <= n; i++) {
        //     cout << dp[i] << " ";
        // }
        
        return dp[n];
    }
};