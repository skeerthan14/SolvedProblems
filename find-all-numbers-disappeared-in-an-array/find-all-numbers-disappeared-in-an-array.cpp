class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++) {
            int m = abs(nums[i])-1;
            nums[m] = nums[m]>0? -1*nums[m]: nums[m];
        }
        for(int i=0;i<nums.size();i++) {
            if(nums[i]>0) ans.push_back(i+1);
        }
        return ans;
    }
};