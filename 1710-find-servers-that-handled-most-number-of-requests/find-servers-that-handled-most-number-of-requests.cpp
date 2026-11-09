class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
       //create a ordered set for available servers
       set<int> available;
       for(int i = 0; i<k; i++){
        available.insert(i);
       }  

        //create a freq. array for counting no. of request handled
        vector<int> freq(k,0);

        //create a min heap to know when will the server be free
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

       for(int i = 0; i<load.size(); i++){
            int arrivalTime = arrival[i];

            //check if at arrival time any servers can be free or not
            
            while(!pq.empty() && arrivalTime >= pq.top().first){
                int top = pq.top().second;
                pq.pop();
                available.insert(top); //inserting free servers back to the set
            }
           

            int target = i%k;
            if(available.empty())
                continue;

            auto it = available.lower_bound(target);

            if(it == available.end())
                it = available.begin(); //wrap around

            pq.push({arrivalTime+load[i],*it});
            freq[*it]++;
            available.erase(it);

       }
       vector<int> ans;
       int maxElement = *max_element(freq.begin(),freq.end());
       
       for(int i = 0; i<k; i++){
            if(freq[i] == maxElement)
                ans.push_back(i);
       }

       return ans;
    }
};