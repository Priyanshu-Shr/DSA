class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxSum = 0;
        int curr = 0;

        for(int i = 0; i<k; i++){
            curr += cardPoints[i];
        }

        maxSum = curr;
        int n = cardPoints.size();
        int j = k-1;
        for(int i = n-1; i>=n-k; i--){
            curr = curr - cardPoints[j] + cardPoints[i];
            j--;

            maxSum = max(curr,maxSum);
        }
        return maxSum;
    }
};