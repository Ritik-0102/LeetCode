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
    int GCD(int a,int b){
        if(b == 0){
            return a;
        }

        return GCD(b,a % b);
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode temp = head;

        while(temp != null && temp.next != null){
            int gcd = GCD(temp.val,temp.next.val);
            ListNode nextNode = temp.next;

            temp.next = new ListNode(gcd);
            temp.next.next = nextNode;

            temp = nextNode;
        }

        return head;
    }
}