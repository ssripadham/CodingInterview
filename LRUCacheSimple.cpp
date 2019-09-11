#include <iostream>

#include <unordered_map>
#include <utility>

using namespace std;


/*


HashMap<K, Ptr to Node>

int numAllocated;

head   <--> tail




class LRUCache<K, V> {
    public LRUCache(int numEntries);
 
      *  If key already exists, replace the current value with the new value.
      *  If the key doesn't exist, add the new key/value entry to the cache.
      *  If the addition of the new entry causes the number of entries to exceed numEntries, remove the oldest entry based on the last time the entry is accessed (either through put or get).

    public void put(K key, V value);
 
 
    // return the value associated with the key or null if the key doesn't exist.
    public V get(K key);
}

K, V , LRUCache*---->


*/

//Storing key is optional & takes up storage
template <class K, class V>
class LRUCacheEntry {
  
public:
  
  LRUCacheEntry(K _key, V _val) {
    key = _key;
    val = _val;
    prev = NULL;
    next = NULL;
  }
  
  LRUCacheEntry() {
    prev = NULL;
    next = NULL;
  }
    
  K key;
  V val;
  LRUCacheEntry<K,V>* prev;
  LRUCacheEntry<K,V>* next;
  
};



template <class K, class V>
class LRUCache {
  
  private: 
  
    int numAllocated;
    int capacity;
    LRUCacheEntry<K,V>* head;
    LRUCacheEntry<K,V>* tail;
  
    unordered_map<K, LRUCacheEntry<K,V> * > cache;
  
  public:
    
    LRUCache(int numEntries){
      
      capacity = numEntries;
      numAllocated = 0;
      
      //Sentinel
      //head <-> tail;
      
      head  = new LRUCacheEntry<K,V>();
      tail  = new LRUCacheEntry<K,V>();
      
      head->next = tail;
      tail->prev = head;
      
    }
  
    //attaches node to head
    void attach(LRUCacheEntry<K,V>* node){
      
      LRUCacheEntry<K,V>* tmp = head->next;
      
      head->next = node;
      node->prev = head;
      
      node->next = tmp;
      tmp->prev  = node;
      
    }
  
    //head <-> node <-> tail

    //manipulate prev->next and it's next prev
    void detach(LRUCacheEntry<K,V>* node){
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }
  
  
      /*  If key already exists, replace the current value with the new value.
      *  If the key doesn't exist, add the new key/value entry to the cache.
      *  If the addition of the new entry causes the number of entries to exceed numEntries, remove the oldest entry based on the last time the entry is accessed (either through put or get).
      */

   
    void put(K key, V value){
      
      //If in map, get cache Entry & then detach attach
      auto iter = cache.find(key);
      
      if (iter != cache.end()){
        
        LRUCacheEntry<K,V>* cacheEntry =  get(key);
        cacheEntry->val = value;
        
      } else {
        
        LRUCacheEntry<K,V>* newEntry = new LRUCacheEntry<K,V>(key, value);
        
        if (numAllocated < capacity) {
          //If not in map, if numAllocated <= capacity, then we attach to head
          attach(newEntry);
          
        } else {
          //If not, kick last entry out, append new entry to head
          cache.erase(tail->prev->key);
          detach(tail->prev);
          attach(newEntry);
                
        }
        cache.insert(make_pair(key,newEntry)); 
        numAllocated++;
        
      }
     
    }

    // return the value associated with the key or null if the key doesn't exist.
    //If K is in cache
    LRUCacheEntry<K,V> * get(K key){
      //If K is not in cache return null value V
      auto iter = cache.find(key);
      
      if (iter == cache.end()){
        cout<<"Not found in cache"<<endl;
        return NULL; 
      }
      
      LRUCacheEntry<K,V> * cacheEntry = (*iter).second;
    
      detach(cacheEntry);
      attach(cacheEntry);
      return cacheEntry;
      
    }
  
    void printCache() {
     
      LRUCacheEntry<K,V> * curr = head;
      
      if (curr) curr = curr->next;
      
      while(curr != tail) {
        
        cout<<curr->key<<" : "<<curr->val<<" -> ";
        curr = curr->next;
        
      }
    }
};




// To execute C++, please define "int main()"
int main() {
  
  LRUCache<int, int> MyCache(3);
  
  MyCache.put(1,100);
  MyCache.put(2,200);
  MyCache.put(3,300);
  MyCache.put(4,400);
  MyCache.put(5,500);
  MyCache.put(5,500);
  MyCache.printCache();
  
  LRUCacheEntry<int,int>* e = MyCache.get(2);
  if (e)  cout<<endl<<"val: "<<e->val<<endl;  
  return 1;
}

