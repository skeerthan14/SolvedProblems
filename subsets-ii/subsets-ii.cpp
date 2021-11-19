class Solution {
public:
    void generate(vector<int>&nums, int id, vector<vector<int>>&ans, vector<int>&v) {
        ans.push_back(v);
        for(int i=id;i<nums.size();i++) {
            if(i!=id && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            generate(nums, i+1, ans, v);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        // ans.push_back({});
        sort(nums.begin(), nums.end());
        vector<int>v;
        generate(nums, 0, ans, v);
        return ans;
    }
};