class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;

        for(auto i:nums){
            mp[i]++;
        }

        int sum1 = 0;
        int sum2 = 0;
        int maxFreq = INT_MIN;

        for(auto i:mp){
            if(i.second > 1){
                if(i.second > maxFreq){
                    maxFreq = i.second;
                    sum2 = i.second;
                }
                else if(i.second == maxFreq)
                    sum2 += i.second;    
            }else{
                sum1 += i.second;
            }
        }

        if(sum2 != 0)
            return sum2;
        else
            return sum1;

    }
};