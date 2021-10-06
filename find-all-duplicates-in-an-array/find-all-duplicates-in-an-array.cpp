class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int>s;
        vector<int> ans;
        for(int &i: nums) {
            if(s.count(i)) {
                ans.push_back(i);
            } else {
                s.insert(i);
            }
        }
        return ans;
    }
};