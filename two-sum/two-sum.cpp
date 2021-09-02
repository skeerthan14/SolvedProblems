class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>u;
        for(int i=0;i<nums.size();i++) {
            if(u.find(target-nums[i])!=u.end()) {
                return {i, u[target-nums[i]]};
            }
            u[nums[i]] = i;
        }
        return {};
    }
};