class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        
        int maxIndex = 0;
        int minIndex = 0;

        for(int i = 1; i<nums.size(); i++){
            if(nums[i] > nums[maxIndex])
                maxIndex = i;
            
            if(nums[i] < nums[minIndex])
                minIndex = i;
        }

       //case 1: remove from front
       int m1 =  max(maxIndex , minIndex) + 1;

       //case 2: remove from back
       int n = nums.size();
       int m2 =  n - min(maxIndex,minIndex);

       //case 3: remove from front as well as back
        int front = min(maxIndex,minIndex) + 1;
        int back = n - max(maxIndex,minIndex);
        int m3 = front + back;

        return min(m1,min(m2,m3));
    }
};