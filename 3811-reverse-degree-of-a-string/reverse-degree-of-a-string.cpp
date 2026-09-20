class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0; i<s.size(); i++){
            int index = 'z' - s[i] + 1;
            int product = index*(i+1);
            sum += product;
        }
        return sum;
    }
};