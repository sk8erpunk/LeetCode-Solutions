/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

struct node{
    char val;
    struct node* next;
};

typedef struct node Node; 


char* convert(char* s, int numRows) {
    if(s == NULL){
        return NULL;
    }
    
    // calculate s size
    int len = strlen(s);
    char* res = (char*)malloc(sizeof(char)*len+1);
    res[len] = '\0';
    if(numRows == 1){
        strcpy(res,s);
        return res;
    }

    // define array of linked lists
    Node** arr = (Node*)malloc(sizeof(Node*)*numRows);
    int i = 0;
    for(i = 0; i < numRows; i++){
        arr[i] = NULL;
    }
    
    // fill lists respectively
    int row = 0,revmode = 0;
    i=0;
    while(i < len){
        
        // new node
        Node* node = (Node*)malloc(sizeof(Node));
        node->val = s[i];
        node->next = NULL;
 
        if(row == numRows-1){
            revmode = 1;
        }
        if(row == 0){
            revmode = 0;
        }     
        
        if(arr[row] == NULL){
            // first node in list
            arr[row] = node;
        } else {
            // connect node to the last one
            Node* iterator = arr[row]; 
            while(iterator->next != NULL){
                iterator = iterator->next;
            }
            iterator->next = node;
        }
                        
        if(revmode == 0){
            row++;    
        } 
        if(revmode){
            row--;
        }
        i++;
    }
    
    // copy from lists to new string
    int k=0;
    Node* iterator;
    for(i = 0; i < numRows; i++){
        for(iterator = arr[i] ; iterator != NULL; iterator = iterator->next){
            res[k] = iterator->val;
            k++;
        }
    }
    return res;
}

