class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        unordered_map<char,int> mp;
        int i = 0,j = 0;
        int ans = INT_MIN;
        while(j<s.size()){
            char ch = s[j];

            if(mp.find(ch) == mp.end()){
                mp[ch] = j;
                j++;
            }else{
                i = max(i,mp[ch] + 1);
                mp[ch] = j++;
            }
            ans = max(ans,j-i);
        }
        return ans;
    }
};