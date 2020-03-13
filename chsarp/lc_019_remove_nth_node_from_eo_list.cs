/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
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
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        
        if (head == null) return head;
        ListNode first = head;
        ListNode second = head;
        for (int i = 1; i <= n ; ++i) {
            if (second.next == null) {
                head = first.next;
                return head;
            }
            second = second.next;  
        }
        
        
        while (second.next != null){
            first = first.next;
            second= second.next;
        }
        
        first.next = first.next.next;
        return head;
    }
}