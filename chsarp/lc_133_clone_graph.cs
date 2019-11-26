
/*

Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph.
Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

 
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> neighbors;

    public Node(){}
    public Node(int _val,IList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
}
*/
public class Solution {
    
    private void dfs(Node node, Dictionary<Node, Node> myMap){
        
        if (node == null) return;
        
        Node clonedNode = new Node(node.val, new List<Node>() );
        
        myMap[node] = clonedNode;
        
        foreach (var neighbor in node.neighbors){
            if (!myMap.ContainsKey(neighbor)){
                dfs(neighbor, myMap);
            }
            clonedNode.neighbors.Add(myMap[neighbor]);
        }
    }

    public Node CloneGraph(Node node) {
        
        Dictionary<Node,Node> myMap = new Dictionary<Node,Node>();
        
        dfs(node, myMap);
        
        return myMap[node];
        
    }
}