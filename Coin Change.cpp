/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Note:
You may assume that you have an infinite number of each kind of coin.
*/

class Solution {
public:
    
    int coinChangeAux(vector<int>& coins, int amount, int* mem){
        if(amount < 0) 
            return INT_MAX;
        if(amount == 0)
            return 0;
        if(mem[amount])
            return mem[amount];
        
        int minCoins = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            int count = coinChangeAux(coins,amount-coins[i],mem);
            minCoins = min(minCoins, count);
        }
        mem[amount] = minCoins == INT_MAX ? INT_MAX : minCoins + 1;
        return mem[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int* mem = new int[amount + 1];
        for(int i = 0; i < amount + 1; i++)
            mem[i] = 0;
        int minCoins = coinChangeAux(coins, amount, mem);
        return minCoins != INT_MAX ? minCoins : -1;
    }
};