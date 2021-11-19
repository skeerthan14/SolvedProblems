class Solution {
public:
    void generate(int n, vector<vector<string>>&ans, vector<string>&v, int left[], int upperD[], int lowerD[], int col) {
        if(col==n) {
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++) {
            if(left[i]==0 && upperD[i+col]==0 && lowerD[n-1 + (col-i)]==0) {
                left[i] = 1;
                upperD[i+col] = 1;
                lowerD[n-1+col-i] = 1;
                v[i][col] = 'Q';
                generate(n, ans, v, left, upperD, lowerD, col+1);
                left[i] = 0;
                upperD[i+col] = 0;
                lowerD[n-1+col-i] = 0;
                v[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<vector<string>> ans;
        vector<string> v(n, s);
        int left[10] = {0}, upperD[19] = {0}, lowerD[19] = {0};
        generate(n, ans, v, left, upperD, lowerD, 0);
        return ans;
    }
};