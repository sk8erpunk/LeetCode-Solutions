/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

char* copysub(char* s, int i, int j){
    char* res = (char*)malloc(sizeof(char)*(j-i+2));
    int k = i;
    char* str = res;
    while(k<=j){
        *str=s[k];
        str++;
        k++;
    }
    *str = '\0';
    return res;
}


bool checkpalindrom(char* start, char* end){
    while(start <= end && *start == *end){
        start++;
        end--;
    }
    return (*start == *end);
}

char* longestPalindrome(char* s) {
    
    int len = strlen(s);
    int i=0,j;
    int besti=0,bestj=0;
    int max = 1;
    
    while(i < len){
        for(j = len-1; j > i && (j-i+1) > max; j--){
            if(s[i] == s[j]){
                if(checkpalindrom(&s[i],&s[j])){
                    int currLen = j-i+1;
                    if(currLen > max){
                        max = currLen;
                        besti = i;
                        bestj = j;
                        break;
                    }
                }
            }
        }
        i++;
    }
    return copysub(s,besti,bestj);
}
