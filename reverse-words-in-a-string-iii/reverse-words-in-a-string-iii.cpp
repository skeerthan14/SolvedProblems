class Solution {
public:
    string reverseWords(string s) {
        int s1 = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i]==' ') {
                reverse(s.begin()+s1, s.begin()+i);
                s1 = i+1;
            } 
        }
        reverse(s.begin()+s1, s.end());
        return s;
    }
};