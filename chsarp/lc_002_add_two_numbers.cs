/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        
        ListNode output = null;
        int carry=0;
        int sum=0;
        ListNode prev = null;
        ListNode head = null;
        while (l1 != null && l2 != null){
            sum = (l1.val+l2.val+carry)%10;
            output = new ListNode(sum);
            
            if (prev != null) {
                prev.next = output;
            } else {
                head = output;
            }
            
            prev = output;
            carry = (l1.val+l2.val+carry)/10;
            
            l1 = l1.next;
            l2 = l2.next;
        }
        
        
        while (l1 != null){
            sum = (l1.val+carry)%10;
            output = new ListNode(sum);
            
            if (prev != null) {
                prev.next = output;
            } else {
                head = output;
            }
            
            prev = output;
            carry = (l1.val+carry)/10;
            
            l1 = l1.next;
        }

        while (l2 != null){
            sum = (l2.val+carry)%10;
            output = new ListNode(sum);
            if (prev != null) {
                prev.next = output;
            } else {
                head = output;
            }
            prev = output;
            carry = (l2.val+carry)/10;
            
            l2 = l2.next;
        }
        
        if (carry != 0){
            output = new ListNode(carry);
            if (prev != null) {
                prev.next = output;
            } else {
                head = output;
            }
        }
        return head;
    }
}