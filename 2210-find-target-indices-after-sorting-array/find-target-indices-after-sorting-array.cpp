class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cntless = 0, cntgrt = 0;

        for(auto it:nums){
            if(it<target){
                cntless++;
            }else if(it > target){
                cntgrt++;
            }
        }

        vector<int> ans;
        int n = nums.size() - cntless - cntgrt;
        for(int i = 0; i<n; i++){
            ans.push_back(i+cntless);
        }
        return ans;
    }
};