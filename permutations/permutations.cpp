class Solution {
public:
    void generate(vector<int> &nums, vector<int>&v, vector<vector<int>>&ans, bitset<10>&b) {
        if(nums.size()==v.size()) {
            ans.push_back(v);
            return;
        }

        for(int i=0;i<nums.size();i++) {
            if(b[i]==false){
                v.push_back(nums[i]);
                b[i] = true;
                generate(nums, v, ans, b);
                v.pop_back();
                b[i] = false;
            }

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        bitset<10>b;
        generate(nums, v, ans, b);
        return ans;
    }
};