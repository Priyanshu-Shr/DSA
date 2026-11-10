class Solution {
public:
    //Tabulation Approach(bottom up DP)
    int solve(int n,vector<int> & costs){
        vector<int> dp(n+1,0);
        dp[0] = 0; //base case

        for(int i = 1; i<=n; i++){
            int o1 = costs[i-1] + 1 + dp[i-1];

            int o2 = INT_MAX;
            if(i-2>=0)
                 o2 = costs[i-1] + 4 + dp[i-2];
            
            int o3 = INT_MAX;
            if(i-3>=0)
                 o3 = costs[i-1] + 9 + dp[i-3];
            
            dp[i] = min(o1,min(o2,o3));
        }
        return dp[n];
    }
    int climbStairs(int n, vector<int>& costs) {
        return solve(n,costs);
    }
};