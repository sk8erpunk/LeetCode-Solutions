/*
Count the number of prime numbers less than a non-negative number, n.

Example:
Input: 10
Output: 4

Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
class Solution {
public:
    
    int countPrimes(int n) {
        vector<int> ifPrime(n,1);   

        // turn off not primes
        for(int i = 2; i*i <= n ; i++){
            if(ifPrime[i] == 0)
                continue;
            for(int j = i*i; j < n; j+=i)
                ifPrime[j] = 0;
        }
        int count = 0;
        // count primes 
        for(int i = 2; i < n; i++){
            if(ifPrime[i])
                count++;
        }
        return count;
    }
};