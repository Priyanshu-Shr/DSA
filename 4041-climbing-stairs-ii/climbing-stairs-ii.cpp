class Solution {
public:
    //Space Optimization 
    int solve(int n,vector<int> & costs){
        
        int prev1 = 0;
        int prev2 = 0;
        int prev3 = 0;

        for(int i = 1; i<=n; i++){
            int o1 = costs[i-1] + 1 + prev1;

            int o2 = INT_MAX;
            if(i-2>=0)
                 o2 = costs[i-1] + 4 + prev2;
            
            int o3 = INT_MAX;
            if(i-3>=0)
                 o3 = costs[i-1] + 9 + prev3;
            
            int curr = min(o1,min(o2,o3));
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int climbStairs(int n, vector<int>& costs) {
        return solve(n,costs);
    }
};