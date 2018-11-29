/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?

*/

bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
    
    int num = x;
    long rev = 0;
    while(num){
        int d = num % 10;
        num = num / 10;
        rev = rev * 10 + d;
    }
    
    if(rev > INT_MAX || rev < INT_MIN){
        return false;
    }
    
    return (int)rev == x;
    
}