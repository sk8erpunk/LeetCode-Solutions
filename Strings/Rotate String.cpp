/*
We are given two strings, A and B.

A shift on A consists of taking string A and moving the leftmost character to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. Return True if and only if A can become B after some number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false
Note:

A and B will have length at most 100.
*/

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.empty() && B.empty()) return true;
        int lenA = A.size();
        int lenB = B.size();
        if(lenA != lenB || A.compare(B) == 0) return false;
        
        string BB = B + B;
        
        int i = 0, j = 0;
        while(i < lenA && j < lenB*2){
            if(A[i] != BB[j]){
                j++;
                continue;
            }
            while(A[i] == BB[j] && i < lenA && j < lenB*2){
                i++;
                j++;
            }
            if(i == lenA){
                return true;
            } else{
                i = 0;
            }
        }  
        return false;
        
    }
};