class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(int x:nums){
            pq.push(x);
        }
        int cnt = 1;
        while(cnt<k){
            pq.pop();
            cnt++;
        }
        return pq.top();
    }
};