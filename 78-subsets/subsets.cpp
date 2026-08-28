class Solution {
public:
    void solve(vector<vector<int>> & ans,vector<int>& nums,vector<int> & temp,int i,int end){
        if(i >= end)
        {
            ans.push_back(temp);
            return;
        }
        
        solve(ans,nums,temp,i+1,end);
        temp.push_back(nums[i]);
        solve(ans,nums,temp,i+1,end);
        if(!temp.empty())
            temp.pop_back();

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i = 0;
        int end = nums.size();
        solve(ans,nums,temp,i,end);
        return ans;
    }
};