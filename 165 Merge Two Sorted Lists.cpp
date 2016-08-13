/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *head = NULL, *tail = NULL;
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL || (l2 != NULL && l1->val > l2->val)) {
                if (head == NULL) {
                    head = l2;
                } else {
                    tail->next = l2;
                }
                tail = l2;
                l2 = l2->next;
            } else {
                if (head == NULL) {
                    head = l1;
                } else {
                    tail->next = l1;
                }
                tail = l1;
                l1 = l1->next;
            }
        }
        return head;
    }
};
