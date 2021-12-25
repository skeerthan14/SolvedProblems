class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int min1=INT_MAX, diff;
        for(int i=0;i<arr.size()-1;i++) {
            diff = arr[i+1] - arr[i];
            if(min1 > diff){
                min1 = diff;
                ans.clear();
                ans.push_back({arr[i], arr[i+1]});
            } else if(min1==diff) {
                ans.push_back({arr[i],arr[i+1]});
                
            }
            
        }
        return ans;
    }
};