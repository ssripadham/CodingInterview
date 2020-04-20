/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    
    class NodeIndex{
        
        public int index;
        public ListNode node;
        public NodeIndex(ListNode _node, int _index){
            node = _node;
            index = _index;
        }
    };
    
    public ListNode MergeKLists(ListNode[] lists) {
        SortedSet<NodeIndex> pq = new SortedSet<NodeIndex>(Comparer<NodeIndex>.Create( (a,b) => (a.node.val == b.node.val) ? a.index-b.index : (a.node.val - b.node.val)));
        
        for(int i = 0; i < lists.Length ; ++i){
            
            if (lists[i] != null)
                pq.Add(new NodeIndex(lists[i],i));
        }
        
        ListNode head = new ListNode(Int32.MinValue);
        ListNode current = head;
        while (pq.Count > 0){
            
            NodeIndex minNodeIndex = pq.Min;
            ListNode minElem = minNodeIndex.node;
            int idx = minNodeIndex.index;
            pq.Remove(minNodeIndex);
            current.next = minElem;
            
            if (minElem.next != null){
                //Console.WriteLine(minElem.next.val);
                pq.Add(new NodeIndex(minElem.next,idx));
            }
            
            
            current = current.next;
        }
        return head.next;
    }
}