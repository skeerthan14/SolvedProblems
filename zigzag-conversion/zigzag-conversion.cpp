class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1) return s;
        vector<vector<char>>v(numRows);
        string ans;
        int n = s.size(), i=0, dir = 1, row=0;
        while(i<n) {
            v[row].push_back(s[i++]);
            if(row==0) {
                dir = 1;
            } else if(row == numRows-1) {
                dir=-1;
            }
            
            row += dir;
        }
        for(int i=0;i<numRows;i++) {
            for(int j=0;j<v[i].size();j++) {
                ans.push_back(v[i][j]);
            }
        }
        return ans;
    }
};