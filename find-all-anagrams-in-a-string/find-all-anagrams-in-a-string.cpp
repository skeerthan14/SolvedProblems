class Solution {
    bool check(vector<int>&p, vector<int>&s) {
        for(int i=0;i<26;i++) {
            if(p[i]!=s[i]) return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), m=p.size();
        if(n<m) return ans;
        vector<int>p_cnt(26, 0), s_cnt(26, 0);
        for(int i=0;i<m;i++) {
            p_cnt[p[i]-'a']++;
            s_cnt[s[i]-'a']++;
        }
        if(check(p_cnt, s_cnt)) ans.push_back(0);
        for(int i=1;i<n-m+1;i++) {
            s_cnt[s[i-1]-'a']--;
            s_cnt[s[i+m-1]-'a']++;
            if(check(p_cnt, s_cnt)) ans.push_back(i);
        }
        return ans;
    }
};