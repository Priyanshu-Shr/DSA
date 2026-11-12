class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1;
        int dec = 1;
        int maxinc = INT_MIN;
        int maxdec = INT_MIN;

        //increasing
        for(int i = 0; i<n-1; i++){
            if(nums[i] < nums[i+1]){
                inc++;
                maxinc = max(maxinc,inc);
            }else{
                inc = 1;
            }
        }

        //decreasing
        for(int i = 0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                dec++;
                maxdec = max(maxdec,dec);
            }else{
                dec = 1;
            }
        }
        maxinc = max(maxinc,inc);
        maxdec = max(maxdec,dec);

        return max(maxinc,maxdec);
    }
};