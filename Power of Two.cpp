/*
Given an integer, write a function to determine if it is a power of two.

Example 1:
Input: 1
Output: true 
Explanation: 2^0 = 1

Example 2:
Input: 16
Output: true
Explanation: 2^4 = 16

Example 3:
Input: 218
Output: false

*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0) return false;
        int countOnes = 0;
        for(int i = 0; i < 32; i++){
            if(n & 1 == 1){
                countOnes++;
            }
            n = n >> 1;
        }
        return countOnes == 1;
    }
};