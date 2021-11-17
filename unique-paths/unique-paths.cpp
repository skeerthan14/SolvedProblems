class Solution {
public:
    int uniquePaths(int m, int n) {
        long long int ans = 1, nu=1, d=1;
        for(int i=m+n-2, j=1;j<min(m,n);i--,j++) {
            nu *= i;
            d*=j;
        }
        // cout<<n
        ans = nu/d;
        return (int)ans;
    }
};