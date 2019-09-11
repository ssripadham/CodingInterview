template  <class K, class T>
class LRUCacheEntry {
	K key;
	T data;
	LRUCacheEntry* prev;
	LRUCacheEntry* next;
};

typedef hash_map unordered_map;

template <class K, class T>
class LRUCache {

	//Map of Key to LRUCacheEntry* of one node
	hash_map<K,LRUCacheEntry<K,T>*> _mapping;

	//PreAllocated CacheEntries - keeps track of MRU's
	vector< LRUCacheEntry<K,T>* > _freeEntries; 

	//Doubly Linked List
	LRUCacheEntry<K,T>* head;
	LRUCacheEntry<K,T>* tail;
	LRUCacheEntry<K,T>* entries;

	public:

	LRUCache(int capacity) {

		entries = new LRUCacheEntry<K,T>[capacity];
		for (unsigned int i = 0; i < capacity; ++i ) {
			_freeEntries.push_back(entries+i);
		}

		head = tail = new LRUCacheEntry;
		head->next = tail;
		tail->prev = head;

		head->prev = NULL;
		tail->prev = NULL;

	}

	~LRUCache() {
		delete entries[];
		delete head;
		delete tail;
		_freeEntries.clear();
	}

	void put(K key, T data){

		//First hash the key and get location in cache
		LRUCacheEntry<K,T>* node = _mapping[key]
		if (node) {
			//detach, update data anyway, attach
			_detach(node);
			node->data = data();
			_attach(node);
		} else{
			if (_freeEntries.empty()){
				//LRU algorithm
				//No free entries - detach from the tail of list
				node = tail->prev;
				_detach(node);
				_mapping.erase(node->key); //That key goes out of cache
				_mapping[key] = node; //New key gets in
				node->data = data;
				_attach(node); //Node goes to beginning
			} else{
				
				//GET THE NODE FROM THE BACK OF FREE LIST AND USE IT UP

				//Get the entry from back of the free list
				node = _freeEntries.back();

				//Remove the node from the free list
				_freeEntries.pop_back();

				node[key] = data;
				mapping[key] = node;

				attach(node);
			}

		}

	}

	T void get(K key) {
		LRUCacheEntry* node = mapping[key];

		if (!node) {
			return NULL;
		}
		
		detach(node);
		attach(node);
		return node->data;
	}

	//
	// Purely doubly linked list functionality
	//
	void detach(LRUCacheEntry<K,T>* node)
	{
		//Remove a given node
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	void attach(LRUCacheEntry<K,T>* node)
	{
		//Add node to the head of the doubly linked list
		node->next = head->next;
		node->prev = head;
		head->next = node;
		node->next->prev = node;
	}
};
