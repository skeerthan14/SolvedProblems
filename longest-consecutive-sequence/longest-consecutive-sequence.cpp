class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        unordered_set<int>s(nums.begin(), nums.end());
        int cnt=1, ans=1;
        for(int i: nums) {
            if(s.count(i+1)) continue;
            cnt = 1;
            while(s.count(--i)) cnt++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};