class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;

        //case 1 -> low and high both are odd
        if( (low&1) && (high&1) ){
            ans = (high-low)/2 + 1;
        }//case 2-> both even
        else if( (low&1)==0 && (high&1)==0  ){
            ans = (high-low)/2;
        }else{
            ans = (high-low)/2 + 1;
        }
        return ans;
    }
};