// Hello
// "a-b, c, d-f"
// "1-2, 4-5", Node(1), Node(2) .. 
// isTree()
// isBipartite()
// isConnected()
// sumOfNodes() => 
// createString() => "abcde"

// http://collabedit.com/s5ggp

  Node(1)  ->  Node(2)  -> Node(3)
   

template <typename T>
class Node<T>{
    public:
        Node<T>(T data1) { data = data1; }
    private:
    T data;
    unordered_set<Node<T>*> neighbors;
};

template <typename T>
class Graph<T> {


    public:
        void insertEdge(T start, T end);
    
    private:
        bool isDirected;
        unordered_set< Node<T>* > nodes;
        
};

enum COLOR = { WHITE, BLACK} ;
class BiPartite: public Graph {


    unordered_map<Node<T>*, COLOR> myMap;
};

Node<T>* createNode(T data)  {
  auto iter = nodes.find(data);
  
  if (iter != nodes.end()) return *iter;
    
  Node<T> newtNode* = new Node<T>(data);
  nodes.push_back(newNode);
  return newNode;
}
        
template <typename T>
Graph<T>::insertEdge(T start, T end) {

   Node<T>* startNode = createNode(start);
   Node<T>* endNode = createNode(end);

   startNode->neighbors.push_back(endNode);
   
   if (isDirected) endNode->neighbors.push_back(startNode);
}
     
  
    
    
}