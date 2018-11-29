/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

int reverse(int x) {
    int digits_num = 0;
    int num = x;
    
    while(num!=0){
        num = num / 10;
        digits_num++;
    }
    
    num = x;
    long rev_num = 0;
    while(digits_num){
        int d = num%10;
        num = num/10;
        rev_num = rev_num+d*pow(10,digits_num-1);
        digits_num--;
    }
    if(rev_num > INT_MAX || rev_num < INT_MIN){
        return 0;
    }
    
    return rev_num;
    
}