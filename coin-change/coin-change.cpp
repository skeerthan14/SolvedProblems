class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for(int i=1;i<=amount;i++) {
            dp[i] = INT_MAX;
            for(int j=0;j<coins.size();j++) {
                if(i<coins[j]) break;
                if(dp[i-coins[j]]!=INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
                }
            }
        }
        return dp[amount] == INT_MAX? -1: dp[amount];
    }
};