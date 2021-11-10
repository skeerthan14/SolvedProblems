class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, bp = prices[0], i=0;
        while(i<prices.size()-1) {
            if(prices[i]>prices[i+1]) {
                ans += prices[i] - bp;
                bp = prices[i+1];
            }
            i++;
        }
        ans += prices[i] - bp;
        return ans;
    }
};