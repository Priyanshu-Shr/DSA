class Solution {
public:
    int reverseDegree(string s) {
        map<char,int> mp;
        for(char ch:s){
            mp[ch] = 'z' - ch +1;
        }

    int sum = 0;
    for(int i = 0; i<s.size(); i++){
        int product = mp[s[i]]*(i+1);
        sum += product;
    }
    return sum;
    }
};