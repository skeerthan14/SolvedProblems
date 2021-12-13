class Solution {
public:
    int maxPower(string s) {
        int c;
        int ma = c = 1;
        for(int i=1;i<s.size();i++) {
            if(s[i] != s[i-1]) {
                ma = max(ma, c);
                c = 1;
            } else {
                c++;
            }
        }
        ma = max(ma,c);
        return ma;
    }
};