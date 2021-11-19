class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v(n);
        iota(v.begin(), v.end(), 1);
        long fact = 1;
        for(int i=2;i<n;i++) {
            fact *= i;
        }
        k -=1;
        string ans = "";
        while(1) {
            ans += to_string(v[k/fact]);
            v.erase(v.begin() + (k/fact));
            if(v.size()==0) {
                break;
            }
            k %= fact;
            fact /= v.size();
        }
        return ans;
    }
};