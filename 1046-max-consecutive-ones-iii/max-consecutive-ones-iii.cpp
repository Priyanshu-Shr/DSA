class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        int zeros = 0;
        while(j<nums.size()){
            if(nums[j] == 0){
                zeros++;
            }

            while(zeros > k){
                if(nums[i] == 0){
                    zeros--;
                }
                i++;
            }

            j++;
            ans = max(ans,j-i);
             
                
        }
        return ans;
    }
};