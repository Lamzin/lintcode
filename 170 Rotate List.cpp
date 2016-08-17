/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if (k == 0 || head == NULL) {
            return head;
        }

        ListNode *current = head, *last = head;
        int size = 0;

        while (current) {
            size++;
            last = current;
            current = current->next;
        }

        k %= size;
        if (k == 0) {
            return head;
        }

        current = head;
        for (int i = 0; i < size - 1 - k; i++) {
            current = current->next;
        }
        ListNode *start = current->next;
        current->next = NULL;
        last->next = head;

        return start;
    }
};
