class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& I) {
        vector<vector<int>> ans;
        sort(I.begin(), I.end());
        ans.push_back({I[0][0], I[0][1]});
        int j=0;
        for(int i=1;i<I.size();i++) {
            if(ans[j][1]>=I[i][0]) {
                ans[j][1] = max(ans[j][1], I[i][1]);
            } else {
                ans.push_back(I[i]);
                j++;
            }
        }
        return ans;
    }
};