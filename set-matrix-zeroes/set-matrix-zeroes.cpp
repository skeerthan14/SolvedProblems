class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<int> row(r, 0), col(c, 0);
        for(int i=0;i<r;i++) {
            for(int j = 0;j<c;j++) {
                if(matrix[i][j]==0) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(row[i]!=0 || col[j]!=0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};