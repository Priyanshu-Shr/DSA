class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        int count = 0;

        for(int x:digits){
            freq[x]++;
        }

        for(int i = 1; i<=9; i++){
            if(freq[i] == 0)
                continue;
            freq[i]--;
            for(int j = 0; j<=9; j++){
                if(freq[j] == 0)
                    continue;
                freq[j]--;
                for(int k = 0; k<=9; k++){
                    if(freq[k] == 0)
                        continue;
                    int digit = 100*i + 10*j + k;
                    if(digit %2 == 0)
                        count++; 
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return count;
    }
};