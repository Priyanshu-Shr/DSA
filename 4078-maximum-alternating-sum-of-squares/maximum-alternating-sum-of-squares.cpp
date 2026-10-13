class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long n = nums.size();

        for(long long i = 0; i<n; i++){
                if(nums[i] <0)
                    nums[i] = -nums[i];
        }
        sort(nums.begin(),nums.end());
        long long ans = 0;

        for(long long i = 0; i<n/2; i++){
            ans = ans - nums[i]*nums[i];
        }

        for(int i = n/2; i<n; i++){
            ans += nums[i]*nums[i];
        }

        return ans;
    }
};