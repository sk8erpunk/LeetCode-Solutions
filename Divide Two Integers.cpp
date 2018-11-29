/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.

*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == INT_MIN && dividend != INT_MIN){
            return 0;
        }
        
        if(dividend != INT_MIN && abs(dividend) < abs(divisor)){
            return 0;
        }
        int sign = 1;
        if(dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0){
            sign = -1;
        }
        
        if(dividend == INT_MIN && abs(divisor) == 1){
            return divisor < 0 ? INT_MAX: INT_MIN;
        }

        int d1,d2, c = 0;
        d1 = (dividend > 0 || dividend == INT_MIN) ? dividend : (-1)*dividend;
        d2 = ((divisor < 0 && dividend == INT_MIN) || (divisor > 0 && dividend != INT_MIN)) ? divisor : (-1)*divisor;
        if(d1 < 0){
            while(d1 <= d2){
                d1-=d2;
                c++;
            }
        } else {
            while(d1 >= d2){
                d1-=d2;
                c++;
            }
        }
        
      
        return sign*c;
    }
};