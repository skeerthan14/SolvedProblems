class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    vector<int> twoSum(vector<int>& nums, int t) {
        int p1=0, p2 = nums.size()-1;
        while(p1<p2) {
            if(nums[p1]+nums[p2]==t) return {p1+1, p2+1};
            else if(nums[p1] + nums[p2]>t) {
                p2--;
            } else {
                p1++;
            }
        }
        return {};
    }
};