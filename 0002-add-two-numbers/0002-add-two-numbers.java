/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
        ListNode head = null; 
        ListNode tail = null;
        int carry = 0;
        
        while(l1 != null || l2 != null)        
        {
            ListNode temp = new ListNode();
            
            int first = l1 != null ? l1.val : 0;
            int second = l2 != null ? l2.val : 0;
            
            int sum = first + second + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            temp.val = sum;
            temp.next = null;
            if(head == null)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail.next = temp;
                tail = temp;
            }
            l1 = l1 != null ? l1.next : null;
            l2 = l2 != null ? l2.next : null;
            
        }
        if(carry != 0)
        {
            ListNode temp = new ListNode();
            
            temp.val = carry;
            temp.next = null;
            tail.next = temp;
            tail = temp;
        }
        return head;
    }
}