class Solution {
public:
    int numDecodings(string s) {
        // vector<int> dp(s.size() + 1, 0);
        int a = 1, b;
        b = (s[0] == '0') ? 0 : 1;
        for(int i=1; i<s.size(); i++){
                int val = (s[i]=='0') ? 0:b;
                int temp = (s[i-1]-'0')*10 + (s[i]-'0');
            
                if (temp>=10 && temp<=26) 
                    val += a;
            
            a = b;
            b= val;
        }
        return b;
    }
};