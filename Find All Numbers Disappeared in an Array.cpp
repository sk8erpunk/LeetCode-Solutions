/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int* count = new int[n+1];
        vector<int> missing;
        
        for(int i = 0; i < n+1; i++){
            count[i] = 0;
        }
        for(int i = 0; i < n; i++){
            count[nums[i]]++;
        }
        for(int i = 1; i < n+1; i++){
            if(count[i] == 0){
                missing.push_back(i);
            }
        }
        return missing;
    }
};