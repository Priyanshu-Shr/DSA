class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;

        string ans = {};

        for(char ch:s){
            if(ch == '(' && open>=1){
                open++;
                ans.push_back(ch);
            }
            else if(ch == ')' && open >=2){
                ans.push_back(ch);
                open--;
            }
            else if(ch == '(' && open == 0){
                open++;
            }
            else{
                open--;
            }
        }
        return ans;
    }
};