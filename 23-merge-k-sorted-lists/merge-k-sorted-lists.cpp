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

class Compare{
    public:
        bool operator()(ListNode*a,ListNode*b){
            return a->val > b->val;
        }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
        int k = lists.size();
        if(k == 0)
            return NULL;
        for(int i = 0; i<k; i++){
            if(lists[i] != NULL)
                pq.push(lists[i]);
        }

        
        ListNode*head = NULL;
        ListNode*tail = NULL;
        while(!pq.empty()){
            if(head == NULL){
                ListNode*temp = pq.top();
                pq.pop();
                head = temp;
                tail = temp;
                if(head->next != NULL){
                    pq.push(head->next);
                }
            }else{
                ListNode*temp = pq.top();
                pq.pop();
                tail->next = temp;
                tail = temp;
                if(tail->next != NULL){
                    pq.push(tail->next);
                }
            }
        }
        return head;

    }
};