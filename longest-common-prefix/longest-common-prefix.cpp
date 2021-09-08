class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        int m = min(strs[0].size(), strs[n-1].size()), i=0;
        string ans = "";
        while(i<m && strs[0][i] == strs[n-1][i]) {
            ans.push_back(strs[0][i++]);
        }
        return ans;
    }
};