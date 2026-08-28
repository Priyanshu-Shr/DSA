class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        int m = k;
        while(j<nums.size()){
            if(nums[j] == 0){
                if(m != 0){
                    j++;
                    m--;
                }else{
                    i++;
                    j = i;
                    m = k;
                }
            }else{
                j++;
            }
            ans = max(ans,j-i);
        }
        return ans;
    }
};