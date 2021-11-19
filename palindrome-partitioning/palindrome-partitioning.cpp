class Solution {
public:
    bool isPal(string s, int l, int h) {
        while(l<h) {
            if(s[l++]!=s[h--]) return false;
        }
        return true;
    }
    void generate(string s, vector<vector<string>>& ans, int st, vector<string>&v) {
        if(st==s.size()) {
            ans.push_back(v);
            return;
        }
        for(int i=st;i<s.size();i++) {
            if(isPal(s, st, i)) {
                v.push_back(s.substr(st, i-st+1));
                generate(s, ans, i+1, v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>v;
        generate(s, ans, 0, v);
        return ans;
    }
};