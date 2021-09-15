class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int sign = 0, prev = 0, ans = 0;
        for(int i=0, j=0; j<arr.size(); j++) {
            if(j== arr.size()-1) {
                return max(ans, j-i+1);
            }
            if(arr[j]>arr[j+1]) sign =1;
            else if(arr[j]<arr[j+1]) sign = -1;
            else sign =0;
            
            if(sign ==0) {
                ans = max(ans, j-i+1);
                i = j+1;
            }
            if(sign != -prev) {
                ans = max(ans, j-i+1);
                i = j;
            } 
            prev = sign;
        }
        return ans;
    }
}; 