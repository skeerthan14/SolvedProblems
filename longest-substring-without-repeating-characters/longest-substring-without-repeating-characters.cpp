class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, ans = 0, n = s.size();
        vector<int>v(256, -1);
        while(r<n) {
            if(v[s[r]]!=-1) {
                l = max(l, v[s[r]]+1);
            }
            v[s[r++]] = r;
            ans = max(ans, r-l);
        }
        return ans;
    }
};