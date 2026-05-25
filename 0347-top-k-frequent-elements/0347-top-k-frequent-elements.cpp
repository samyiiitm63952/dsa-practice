class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        vector<int>ans;
        
        while(k--){
        int freq=0;
        int element;
        for(auto it:mpp){
            if(it.second>freq){
                freq=it.second;
                element=it.first;
            }
        }
        ans.push_back(element);
        mpp.erase(element);
        }
        return ans;
    }
};