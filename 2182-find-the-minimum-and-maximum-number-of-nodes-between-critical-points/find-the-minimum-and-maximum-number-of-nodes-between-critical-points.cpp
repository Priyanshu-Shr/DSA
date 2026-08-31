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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> distance;
        ListNode*temp = head->next;
        ListNode*prev = head;
        if(temp->next == NULL){
            return {-1,-1};
        }
        int count = 2;

        while(temp != NULL){
            if(temp->next){
                if(temp->val > temp->next->val && temp->val > prev->val){
                    distance.push_back(count);
                }
                else if(temp->val < temp->next->val && temp->val < prev->val){
                    distance.push_back(count);
                }
                prev = temp;
                temp = temp->next;
                count++;
            }else{
                break;
            }
        }

        int n = distance.size();
        int mini = INT_MAX;
        int maxi;
        if(n>=2){
            for(int i = 1; i<distance.size(); i++){
                mini = min(mini,distance[i]-distance[i-1]);
            }
            maxi = distance[n-1] - distance[0];
        }
        else{
            mini = -1;
            maxi = -1;
        }

        return {mini,maxi};
    }
};