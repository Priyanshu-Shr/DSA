class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n == 1){
            return 1;
        }
        unordered_map<int,int> freq;

        int left = 0;
        int ans = 0;
        for(int right = 0; right<n; right++){
            freq[fruits[right]]++;
            while(freq.size() > 2){
                freq[fruits[left]]--;

                if(freq[fruits[left]] == 0){
                    freq.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};