/*
Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:

put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.

Example:

MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);          
hashMap.put(2, 2);         
hashMap.get(1);            // returns 1
hashMap.get(3);            // returns -1 (not found)
hashMap.put(2, 1);          // update the existing value
hashMap.get(2);            // returns 1 
hashMap.remove(2);          // remove the mapping for 2
hashMap.get(2);            // returns -1 (not found) 

Note:
All keys and values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashMap library.
*/

#define TABLE_SIZE 100
class MyHashMap {
    list<pair<int,int>> table[TABLE_SIZE];
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
    
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashCode = key % TABLE_SIZE;
        list<pair<int,int>>& lst = table[hashCode];
        for(auto& p : lst){
            if(p.first == key){
                p.second = value;
                return;
            }
        }
        lst.push_front(make_pair(key,value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashCode = key % TABLE_SIZE;
        list<pair<int,int>>& lst = table[hashCode];
        for(auto& p: lst){
            if(p.first == key)
                return p.second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashCode = key % TABLE_SIZE;
        list<pair<int,int>>& lst = table[hashCode];
        lst.remove_if([key](auto n) { return n.first == key; });
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */