class Solution {
public:
    int secondHighest(string s) {
        vector<int>nums;
        for(auto it:s){
            if(it>='0' && it<='9'){
                nums.push_back(it-'0');
            }
        }
        if(!nums.size())return -1;
        sort(nums.begin(),nums.end());
        int largest=-1;
        for(int it:nums){
            largest = max(it,largest);
        }
        int ans= -1;
        for( int it:nums){
            if(it<largest){
                ans = max( it , ans);
            }
        }
        return ans;

    }
};