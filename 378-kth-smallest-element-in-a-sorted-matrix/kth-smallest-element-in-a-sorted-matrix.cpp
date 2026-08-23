class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> vec;
        for(auto i:matrix){
            for(auto j:i){
                vec.push_back(j);
            }
        }
        sort(vec.begin(),vec.end());
        return vec[k-1];
    }
};