class Solution {
public:
    // bool isPalin(string s, int l, int h) {
    //     if(l<0 || h>=s.size()) return false;
    //     while(l<h) {
    //         if(s[l++]!=s[h--]) return false;
    //     }
    //     return true;
    // }
    string longestPalindrome(string s) {
        string ans = "";
        int p1, p2;
        int n = s.size();
        for(int i=0;i<n;i++) {
            p1 = i-1, p2 = i+1;
            while(p1>=0 && p2<n && s[p1]==s[p2]) {
                p1--;
                p2++;
            }
            if(p2-p1-1>ans.size()) {
                ans = s.substr(p1+1, p2-p1-1);
            }
            p1 = i, p2 = i+1;
            // cout<<p1<<" "<<p2<<" : ";
            while(p1>=0 && p2<n && s[p1]==s[p2]){
                // cout<<p1<<" "<<p2<<" "<<(s[p1]==s[p2])<<" ;";
                p1--;
                p2++;
            }
            // cout<<" : "<<p1<<" "<<p2<<endl;
            if(p2-p1-1>ans.size()) {
                ans = s.substr(p1+1, p2-p1-1);
                // cout<<ans<<endl;
                
            }
        }
        return ans;
    }
};