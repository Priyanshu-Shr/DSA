class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        if(n < 3){
            return -1;
        }

        unordered_map<int,vector<int>>mp;

        for(int i = 0; i<n; i++){
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for(auto i:mp){
            vector<int> temp = i.second;
            int m = temp.size();
            for(int j = 0; j+2<m; j++){
                int dis = 2*(temp[j+2] - temp[j]);
                ans = min(ans,dis);
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};