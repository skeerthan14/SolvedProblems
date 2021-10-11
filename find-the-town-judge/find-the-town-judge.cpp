class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> grid(n+1, 0);
        for(auto i: trust) {
            grid[i[0]]--;
            grid[i[1]]++;
        }
        for(int i=1;i<=n;i++) {
            if(grid[i]==n-1) return i;
        }
        return -1;
    }
};