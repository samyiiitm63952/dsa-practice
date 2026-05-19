class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums1.size();i++){
            freq[nums1[i]]=1;
        }
        for(int j=0;j<nums2.size();j++){
            if(freq[nums2[j]]==1){
                return nums2[j];
            }
            
            
        }
        return -1;
    }
};