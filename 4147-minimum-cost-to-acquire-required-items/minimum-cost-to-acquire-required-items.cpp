class Solution {
public:
    //video solution -> https://www.youtube.com/watch?v=WK_kd0RDd8k
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        //if c1 + c2 <= cb then we will directly take c1 & c2.. no need to take cb
        if(1LL*cost1 + cost2 <= costBoth){
            long long r1 = 1LL*cost1*need1;
            long long r2 = 1LL*cost2*need2;
            long long result = r1 + r2 ;
            return result;
        }else{
            long long both = min(need1,need2);
            long long ans = 1LL*both*costBoth;
            long long n1 = need1-both;
            long long n2 = need2 - both;

            ans = ans + 1LL*n1*min(cost1,costBoth) + 1LL*n2*min(cost2,costBoth);
            return ans;
        }
        return 0;
    }
};