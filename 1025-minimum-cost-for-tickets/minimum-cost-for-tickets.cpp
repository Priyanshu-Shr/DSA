class Solution {
public:
    //space optimization
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0;
        queue<pair<int,int>> month;
        queue<pair<int,int>> week;
        int n = days.size();
        //traverse in days array
        for(int i = 0; i<n; i++){
            //step 1-> remove expired days
            while(!month.empty() && month.front().first + 30 <= days[i])
                month.pop();

            while(!week.empty() && week.front().first + 7 <= days[i])
                week.pop();
            
            //step 2-> add days to the queue
            month.push({days[i],ans+costs[2]});
            week.push({days[i],ans+costs[1]});

            //step 3-> find min. ans
            ans = min(ans+costs[0],min(month.front().second,week.front().second));
        }
        return ans;
    }
};