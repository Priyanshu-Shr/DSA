class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for(int i = 0; i<n-1; i++){
            int sum = nums[i] + nums[i+1];
            if(st.find(sum) == st.end()){
                st.insert(sum);
            }else{
                return true;
            }
        }
        return false;
    }
};