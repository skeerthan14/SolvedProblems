class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n-2;i++) {
            int p1= i+1, p2 = n-1;
            if(nums[i]>0) break;
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                while(p1<p2 && p1<n && p2>=0) {
                    if(nums[p1]+nums[p2]>-nums[i]) {
                        p2--;
                    } else if(nums[p1]+nums[p2]<-nums[i]) {
                        p1++;
                    } else {
                        ans.push_back({nums[i], nums[p1], nums[p2]});
                        int prev_p1 = nums[p1], prev_p2 = nums[p2];
                        while(p1<p2 && nums[p1]==prev_p1) p1++;
                        while(p1<p2 && nums[p2]==prev_p2) p2--;
                    }
                }   
            }
             
        }
        return ans;
        
    }
};