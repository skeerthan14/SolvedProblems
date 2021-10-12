/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, h=n, m;
        while(l<=h) {
            m = l+(h-l)/2;
            int k = guess(m);
            if(k==0) return m;
            else if(k==1) l=m+1;
            else if(k==-1) h = m-1;
        }
        return n;
    }
};