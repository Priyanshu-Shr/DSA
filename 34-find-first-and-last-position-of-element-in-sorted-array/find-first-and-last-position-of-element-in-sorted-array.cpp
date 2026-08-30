class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        int n = nums.size();
        if(n == 0)
            return ans;
        
        int start = 0;
        int end = n - 1;
        
         int first = -1;   
        //for first occurence
        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                first = mid;
                end = mid - 1;
            }
            else if(nums[mid] > target){
                end = mid-1;
            }else{
                start = mid + 1;
            }
        }

        start = 0;
        end = n-1;
        int second = -1;
        //for second occurence
        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                second = mid;
                start = mid + 1;
            }
            else if(nums[mid] > target){
                end = mid-1;
            }else{
                start = mid + 1;
            }
        }

        ans[0] = first;
        ans[1] = second;

        return ans;
    }
};