class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()>b.size()) return findMedianSortedArrays(b, a);
        int n1= a.size(), n2 = b.size(), c1, c2, l1, l2, r1, r2, l=0, h=n1;
        while(l<=h) {
            c1 = l + ((h-l)>>1);
            c2 = (n1+n2+1)/2 - c1;
            l1 = (c1==0)?INT_MIN:a[c1-1];
            l2 = (c2==0)?INT_MIN:b[c2-1];
            r1 = (c1==n1)?INT_MAX:a[c1];
            r2 = (c2==n2)?INT_MAX:b[c2];
            if(l1>r2) {
                h = c1-1;
            } else if(l2>r1) {
                l = c1+1;
            } else if(l1<=r2 && l2<=r1) {
                if((n1+n2)%2) {
                    return max(l1, l2);
                } else {
                    return (max(l1, l2) + min(r1, r2))/2.0;
                }
            }
        }
        return 0.0;
        
    }
};