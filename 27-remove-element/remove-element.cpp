class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] == val){
                int j = i+1;
                while( j<n && nums[j] == val){
                    j++;
                }
                if(j <n){
                    swap(nums[i],nums[j]);
                }  
            }
        }

        int cnt = 0;
        for(auto x:nums){
            if(x != val)
                cnt++;
        }

        return cnt;     
    }
};