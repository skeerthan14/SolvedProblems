class Solution {
public:
    void generate(vector<int>&arr, int t, int s, vector<vector<int>>&ans, vector<int>&v, int st) {
        if(s==t) {
            ans.push_back(v);
            return;
        }
        for(int i=st;i<arr.size();i++) {
            if(s+arr[i]>t) return;
            v.push_back(arr[i]);
            generate(arr, t, s+arr[i], ans, v, i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int t) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> v;
        generate(arr, t, 0, ans, v, 0);
        return ans;
    }
};