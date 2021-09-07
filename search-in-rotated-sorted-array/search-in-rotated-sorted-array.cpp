class Solution {
public:
    int search(vector<int>& a, int k) {
        int l = 0, h = a.size()-1, mid;
        while(l<=h) {
            mid = (l+h)>>1;
            // cout<<mid<<endl;
            if(a[mid]==k) return mid;
            if(a[l]<=a[mid]) {
                if(a[l]<=k && k<=a[mid]) h=mid-1;
                else l = mid+1;
            } else {
                if(a[mid]<=k && k<=a[h]) l = mid+1;
                else {
                    h = mid-1;
                }
            }
            // cout<<l<<" "<<h<<endl;
        }
        return -1;
    }
};