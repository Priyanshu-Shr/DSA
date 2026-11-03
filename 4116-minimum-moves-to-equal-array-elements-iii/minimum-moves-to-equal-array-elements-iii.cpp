class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int max = 0;
        int n = nums.size();
        for(int i = 1; i<n; i++){
            if(nums[i] > nums[max])
                max = i;
        }

        for(int i = 0; i<n; i++){
            sum += nums[max] - nums[i];
        }
        return sum;
    }
};