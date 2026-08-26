class Node{
    public:
    int data;
    int row;
    int col;

    Node(int data,int row,int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class Compare{
    public:
        bool operator()(Node*a,Node*b){
            return a->data > b->data;
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<Node*,vector<Node*>,Compare> pq;

        int k = nums.size();
        for(int i = 0; i<k; i++){
            maxi = max(maxi,nums[i][0]);
            pq.push(new Node(nums[i][0],i,0));
        }
        mini = pq.top()->data;
        int start = mini;
        int end = maxi;

        while(!pq.empty()){
            Node*temp = pq.top();
            pq.pop();
            mini = temp->data;

            if(maxi - mini < end - start){
                end = maxi;
                start = mini;
            }

            if(temp->col + 1 < nums[temp->row].size()){
                maxi = max(maxi,nums[temp->row][temp->col +1]);
                pq.push(new Node(nums[temp->row][temp->col +1],temp->row,temp->col +1));
            }else{
                break;
            }
        }

        vector<int> ans(2);
        ans[0] = start;
        ans[1] = end;
        return ans;
    }
};