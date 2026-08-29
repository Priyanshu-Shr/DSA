class Solution {
public:
    bool isIsomorphic(string s, string t) {
      map<char,char> mp;
      map<char,char> mp2;
    
      int n = s.size();
      for(int i = 0; i<n; i++){

        if(mp.find(s[i]) == mp.end()){
            mp[s[i]] = t[i];
        }else{
            if(mp[s[i]] != t[i])
                return false;
        }

        if(mp2.find(t[i]) == mp2.end()){
            mp2[t[i]] = s[i];
        }else{
            if(mp2[t[i]] != s[i])
                return false;
        }
      }
      return true;
    }
};