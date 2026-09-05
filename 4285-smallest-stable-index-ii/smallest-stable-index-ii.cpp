class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> maxi;
        vector<int> mini(nums.size());

        int maximum = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            maximum = max(maximum,nums[i]);
            maxi.push_back(maximum); 
        }

        int minimum = INT_MAX;
        for(int i = nums.size()-1; i>=0; i--){
            minimum = min(minimum,nums[i]);
            mini[i] = minimum;
        }
        
        for(int i = 0; i<nums.size(); i++){
            if(maxi[i] - mini[i] <=k)
                return i;
        }
        return -1;
    }
};