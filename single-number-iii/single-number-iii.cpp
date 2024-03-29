class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int xr=0;
        int n1=0,n2=0;
        for(auto& i:nums)xr^=i;
        int rt_set_bit=xr&~(xr-1);        
        for(auto& i:nums){
            if(i&rt_set_bit)n1^=i;
            else n2^=i;
        }
        return {n1,n2};
    }
};