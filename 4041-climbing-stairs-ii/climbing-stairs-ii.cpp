class Solution {
public:
    int solve(int n, vector<int>& costs,vector<int> &dp){
        //base case
        if(n <=0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int o1 = costs[n-1] + 1 + solve(n-1,costs,dp);
        int o2 = costs[n-1] + 4 + solve(n-2,costs,dp);
        int o3 = costs[n-1] + 9 + solve(n-3,costs,dp);
        dp[n] = min(o1,min(o2,o3));
        return dp[n];
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        return solve(n,costs,dp);
    }
};