class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        
        if(amt == 0) {
            return 0;
        }
        
        int dp[amt + 1];
        
        dp[0] = 0;
        for(int i = 1; i <= amt; i++) {
            int min_num = INT_MAX;
            for(int j = 0; j < n; j++) {
                if(coins[j] <= i) {
                    int req_coins = 1 + dp[i - coins[j]];
                    
                    if(req_coins != 0) {
                        min_num = min(min_num, req_coins);
                    }
                }
            }
            dp[i] = (min_num == INT_MAX) ? -1 : min_num;
        }
        
        return dp[amt];
    }
};