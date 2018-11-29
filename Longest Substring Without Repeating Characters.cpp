/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

void zeroArray(int* arr,char* end, char* str){
    
    while(str != end){
        arr[(int)(*str)] = 0;
        str++;
    }
}

int lengthOfLongestSubstring(char* s) {
    if(s == NULL){
        return 0;
    }
    int arr[256] = {0};
    
    int maxLen = 0;
    int currLen = 0;
    
    char* itr = s;
    char* beginSub = s;
    
    while(*itr != NULL){
        if(arr[(int)(*itr)] == 0){
            arr[(int)(*itr)]++;
            currLen++;
            itr++;
        } else {
            zeroArray(&arr,itr,beginSub);
            if(currLen > maxLen){
                maxLen = currLen;
            }
            currLen = 0;
            beginSub++;
            itr = beginSub;
        }
    }
    if(currLen > maxLen){
        maxLen = currLen;
    }
    return maxLen;
}