class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int searchInsert(vector<int>& nums, int t) {
        int l=0, h=nums.size()-1;
        if(nums[0]>t) return 0;
        if(nums[h]<t) return h+1;
        while(l<h){
            int m = l+(h-l)/2;
            if(nums[m]<t) {
                l = m+1;
            } else {
                h=m;
            }
        }
        return l;
    }
};