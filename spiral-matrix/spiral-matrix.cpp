class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size(), n = mat[0].size(), k=0, l=0;
        while(k<m && l<n) {
            //top
            for(int i=l;i<n; i++) {
                ans.push_back(mat[k][i]);
            }
            k++;
            
            //right
            for(int i = k; i<m;i++) {
                ans.push_back(mat[i][n-1]);
            }
            n--;
            //bottom
            if(k<m) {
                for(int i=n-1;i>=l;i--) {
                    ans.push_back(mat[m-1][i]);
                }
                m--;
            }
            if(l<n) {
                //left
                for(int i=m-1;i>=k;i--) {
                    ans.push_back(mat[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};