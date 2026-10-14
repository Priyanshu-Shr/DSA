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
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        ListNode*temp = head;

        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }

        ListNode*newHead = new ListNode(st.top());
        st.pop();
        temp = newHead;
        while(!st.empty()){
            if(st.top() >= temp->val){
                ListNode*newNode = new ListNode(st.top());
                newNode->next = temp;
                temp = newNode;
            }
            st.pop();
        }
        return temp;
    }
};