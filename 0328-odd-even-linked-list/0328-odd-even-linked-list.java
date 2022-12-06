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
    public ListNode oddEvenList(ListNode head) {
        if(head == null)
            return head;
        ListNode head1 = head;
        ListNode head2 = null;
        if(head1.next != null)
            head2 = head1.next;



        if(head2 == null)
            return head1;


        ListNode ptr1 = head1;
        ListNode ptr2 = head2;
        ListNode prev = null;
        int count = 0;

        while(ptr1 != null && ptr2 != null)
        {
            ListNode temp = ptr2.next;
            ptr1.next = temp;
            prev = ptr1;
            ptr1  = ptr2;
            ptr2 = temp;
            count++;
        }



        if(count % 2 == 0)
            ptr1.next = head2;
        else
            prev.next = head2;
        return head1;

        
        
    }
}