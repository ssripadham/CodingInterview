/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

public class LRUCache {

    private Dictionary<int, int> cache;
    private List<int> lruList;
    
    int _capacity;
    
    public LRUCache(int capacity) {
        _capacity = capacity;
        cache = new Dictionary<int,int>();
        lruList = new List<int>();
    }
    
    public int Get(int key) {
        if (cache.ContainsKey(key)){
            //Update key in list
            lruList.Remove(key);
            lruList.Insert(0,key);
            return cache[key];
        } else {
            return -1;
        }
        
    }
    
    public void Put(int key, int value) {
        
        if (cache.Count < _capacity){
            if (!cache.ContainsKey(key)){
                cache.Add(key,value);
                lruList.Insert(0,key);
            } else {
                cache[key] = value;
                //Update key in list
                lruList.Remove(key);
                lruList.Insert(0,key);
            }
        } else {
             if (!cache.ContainsKey(key)){
                int lruKey = lruList[lruList.Count - 1];
                lruList.RemoveAt(lruList.Count -1);
                cache.Remove(lruKey);
                cache.Add(key,value);
                lruList.Insert(0,key);
             } else {
                 cache[key] = value;
                 //Update key in list
                 lruList.Remove(key);
                 lruList.Insert(0,key);
             }
        }
        
    }

}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */

