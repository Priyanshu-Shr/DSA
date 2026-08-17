/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode*front = head->next;
        ListNode*back = head;

            back->next = front->next;
            front->next = back;
            head = front;

            ListNode*prev = back;
            back = back->next;
            
            

        while(back != NULL && back->next != NULL){
            front = back->next;

            back->next = front->next;
            front->next = back;
            prev->next = front;
            prev = back;
            back = back->next;
        }
        return head;
    }
};