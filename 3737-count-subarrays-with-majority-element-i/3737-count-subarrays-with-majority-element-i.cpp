class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            unordered_map<int,int> mpp;

            for(int j=i;j<n;j++){
                mpp[nums[j]]++;

                if(mpp[target] > (j-i+1)/2)
                    cnt++;
            }
        }

        return cnt;
    }
};