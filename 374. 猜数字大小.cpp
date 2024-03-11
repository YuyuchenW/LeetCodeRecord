/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);
class Solution {
public:
    int guessNumber(int n) {
        
        int res = n/2;
        while (guess(res)!= 0)
        {
            if (guess(res) == 1)
            {
                res = 1 + (res -1)/2;
            }
            else
            {
                res = n + (res - n)/2;
            }
        }
        
        return res;
    }
};