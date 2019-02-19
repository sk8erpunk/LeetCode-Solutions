/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:
Input: 2.00000, 10
Output: 1024.00000

Example 2:
Input: 2.10000, 3
Output: 9.26100

Example 3:
Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Note:
-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
*/
class Solution {
public:
    double myPow(double x, int n) {
        long N = n;
        if (N < 0) {
            N = -N; 
            x = 1 / x;
        }
        double res = 1;
        double curr = x;
        for(long i = N; i > 0; i /= 2){
            if(i % 2 == 1)  // bit 1
                res *= curr;
            curr = curr * curr;
        }
        return res;
    }
};