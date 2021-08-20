class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        if(amount == 0) {
            return 0;
        }
        
        int dp[amount + 1];
        
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            int min_coins = INT_MAX;
            
            for(int j = 0; j < n; j++) {
                if(coins[j] <= i && dp[i - coins[j]] != -1) {
                    int req_coins = min(min_coins, 1 + dp[i - coins[j]]);
                    
                    if(req_coins != 0) {
                        min_coins = min(min_coins, req_coins);
                    }
                }    
            }
            
            dp[i] = (min_coins == INT_MAX) ? -1 : min_coins;
        }
        
        return dp[amount];
    }
};