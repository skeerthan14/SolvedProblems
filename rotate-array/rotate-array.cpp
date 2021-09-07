class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0 || k==0 || k%n==0) return;
        k %= n;
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};