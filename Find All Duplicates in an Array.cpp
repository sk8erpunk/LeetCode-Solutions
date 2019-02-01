/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements that appear twice in this array.
Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/
class Solution {
public:
    // solution using extra memory
	// vector<int> findDuplicates(vector<int>& nums) {
    //     unordered_map<int,int> freq;
    //     vector<int> dups;
    //     for(int i = 0; i < nums.size(); i++){
    //         if(++freq[nums[i]] > 1){
    //             dups.push_back(nums[i]);
    //         }
    //     }
    //     return dups;
    // }
	
	// solution without extra memory
    vector<int> findDuplicates(vector<int>& nums){
        vector<int> dups;
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] != nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1)
                dups.push_back(nums[i]);
        }
        return dups;
    }
};