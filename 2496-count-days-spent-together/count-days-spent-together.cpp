class Solution {
public:

    int convert(string s,int arr[]){
        int month = stoi(s.substr(0,2));
        int day = stoi(s.substr(3,2));

        int total = 0;
        for(int i = 0; i<month-1; i++){
            total += arr[i];
        }
        total += day;
        return total;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

        //converting dates into total days(1-365)
        int a1 = convert(arriveAlice,arr);
        int a2 = convert(leaveAlice,arr);
        int b1 = convert(arriveBob,arr);
        int b2 = convert(leaveBob,arr);

        //starting of overlap
        int start = max(a1,b1);
        int end = min(a2,b2);

        if(start>end)
            return 0;
        
        return end-start+1;
    }
};