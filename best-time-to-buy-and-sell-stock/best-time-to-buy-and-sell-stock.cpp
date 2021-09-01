class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0, mi=prices[0];
        for(int i=1;i<prices.size();i++) {
            mp = max(mp, prices[i]-mi);
            mi = min(mi, prices[i]);
        }
        return mp;
    }
};