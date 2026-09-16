class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int prevAns = 0;

        for(char ch:s){
            if(ch == ' '){
                if(ans != 0)
                    prevAns = ans;
                ans = 0;
                continue;
            }else{
                ans++;
            }
        }

        if(ans == 0){
            return prevAns;
        }else{
            return ans;
        }
    }
};