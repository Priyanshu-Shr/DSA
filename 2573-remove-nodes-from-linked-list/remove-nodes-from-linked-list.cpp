
class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        if (head == NULL) return NULL;

        head = reverseLL(head);

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != NULL) {
            if (curr->val >= prev->val) {
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }

        prev->next = NULL;

        return reverseLL(head);
    }
};
