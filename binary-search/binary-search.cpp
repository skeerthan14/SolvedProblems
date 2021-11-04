class Solution {
public:
    int search(vector<int>& nums, int t) {
        int l = 0, h = nums.size()-1;
        while(l<=h) {
            int m = l + (h-l)/2;
            if(nums[m]==t) return m;
            else if(nums[m]<t) l=m+1;
            else h=m-1;
        }
        return -1;
    }
};