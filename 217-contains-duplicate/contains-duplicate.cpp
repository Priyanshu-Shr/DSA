class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mp;

        for(auto i:nums){
            if(mp.find(i) == mp.end()){
                mp[i] = 1;
            }else{
                return true;
            }
        }
        return false;
    }
};